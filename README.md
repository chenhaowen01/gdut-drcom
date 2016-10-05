# gdut-drcom
                   __     __         __
          ___  ___/ /_ __/ /_    ___/ /__________  __ _
         / _ `/ _  / // / __/   / _  / __/ __/ _ \/  ' \
         \_, /\_,_/\_,_/\__/    \_,_/_/  \__/\___/_/_/_/
        /___/    A third-party drcom client for gdut.
        
这是一个适用于广东工业大学的第三方 drcom 客户端（drcom 5.2.1p），目前支持 Linux 平台（包括OpenWrt等用于路由器的发行版）。
# install
* OpenWrt
1.使用 opkg（推荐）
  ```bash
  opkg install gdut-drcom_xxx.ipk
  ```
  2.手动安装（仅在 opkg 安装失败时使用）
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
git clone git@github.com:chenhaowen01/gdut-drcom.git package/gdut-drcom
make package/gdut-drcom/compile
```
# usage
```bash
gdut-drcom
    --remote-ip <ip addr>               The server ip.

    [--remote-port <port>]              The server port, default as 61440.
    [--keep-alive1-flag <flag>]         The keep alive 1 packet's flag.
                                            default as 00.
    [-c, --config-file <file>]          The path to config file.
                                            default as /etc/gdut-drcom.conf.
    [-h, --help]                        Print this message.
```
