package com.packcheng.fmode;

import com.packcheng.base.BaseActivity;
import com.packcheng.fmode.databinding.ActivityFmodeBinding;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class FmodeActivity extends BaseActivity<ActivityFmodeBinding> {
    static {
        System.loadLibrary("fmod");
        System.loadLibrary("fmodL");
        System.loadLibrary("my-fmode-lib");
    }

    private FModePlayer mPlayer;
    private final String mPath = "file:///android_asset/sound.mp3";
    private final ThreadPoolExecutor mPool = new ThreadPoolExecutor(1, 1,
            60, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10));

    @Override
    protected int getContentResId() {
        return R.layout.activity_fmode;
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mPlayer.destroy();
    }

    @Override
    protected void initView() {
        super.initView();
        mPlayer = new FModePlayer(this);

        mBinding.btnNormal.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_NORMAL)));
        mBinding.btnLuoli.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_LUOLI)));
        mBinding.btnDashu.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_DASHU)));
        mBinding.btnKongling.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_KONGLING)));
        mBinding.btnGaoguai.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_GAOGUI)));
        mBinding.btnJingson.setOnClickListener(v -> mPool.submit(() -> mPlayer.startPlay(mPath, FModePlayer.MODE_JINGXIONG)));
    }
}