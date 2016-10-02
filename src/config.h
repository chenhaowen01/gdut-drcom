#ifndef __CONFIG_H__
#define __CONFIG_H__

struct config_s {
    char remote_ip[20];
    int remote_port;
    unsigned char keep_alive1_flag;
};

extern struct config_s drcom_config;

int parse_config(char * conf_file_name);

#endif //__CONFIG_H__
