package com.packcheng.ndkdemo.jni;

/**
 * native线程之生产者与消费者练习
 *
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/4/20 3:21 PM
 */
public class ProductConsumer {
    public native void start();

    public native void stop();
}
