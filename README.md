# android-ndk-demo
JNI/NDK练习

## NativeCrash定位
1. arm-linux-androideabi-addr2line  
作用: 定位出错位置  
位置: /ndk/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin  
使用:
```shell
    arm-linux-androideabi-addr2line -e /aa/bb/xxx.so 00000cf4 00000d1c
```

2. arm-linux-androideabi-objdump  
作用: 定位出错的函数信息  
位置: /ndk/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin  
使用:
```shell
    arm-linux-androideabi-objdump -S -D /aa/bb/xxx.so > /dump.log
```

3. ndk-stack  
作用: 定位出错位置  
位置: ndk目录  
使用:
```shell
    adb logcat | ndk-stack -sym /aa/bb/xxx.so
```
	或者使用以下的方式:
```shell
    adb logcat > crash.log
    ndk-stack -sym /aa/bb/xxx.so -dump crash.log
```

## 目录结构
- T1 Ndk与Java方法回调/Ndk修改Java属性和静态属性
- T2 数组操作、创建对象

## 重要笔记

