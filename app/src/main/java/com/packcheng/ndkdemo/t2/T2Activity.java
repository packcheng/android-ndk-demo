package com.packcheng.ndkdemo.t2;

import android.content.Context;
import android.content.Intent;

import com.packcheng.base.BaseActivity;
import com.packcheng.ndkdemo.R;
import com.packcheng.ndkdemo.databinding.ActivityT2Binding;
import com.packcheng.base.LogUtil;

/**
 * @author packcheng
 * @date 2021/8/10 00:23
 */
public class T2Activity extends BaseActivity<ActivityT2Binding> {

    private final T2 operator = new T2();

    public static void startActivity(Context context) {
        context.startActivity(new Intent(context, T2Activity.class));
    }

    @Override
    protected int getContentResId() {
        return R.layout.activity_t2;
    }

    @Override
    protected void initView() {
        super.initView();
        mBinding.btnTestArrayAction.setOnClickListener(v -> {
            int count = 10;
            String info = "zbc";
            int[] ints = {10, 20, 30, 40, 50};
            String[] strings = {"10", "20", "30", "40", "50", "AA"};

            operator.printArrayAction(count, info, ints, strings);
            operator.testArrayAction(count, info, ints, strings);
            operator.printArrayAction(count, info, ints, strings);

        });
        mBinding.btnTestInsertObject.setOnClickListener(v -> {
            operator.newObject();
            LogUtil.d(operator.toString());
        });
    }
}