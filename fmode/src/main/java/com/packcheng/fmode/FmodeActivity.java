package com.packcheng.fmode;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class FmodeActivity extends AppCompatActivity {
    static {
        System.loadLibrary("my-fmode-lib");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fmode);
    }
}