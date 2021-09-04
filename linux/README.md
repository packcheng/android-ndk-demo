# Linux

## Linux常用快捷键

| **快捷键** | **功能** |
| --- | --- |
| Ctrl + A | 光标移到最前面 |
| Ctrl + E | 光标移到最后面 |
| Ctrl + U | 光标清除 |
| TAB | 命令自动补全 |
| ↑、↓ | 切换之前输入的命令 |

## Linux常用文件命令

| **命令** | **功能** |
| --- | --- |
| cd dir | 跳转目录 |
| cd .. | 返回上一层目录 |
| cd | 返回根目录 |
| cd ~ | 返回根目录 |
| clear | 清屏 |
| pwd | 当前完整路径 |
| date | 当前时间 |
| ls | 大概目录 |
| ls -all | 详细目录 |
| ls -lh | 详细目录（包含大小） |
| ls -R | 包含子目录文件 |
| mkdir dirname | 创建目录 |
| touch 1.txt | 创建文件 |
| rm -rf 1.txt | 递归删除文件夹或文件 |
| cp src.txt test/ | 复制 |
| mv src.txt src1.txt | 重命名 |
| chmod 777 src1.txt | 设置可读可写可执行权限 |
| chmod u+rwx src1.txt | 第一组设置可读可写可执行权限 |
| chmod g+rwx src1.txt | 第二组设置可读可写可执行权限 |
| chmod o+rwx src1.txt | 第三组设置可读可写可执行权限 |
| chmod a+rwx src1.txt | 所有组设置可读可写可执行权限 |
| cat src1.txt | 查看文件 |
| tac src1.txt | 倒序查看文件 |
| more src1.txt | 百分比查看文件 |
| head -3 src1.txt | 只查看前面三行 |
| tail -3 src1.txt | 只查看后面三行 |
| vim src1.txt | 查看文件(C/C++高亮) |
| vi src1.txt | 查看文件(C/C++不高亮) |
| find . -name "*.sh" | 在当前目录查找名字后缀为.sh的所有文件 |
| tar czf all.taz *.sh | 包所有名字后缀为.sh的文件压缩到all.taz中 |

ls -all 查看文件目录详情结果
> ```
> -rw-r--r--  1 packcheng  staff    0 Sep  4 13:37 1.txt
> ```
> 结果解析
> | -rw-r--r-- | 1 |packcheng | staff | 0 |Sep  4 13:37 |1.txt|
> | --- | --- | --- | --- | --- | --- | --- |
> | 权限 | 软链接数 | 所属用户 | 所属组 | - | 日期 | 文件名 |
>
> 权限**-rw-r--r--**解析
> 1. 第一位——文件类型
> + \- 普通文件
> + d 目录
> + l 软链接
> + c 字符设备文件
> + b 块设备文件
> + p 管道
> + s 套接字
>
> 2. **rw-** 第一组，当前自身用户权限(可读可写不可执行权限)
> 3. **r--** 第二组，同组用户权限(可读不可写不可执行权限)
> 4. **r--** 第三组，其他用户权限(可读不可写不可执行权限)

## Linux 用户与用户组

1. 用户类型

+ \# 超级用户root
+ \$ 普通用户

> 使用以下命令可以修改权限：
> ```shell 
> sudo su root 
> ```
> 输入密码后，可以将普通用户设置为超级用户权限
> ```shell
> exit
> ```
> 退出超级权限

## VIM

### 模式及切换

| 模式 | 进入命令 | 退出命令 |
| --- | --- | ---|
| 命令模式 | 默认/ESC | i,a,s | 
| 编辑模式 | i,a,s | ESC |
| 末行模式 | : | ESC |

> **退出VIM:** 命令模式下按**Shift+zz**或者 **:wq**

### VIM常用快捷键

