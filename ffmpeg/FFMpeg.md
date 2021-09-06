# FFMpeg交叉编译流程

## 下载FFMpeg

[FFMpeg下载地址](http://www.ffmpeg.org/releases/)
我这里下载的是：**ffmpeg-4.0.2.tar.bz2**

## 解压FFMpeg

解压之后，到目录中执行**./configure**
我运行的时候报一下错误：

> nasm/yasm not found or too old. Use --disable-x86asm for a crippled build.

可使用以下方式运行
```shell
./configure --disable-x86asm
```

也可以下载安装yasm，步骤如下：
> 1. 下载：[yasm的下载链接](http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz)
> 2. 解压：把下载下来的压缩包进行解压
> 3. 切换路径： cd yasm-1.3.0
> 4. 执行配置： ./configure
> 5. 编译：make
> 6. 安装：make install（提示：Permission denied，就执行sudo make install）

然后再去ffmpeg目录执行 **./configure**，发现成功了。

导出FFMpeg帮助文档

```shell
./configure --help ->/users/packcheng/desktop/ffmpeg_help.txt
```


```text
Help options:
  --list-decoders          show all available decoders  (可用解码器)
  --list-encoders          show all available encoders  (可用编码器)
  
Standard options:
  --prefix=PREFIX          install in PREFIX [/usr/local]   (我们最终产出的目录，动态库和静态库目录)

Configuration options:
  --disable-static         do not build static libraries [no]   (生成动态库)
  --enable-shared          build shared libraries [no]  (不生成动态库)
  --enable-small           optimize for size instead of speed   (可以优化库的大小，尽量加上此配置)
  --disable-runtime-cpudetect disable detecting CPU capabilities at runtime (smaller binary)
  --enable-gray            enable full grayscale support (slower color)
  --disable-swscale-alpha  disable alpha channel support in swscale
  --disable-all            disable building components, libraries and programs
  --disable-autodetect     disable automatically detected external libraries [no]
  

Component options:
  --disable-avcodec        disable libavcodec build
  --disable-avformat       disable libavformat build    (默认开启，音视频封装格式的生成与解析)
  --disable-swscale        disable libswscale build
  --disable-postproc       disable libpostproc build


```