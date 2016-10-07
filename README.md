# gdut-drcom
                   __     __         __
          ___  ___/ /_ __/ /_    ___/ /__________  __ _
         / _ `/ _  / // / __/   / _  / __/ __/ _ \/  ' \
         \_, /\_,_/\_,_/\__/    \_,_/_/  \__/\___/_/_/_/
        /___/    A third-party drcom client for gdut.
        
这是一个适用于广东工业大学的第三方 drcom 客户端（drcom 5.2.1p），支持 Linux （包括OpenWrt等用于路由器的发行版）与Windows。
# install
* OpenWrt
  * 使用 opkg（推荐）
  ```bash
  opkg install gdut-drcom_xxx.ipk
  ```
  * 手动安装（仅在 opkg 安装失败时使用）
  ```bash
  tar xvf gdut-drcom_xxx.tar -C /tmp
  cd /tmp/gdut-drocm
  sh install.sh
  ```

# compile
* 使用 OpenWrt SDK（以rampis平台为例）
```bash
tar xvjf OpenWrt-SDK-15.05-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64.tar.bz2
cd OpenWrt-SDK-15.05-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64
git clone https://github.com/chenhaowen01/gdut-drcom.git
make package/gdut-drcom/compile
```
* Linux
```bash
git clone https://github.com/chenhaowen01/gdut-drcom.git
cd gdut-drcom/src
# 可通过cryptlib变量指定加密库，留空表示不使用第三方库
# cryptlib=[openssl, polarssl, gcrypt]
# 如
make cryptlib=openssl
```

* Windows（[mingw-w64][3]）
```bat
git clone https://github.com/chenhaowen01/gdut-drcom.git
cd gdut-drcom\src
# 可通过cryptlib变量指定加密库，留空表示不使用第三方库
# cryptlib=[openssl, polarssl, gcrypt]
# 如
mingw32-make CC=gcc
```
# usage
```bash
gdut-drcom
    --remote-ip <ip addr>               The server ip.

    [--remote-port <port>]              The server port, default as 61440.
    [--keep-alive1-flag <flag>]         The keep alive 1 packet's flag.
                                            default as 00.
    [-c, --config-file <file>]          The path to config file.
    [-h, --help]                        Print this message.
```

# reference
数据包结构参考了[drcom-generic][1]

心跳包校验和算法参考了[drcom-generic issues #82][2]

[1]: https://github.com/drcoms/drcom-generic
[2]: https://github.com/drcoms/drcom-generic/issues/82
[3]: https://sourceforge.net/projects/mingw-w64/
