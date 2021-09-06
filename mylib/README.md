# 自己编译生成动态库和静态库并在APP中使用

## 第一步、编写c文件和头文件

在目录/prebuild/code/目录下:
[static.h](./prebuild/code/static.h)
[dynamic.h](./prebuild/code/dynamic.h)[
static.c](./prebuild/code/static.c)
[dynamic.c](./prebuild/code/dynamic.c)

## 第二步、交叉编译生成动态库和静态库

具体可参考以下脚本:
生成动态库：[pack_dynamic](./prebuild/sh/pack_dynamic.sh)
生成静态库：[pack_static](./prebuild/sh/pack_static.sh)

生成动态库的路径为：[arm64-v8a](./prebuild/out/arm64-v8a)、[armeabi-v7a](./prebuild/out/armeabi-v7a)

> **注意：**
> *1. 因为我使用的是ndk提供的gcc进行编译的，所以在编译的时候必须下载ndk17以下的版本，因为在更高的版本中，找不到gcc了*
>
> *2. 动态库的名字的格式为 libxxx.a ;静态库的名字格式为 libxxx.so*

### 1. 使用交叉编译生成静态库

1. 定义编译中需要用到的gcc/ar路径并配置库文件和头文件的引用位置

```shell
NDK_ROOT="/Users/packcheng/Library/Android/sdk/ndk/17.2.4988734"

NDK_GCC_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc"
NDK_LIB_CONFIG_V7="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/arm-linux-androideabi"
NDK_AR_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-ar"

NDK_GCC_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-gcc"
NDK_LIB_CONFIG_V8="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm64 -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/aarch64-linux-android"
NDK_AR_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-ar"
```

2. 定义源文件路径和输出路径

```shell
CUR_DIR=$(pwd)
SRC_FILE=$CUR_DIR/../code/static.c

DES_FILE_O_V7=$CUR_DIR/../out/armeabi-v7a/static.o
DES_FILE_A_V7=$CUR_DIR/../out/armeabi-v7a/libstatic.a

DES_FILE_O_V8=$CUR_DIR/../out/arm64-v8a/static.o
DES_FILE_A_V8=$CUR_DIR/../out/arm64-v8a/libstatic.a
```

3. 交叉编译生成中间产物和静态库

```shell
# armeabi-v7a
$NDK_GCC_V7 $NDK_LIB_CONFIG_V7 -fPIC -c $SRC_FILE -o $DES_FILE_O_V7
$NDK_AR_V7 rcs -o $DES_FILE_A_V7 $DES_FILE_O_V7

# arm64-v8a
$NDK_GCC_V8 $NDK_LIB_CONFIG_V8 -fPIC -c $SRC_FILE -o $DES_FILE_O_V8
$NDK_AR_V8 rcs -o $
```

### 2. 使用交叉编译生成动态库

1. 指定编译需要用到的ndk提供的gcc和编译链接so和头文件的路径

```shell
NDK_ROOT="/Users/packcheng/Library/Android/sdk/ndk/17.2.4988734"

NDK_GCC_V7="$NDK_ROOT/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc"
NDK_LIB_CONFIG_V7="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/arm-linux-androideabi"

NDK_GCC_V8="$NDK_ROOT/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/bin/aarch64-linux-android-gcc"
NDK_LIB_CONFIG_V8="--sysroot=$NDK_ROOT/platforms/android-28/arch-arm64 -isystem $NDK_ROOT/sysroot/usr/include -isystem $NDK_ROOT/sysroot/usr/include/aarch64-linux-android"
```

2. 指定源文件和生成so的路径

```shell
CUR_DIR=$(pwd)
SRC_FILE=$CUR_DIR/../code/dynamic.c
DES_FILE_V7=$CUR_DIR/../out/armeabi-v7a/libdynamic.so
DES_FILE_V8=$CUR_DIR/../out/arm64-v8a/libdynamic.so
```

3. 使用交叉编译生成动态库xxx.so

```shell
# armeabi-v7a
$NDK_GCC_V7 $NDK_LIB_CONFIG_V7 -fPIC -shared $SRC_FILE -o $DES_FILE_V7

# arm64-v8a
$NDK_GCC_V8 $NDK_LIB_CONFIG_V8 -fPIC -shared $SRC_FILE -o $DES_FILE_V8
```

