#include <jni.h>
#include "my-jni.h"
#include <queue>
#include <pthread.h>
#include <unistd.h>

//
// 线程练习之生产者与消费者
// Created by packcheng on 2021/4/20.
//

std::queue<int> product_queue;
pthread_t pthread_product;
pthread_t pthread_consumer;
pthread_mutex_t mutex_product;
pthread_cond_t cond_product;
int8_t stop = -1;

void destroy() {
    LOG_W("destroy")
    pthread_mutex_destroy(&mutex_product);
    pthread_cond_destroy(&cond_product);
}

void *productAction(void *arg) {
    char *param = (char *) arg;
    LOG_D("productAction, param: %s", param)

    while (product_queue.size() < 50 && stop < 0) {
        LOG_I("生产一个产品")
        pthread_mutex_lock(&mutex_product);
        product_queue.push(product_queue.size());
        if (!product_queue.empty()) {
            pthread_cond_signal(&cond_product);
        }
        pthread_mutex_unlock(&mutex_product);
        sleep(1);
    }

    pthread_exit(&pthread_product);
}

void *consumerAction(void *arg) {
    LOG_D("customerAction")
    while (stop < 0 || !product_queue.empty()) {
        pthread_mutex_lock(&mutex_product);
        if (!product_queue.empty()) {
            LOG_I("消费一个产品");
            product_queue.pop();
        } else {
            LOG_W("全部消费完毕，等待生产")
            pthread_cond_wait(&cond_product, &mutex_product);
        }
        pthread_mutex_unlock(&mutex_product);
        usleep(500 * 1000);
    }

    destroy();
    pthread_exit(&pthread_consumer);
}

/**
 * 初始化
 */
void initMutex() {
    pthread_mutex_init(&mutex_product, NULL);
    pthread_cond_init(&cond_product, NULL);
    pthread_create(&pthread_product, NULL, productAction, (void *) "product");
    pthread_create(&pthread_consumer, NULL, consumerAction, NULL);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ProductConsumer_start(JNIEnv *env, jobject thiz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ProductConsumer_start")
    for (int i = 0; i < 10; i++) {
        product_queue.push(i);
    }

    stop = -1;
    initMutex();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_packcheng_ndkdemo_jni_ProductConsumer_stop(JNIEnv *env, jobject thiz) {
    LOG_D("Java_com_packcheng_ndkdemo_jni_ProductConsumer_stop")
    stop = 1;
}


