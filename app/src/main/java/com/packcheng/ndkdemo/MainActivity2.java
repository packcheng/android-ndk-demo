package com.packcheng.ndkdemo;

import com.packcheng.ndkdemo.databinding.ActivityMain2Binding;
import com.packcheng.ndkdemo.jni.ClassOperate;
import com.packcheng.ndkdemo.jni.DynamicLink;
import com.packcheng.ndkdemo.jni.JniRoot;
import com.packcheng.ndkdemo.jni.NativeThread;
import com.packcheng.ndkdemo.jni.ProductConsumer;
import com.packcheng.ndkdemo.jni.StaticLink;
import com.packcheng.ndkdemo.util.LogUtil;

/**
 * JNI/NDK T工程之前备份
 *
 * @author packcheng
 * @date 2021/8/10 00:19
 */
public class MainActivity2 extends BaseActivity<ActivityMain2Binding> {

    JniRoot root = new JniRoot();
    ProductConsumer productConsumer;

    @Override
    protected int getContentResId() {
        return R.layout.activity_main2;
    }

    @Override
    protected void initView() {
        super.initView();

        final StaticLink staticLink = new StaticLink();
        mBinding.btnStaticLink.setOnClickListener(v -> {
            String result = staticLink.helloFromCPP("packcheng");
            LogUtil.w("hello from cpp: " + result);
            staticLink.sayHelloToCPP("packcheng", 18, new String[]{"12345", "23456", "34567"});
        });

        mBinding.btnDynamicLink.setOnClickListener(v -> {
            DynamicLink dynamicLink = new DynamicLink();
            LogUtil.w("hello from cpp: " + dynamicLink.dynamicHelloFromCPP("zbc"));
            boolean success = dynamicLink.dynamicSayHelloToCpp("zbc", 169.9);
            LogUtil.w("success: " + success);
        });

        mBinding.btnClassOperate.setOnClickListener(v -> {
            ClassOperate classOperate = new ClassOperate();
            classOperate.updateMemberFiled();
            LogUtil.w("update: " + classOperate.toString());
            classOperate.callMemberMethod();
            LogUtil.w("update: " + classOperate.toString());

            ClassOperate newOne = new ClassOperate();
            newOne.setAge(222);
            LogUtil.w("old: " + classOperate.toString());
            classOperate.update(newOne);
            LogUtil.w("update: " + classOperate.toString());

            ClassOperate.updateClassFiled();
            LogUtil.w("update: " + classOperate.toString());
            ClassOperate.callClassMethod();
            LogUtil.w("update: " + classOperate.toString());
            ClassOperate classOperate1 = ClassOperate.create();
            LogUtil.w("new obj: " + classOperate1.toString());
        });

        mBinding.btnNativeThread.setOnClickListener(v -> {
            NativeThread nativeThread = new NativeThread();
            nativeThread.nativeInit();
            LogUtil.d("Create NativeThread and call nativeInit");
        });

        mBinding.btnProductConsumerStart.setOnClickListener(v -> {
            productConsumer = new ProductConsumer();
            productConsumer.start();
            LogUtil.d("Call ProductConsumer's method: start");
        });

        mBinding.btnProductConsumerStop.setOnClickListener(v -> {
            if (null == productConsumer) {
                return;
            }
            productConsumer.stop();
            LogUtil.d("Call ProductConsumer's method: stop");
        });

    }

    @Override
    protected void onDestroy() {
        if (null != productConsumer) {
            productConsumer.stop();
        }
        super.onDestroy();
    }
}