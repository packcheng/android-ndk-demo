//
// Created by packcheng on 2021/8/12.
//

#include <unistd.h>
#include "my-fmode.h"

using namespace FMOD;
using namespace std;

extern "C"
JNIEXPORT void JNICALL Java_com_packcheng_fmode_FModePlayer_play
        (JNIEnv *env, jobject thiz, jstring file_path, jint mode) {

    char *result = "默认播放完毕";
    const char *sound_path = env->GetStringUTFChars(file_path, 0);

    System *system = NULL;
    Channel *channel = NULL;
    Sound *sound = NULL;
    DSP *dsp = NULL;

    // 第一步：创建系统
    System_Create(&system);
    // 第二步: 初始化系统
    system->init(32, FMOD_INIT_NORMAL, 0);
    // 第三步: 创建声音
    system->createSound(sound_path, FMOD_DEFAULT, NULL, &sound);
    // 第四步: 播放声音
    system->playSound(sound, NULL, false, &channel);

    jclass player_class = env->GetObjectClass(thiz);
    jmethodID method_on_start_play = env->GetMethodID(player_class, "onStartPlay", "()V");
    env->DeleteLocalRef(player_class);
    env->CallVoidMethod(thiz, method_on_start_play);

    LOG_W("开始播放了哟: %s", sound_path)

    switch (mode) {
        case FModePlayer_MODE_LUOLI:
            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
            dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 1.8F);
            channel->addDSP(0, dsp);
            result = "萝莉播放完毕";
            break;
        case FModePlayer_MODE_DASHU:
            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
            dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 0.7F);
            channel->addDSP(0, dsp);
            result = "大叔播放完毕";
            break;
        case FModePlayer_MODE_KONGLING:
            system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
            dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 200);
            dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 10);
            channel->addDSP(0, dsp);
            result = "空灵播放完毕";
            break;
        case FModePlayer_MODE_GAOGUI:
            float frequency;
            channel->getFrequency(&frequency);
            channel->setFrequency(frequency * 2.0F);
            result = "搞怪播放完毕";
            break;
        case FModePlayer_MODE_JINGXIONG:
            channel->getFrequency(&frequency);
            channel->setFrequency(frequency * 1.3F);

            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
            dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 1.4F);
            channel->addDSP(0, dsp);

            system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
            dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 200);
            dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 9);
            channel->addDSP(1, dsp);

            system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
            dsp->setParameterFloat(FMOD_DSP_TREMOLO_FREQUENCY, 20);
            dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW, 0.8F);
            channel->addDSP(1, dsp);
            result = "惊悚完毕";
            break;
        case FModePlayer_MODE_NORMAL:
        default:
            result = "正常播放完毕";
            break;
    }

    bool isPlaying = true;
    while (isPlaying) {
        channel->isPlaying(&isPlaying);
        usleep(1000 * 1000);
    }

    LOG_W("播放完毕: %s", result)

    sound->release();
    channel->stop();
    system->close();
    system->release();
    env->ReleaseStringUTFChars(file_path, sound_path);

    jstring str = env->NewStringUTF(result);
    player_class = env->GetObjectClass(thiz);
    jmethodID method_on_play = env->GetMethodID(player_class, "onPlayEnd", "(Ljava/lang/String;)V");
    env->DeleteLocalRef(player_class);
    env->CallVoidMethod(thiz, method_on_play, str);
}