## 第三步、在项目中使用生成的动态库和静态库

1. 将源文件中定义的头文件拷贝到自己的项目中

> 在本项目中，就是将[static.h](./prebuild/code/static.h)和[dynamic.h](./prebuild/code/dynamic.h)拷贝到[mylib](./src/main/cpp/mylib)中。

2. 将动态库拷贝到项目中

> 在本项目中，就是将prebuild/out/下面[arm64-v8a](./prebuild/out/arm64-v8a)、[armeabi-v7a](./prebuild/out/armeabi-v7a)中的**static.a**拷贝到项目jniLibs对应目录的[arm64-v8a](./src/main/jniLibs/arm64-v8a)、[armeabi-v7a](./src/main/jniLibs/armeabi-v7a)中

3. 将静态库拷贝到项目中

> 在本项目中，就是将prebuild/out/下面[arm64-v8a](./prebuild/out/arm64-v8a)、[armeabi-v7a](./prebuild/out/armeabi-v7a)中的**dynamic.so**拷贝到项目cpp/mylib对应的[arm64-v8a](./src/main/cpp/mylib/arm64-v8a)、[armeabi-v7a](./src/main/cpp/mylib/armeabi-v7a)中

4. CMake中配置动态库和静态库

> 1. 批量导入所有源文件和头文件
> ```shell
> # 导入头文件
> include_directories("mylib")
>
> # 批量导入所有源文件
> file(GLOB allCPP *.c *.h *.cpp)
> 
> add_library(
> mylib
> SHARED
> ${allCPP})
>   ```
>
> 2. 导入静态库文件
     > *注意：用这种方式导入库文件的时候，第一个参数(static)必须和后面链接库文件的名字一致，否则会找不到导入的库*
> ```shell
> # 导入静态库文件
> add_library(static STATIC IMPORTED)
> # 真正导入静态库文件
> set_target_properties(static PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/mylib/${CMAKE_ANDROID_ARCH_ABI}/libstatic.a)
> ```
>
> 3. 导入动态库文件
     > *原本是想用上面静态库的方式导入的，不知道怎么，一致不能成功，就改为使用这种方式导入*
> ```shell
> # 导入动态库文件
> set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")
> ```
>
> 4. 将动态库和静态库链接到我们的库中
> ```shell
> target_link_libraries(
> mylib
> log
> static
> dynamic
> )
> ```

5. app Module中的build.gradle中配置ndk架构

> ```groovy
> android{
>   defaultConfig{
>               externalNativeBuild {
>           cmake {
>               cppFlags ""
>               abiFilters "arm64-v8a", "armeabi-v7a"
>           }
>       }
>       ndk {
>           abiFilters "arm64-v8a", "armeabi-v7a"
>       }
>   }   
> }
> ```
>
> **有时候需要添加下面的额外配置(so的名字为自己导入和生成的so名)**
>
> ```groovy
> android{
>     packagingOptions {
>         pickFirst "**/libmylib.so"
>         pickFirst "**/libdynamic.so"
>     }
> }
> ```

## 第四步、加载动态库和使用

1. 加载动态库(静态库不用加载)
   **需要加载使用到的第三方so和自己生成的so**
   在java中通过以下方式加载
   
> ```java
>     static {
>         System.loadLibrary("dynamic");
>         System.loadLibrary("mylib");
>     }
> ```

2. 在native中使用静态库和动态库
   *因为项目是用C++编写的，库文件是使用c编写的，所以在导入头文件的时候需要使用extern "c"*

>
> ```c++
> // 因为当前是在c++文件中，库中的代码是用c写的，所以需要这种方式include
> extern "C" {
> #include "./mylib/static.h"
> #include "./mylib/dynamic.h"
> }
> 
> extern "C" JNIEXPORT jstring JNICALL
> Java_com_packcheng_mylib_NativeLib_stringFromJNI(
> JNIEnv *env,
> jobject /* this */) {
> std::string hello = "Hello from C++";
> int reslut1 = say_hello_from_dynamic(22);
> int reslut = say_hello_to_static();
>LOG_I("HJJJJJJJJJJJJJJJJJJJJJ %d - %d", reslut, reslut1)
> return env->NewStringUTF(hello.c_str());
> }
> ```
> 
