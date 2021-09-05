package com.packcheng.mylib;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private final NativeLib lib = new NativeLib();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.btn_call).setOnClickListener(v->{
            lib.stringFromJNI();
        });
    }
}