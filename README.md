# gdut-drcom
                   __     __         __
          ___  ___/ /_ __/ /_    ___/ /__________  __ _
         / _ `/ _  / // / __/   / _  / __/ __/ _ \/  ' \
         \_, /\_,_/\_,_/\__/    \_,_/_/  \__/\___/_/_/_/
        /___/    A third-party drcom client for gdut.
        
本项目旨在为第三方 drcom 客户端提供一个心跳服务，提供一个命令行工具（gdut-drcom），以及一个动态库（gdut-drcom.dll, gdut-drcom.so）供上层程序调用，支持 Linux 与 Windows(mingw64) 平台。

目前仅测试过，适用于广东工业大学的drcom客户端（drcom 5.2.1p），理论上也支持其他学校的drcom客户端，请自测。如有需要移植到其他学校，请联系我（chenhaowen01@qq.com）。

# compile
* Linux
```bash
git clone https://github.com/chenhaowen01/gdut-drcom.git
cd gdut-drcom/src

# 编译命令行工具
# 可通过cryptlib变量指定加密库，留空表示不使用第三方库
# cryptlib=[openssl, polarssl, gcrypt]
# 如
make cryptlib=openssl

# 编译动态链接库
make dll
```

* Windows（[mingw-w64][3]）
```
git clone https://github.com/chenhaowen01/gdut-drcom.git
cd gdut-drcom\src

# 可通过cryptlib变量指定加密库，留空表示不使用第三方库
# cryptlib=[openssl, polarssl, gcrypt]
# 如
mingw32-make CC=gcc

# 编译动态链接库
make dll CC=gcc
```
# usage
```
gdut-drcom
    --remote-ip <ip addr>               The server ip.

    [--remote-port <port>]              The server port, default as 61440.
    [--keep-alive1-flag <flag>]         The keep alive 1 packet's flag.
                                            default as 00.
    [--enable-crypt]                    Enable crypt of keep alive1 packet2.
    [-c, --config-file <file>]          The path to config file.
    [-h, --help]                        Print this message.
    [-v, --version]                     Print version infomatuon
```

# reference
数据包结构参考了[drcom-generic][1]

心跳包校验和算法参考了[drcom-generic issues #82][2]

[1]: https://github.com/drcoms/drcom-generic
[2]: https://github.com/drcoms/drcom-generic/issues/82
[3]: https://sourceforge.net/projects/mingw-w64/
