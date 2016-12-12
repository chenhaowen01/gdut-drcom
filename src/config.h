#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>

#ifndef VERSION
    #define VERSION 0.0.0
#endif

#define _VERSION __VERSION(VERSION)
#define __VERSION(str) ___VERSION(str)
#define ___VERSION(str) #str

enum CRYPT_TYPE {
    DISABLE_CRYPT=0,
    ENABLE_CRYPT=1,
    AUTO_CRYPT=2
};

struct config_s {
    char remote_ip[20];
    int remote_port;
    unsigned char keep_alive1_flag;
    int enable_crypt;
    FILE * log_file;
    int exit;
};

extern struct config_s drcom_config;

int parse_config(char * conf_file_name);
void set_remote_ip(char *ip, int len);
void set_keep_alive1_flag(char *flag, int len);
void set_enable_crypt(int enable);
void get_version(char * version);
void set_log_file(char * log_file, int len);

#endif //__CONFIG_H__
