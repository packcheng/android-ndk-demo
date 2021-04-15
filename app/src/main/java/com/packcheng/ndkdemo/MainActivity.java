package com.packcheng.ndkdemo;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import com.packcheng.ndkdemo.databinding.ActivityMainBinding;
import com.packcheng.ndkdemo.jni.ClassOperate;
import com.packcheng.ndkdemo.jni.DynamicLink;
import com.packcheng.ndkdemo.jni.JniRoot;
import com.packcheng.ndkdemo.jni.StaticLink;
import com.packcheng.ndkdemo.util.LogUtil;

public class MainActivity extends AppCompatActivity {

    ActivityMainBinding mBinding;

    JniRoot root = new JniRoot();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = DataBindingUtil.setContentView(this, R.layout.activity_main);

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
    }

}