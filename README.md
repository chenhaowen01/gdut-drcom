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
* 命令行工具
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
* 动态链接库
gdut-drcom 动态链接库提供如下接口，供上层应用程序配置与启动心跳服务：
```c
/* 函数名称：set_remote_ip
 * 参数表：  char *ip    远程认证服务器ip
 *          int len     上一个参数的长度
 * 返回值：  无
 * 函数功能：用于配置认证服务器的ip地址
 */
void set_remote_ip(char *ip, int len);

/* 函数名称：set_keep_alive1_flag
 * 参数表：  char *flag  数据包标志，两个字节大小
 *          int len     上一个参数的长度
 * 返回值：  无
 * 函数功能：用于配置第一组数据包的标志位，不设置则默认为00
 */
void set_keep_alive1_flag(char *flag, int len);

/* 函数名称：set_enable_crypt
 * 参数表：  int enable 0为禁用加密校验，1为启用加密校验
 * 返回值：  无
 * 函数功能：用于配置第一组数据包的校验是否使用加密校验，不配置则默认为不加密
 */
void set_enable_crypt(int enable);

/* 函数名称：get_version
 * 参数表：  char *version 用于存储返回的版本号，请确保该字符数组不会越界
 * 返回值：  无
 * 函数功能：用于获取当前使用的动态链接库的版本号，如"1.6.0"
 */
void get_version(char * version); 

/* 函数名称：auth
 * 参数表：  无
 * 返回值：  无
 * 函数功能：用于启动心跳服务
 */
int auth(void);
```

# reference
数据包结构参考了[drcom-generic][1]

心跳包校验和算法参考了[drcom-generic issues #82][2]

[1]: https://github.com/drcoms/drcom-generic
[2]: https://github.com/drcoms/drcom-generic/issues/82
[3]: https://sourceforge.net/projects/mingw-w64/
