package com.packcheng.fmode;

import android.widget.Toast;

import androidx.annotation.IntDef;
import androidx.annotation.NonNull;

import org.fmod.FMOD;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/8/14 21:49
 */
class FModePlayer {

    public static final int MODE_NORMAL = 0;
    public static final int MODE_LUOLI = 1;
    public static final int MODE_DASHU = 2;
    public static final int MODE_KONGLING = 3;
    public static final int MODE_GAOGUI = 4;
    public static final int MODE_JINGXIONG = 5;

    @Retention(RetentionPolicy.SOURCE)
    @IntDef({MODE_NORMAL, MODE_LUOLI, MODE_DASHU, MODE_KONGLING, MODE_GAOGUI, MODE_JINGXIONG})
    public @interface PlayMode {
    }


    private final FmodeActivity activity;
    private volatile boolean isPlaying;

    public FModePlayer(@NonNull FmodeActivity activity) {
        this.activity = activity;
        FMOD.init(activity.getApplicationContext());
    }

    public void startPlay(String filePath, @PlayMode int mode) {
        if (isPlaying) {
            activity.runOnUiThread(() -> Toast.makeText(activity, "请等待播放完毕", Toast.LENGTH_SHORT).show());
            return;
        }
        play(filePath, mode);
    }

    private native void play(String filePath, @PlayMode int mode);

    private void onStartPlay() {
        isPlaying = true;
    }

    private void onPlayEnd(String result) {
        isPlaying = false;
        activity.runOnUiThread(() -> Toast.makeText(activity, result, Toast.LENGTH_SHORT).show());
    }

    public boolean isPlaying() {
        return isPlaying;
    }

    public void destroy() {
        if (FMOD.checkInit()) {
            FMOD.close();
        }
    }
}