| 快捷键 | 功能 |
| --- | --- |
| i | 输入，光标不动 |
| I | 输入，光标移到行首 |
| a | 输入，光标迁移一个字符 |
| A | 输入，光标移到行尾 |
| s | 输入，删除当前光标的字符 |
| S | 输入，删除当前光标所在行 |
| :q! | 强制退出不保存 |
| :wq | 退出并保存 |
| h | 光标左移 |
| j | 光标下移 |
| k | 光标上移 |
| l | 光标右移 |
| 5G | 跳转到指定行 |
| gg | 跳转第一行 |
| G | 跳转最后一行 |
| $ | 跳转行尾 |
| 0 | 跳转行首 |
| dw | 删除单词 |
| dd | 删除当前行/剪切当前行 |
| 3dd | 删除三行 |
| :set number | 显示行号 |
| yy | 复制一行 |
| P | 刚刚复制的内容粘贴到下一行 |
| p | 刚刚复制的内容粘贴到当前行 |
| / | 查找内容 |
| r (+) a | 将当前光标内容替换为a |
| :s /hello/hello1 | 将光标所在行hello替换为hello1 |
| :%s /hello/hello1/g | 将所有hello替换为hello1 |
| :1,6s /hello/hello1/g | 将1-6行所有hello替换为hello1 |

## Shell编程

| 指令 | 内容 |
| --- | --- |
| $? | 检测上一个命令是否成功,0：成功；127：失败 |
| $PWD | 获取当前脚本完整路径 |
| $0 | 当前脚本文件名称 |
| $1 | 参数一 |
| $* | 全部参数内容 |
| $# | 参数个数 |

## 交叉编译

gcc 命令参数

| 参数名 | 作用 |
| --- | --- |
| -o | 生成文件 |
| -c | 生成目标产物xxx.o |
| -shared | 生成动态库xxx.so |

### 交叉编译步骤

+ 导出NDK内部GCC的路径

```shell
export NDK_GCC="/Users/packcheng/Library/Android/sdk/ndk/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/arm-linux-androideabi/bin/gcc"
```

+ --sysroot=/Users/packcheng/Library/Android/sdk/ndk/platforms/android-28/arch-arm 指定寻找头文件和库文件的路径
+ -isystem /Users/packcheng/Library/Android/sdk/ndk/sysroot/usr/include 指定寻找头文件的路径
+ -isystem /Users/packcheng/Library/Android/sdk/ndk/sysroot/usr/include/arm-linux-androideabi
  指定寻找asm的路径

```shell
export AAA="--sysroot=/Users/packcheng/Library/Android/sdk/ndk/platforms/android-28/arch-arm -isystem /Users/packcheng/Library/Android/sdk/ndk/sysroot/usr/include -isystem /Users/packcheng/Library/Android/sdk/ndk/sysroot/usr/include/arm-linux-androideabi"
```

> **--sysroot=path** 在此目录自动寻找头文件和库文件
> **-isystem path** 在此目录自动寻找头文件

执行编译生成可执行文件

```shell
$NDK_GCC pie $AAA main.c -o main
```

### 编译生成动态库

编译生成Linux服务器使用的动态库

```shell
gcc -fPIC -shared main.c -o lib.so
```

交叉编译生成Android使用的动态库

```shell
$NDK_GCC $AAA -fPIC -shared main.c -o lib.so
```

查看库内容

```shell
file lib.so
```

### 编译生成静态库

步骤：

1. 生成目标文件xxx.o
2. 借助 **ar** 生成静态库xxx.a

编译生成Linux服务器使用的静态库

```shell
gcc -fPIC -c main.c -o main.o
ar rcs -o main.a main.o
```

交叉编译生成Android使用的静态库

```shell
export NDK_AR="/Users/packcheng/Library/Android/sdk/ndk/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/arm-linux-androideabi/bin/ar"
$NDK_GCC $AAA -fPIC -c main.c -o main.o
$NDK_AR rcs -o main.a main.o
```

**这一步必须使用ndk的gcc生成的xxx.o文件，否则能打包成功xxx.a但无法在手机上运行，且很难排查原因！！！**

### CMakeLists.txt配置

```cmake
# 批量导入
file(GLOB allCPP *.cpp)

add_library(
        native-lib
        SHARED
        ${allCPP}
)

# 导入静态库 libmain.a
add_library(getndk STATIC IMPORTED)
# 开始真正导入静态库
set_target_properties(getndk PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libmain.a)

# 导入动态库libmain1.so
add_library(getndk1 SHARED IMPORTED)
# 开始真正导入动态库
set_target_properties(getndk1 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}/libmain1.so)

# !!!动态库还需要额外的加载System.loadLibrasy("main1")

# 链接静态库到总库
target_link_libraries(
        native-lib
        log
        main
        main1
)
```








