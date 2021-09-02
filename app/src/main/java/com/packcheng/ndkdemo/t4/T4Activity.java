package com.packcheng.ndkdemo.t4;

import android.content.Context;
import android.content.Intent;
import android.os.Parcel;

import com.packcheng.base.BaseActivity;
import com.packcheng.base.LogUtil;
import com.packcheng.ndkdemo.R;
import com.packcheng.ndkdemo.databinding.ActivityT4Binding;

/**
 * 仿实现Parcel
 *
 * @author packcheng
 * @date 2021/8/10 00:23
 */
public class T4Activity extends BaseActivity<ActivityT4Binding> {

    public static void startActivity(Context context) {
        context.startActivity(new Intent(context, T4Activity.class));
    }

    @Override
    protected int getContentResId() {
        return R.layout.activity_t4;
    }


    @Override
    protected void initView() {
        super.initView();
    }

    @Override
    protected void initData() {
        super.initData();

        Parcel parcel = Parcel.obtain();
        int input = 100;
        parcel.writeInt(input);
        LogUtil.i("系统写入: " + input);
        input = 50;
        parcel.writeInt(input);
        LogUtil.i("系统写入: " + input);

        parcel.setDataPosition(0);

        int result;
        result = parcel.readInt();
        LogUtil.i("系统读取: " + result);
        result = parcel.readInt();
        LogUtil.i("系统读取: " + result);
        parcel.recycle();

        LogUtil.i("------------------------------");
        DParcel myParcel = DParcel.obtain();
        myParcel.writeInt(input);
        LogUtil.i("系统写入: " + input);
        myParcel.writeInt(50);
        LogUtil.i("系统写入: " + input);

        myParcel.setDataPosition(0);

        result = myParcel.readInt();
        LogUtil.i("系统读取: " + result);
        result = myParcel.readInt();
        LogUtil.i("系统读取: " + result);

    }
}