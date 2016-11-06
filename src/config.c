#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

struct option_s {
    char key[256];
    char value[256];
};

/* extern variables */
struct config_s drcom_config = {
    .remote_port = 61440,
};
/* extern variables */

/* locale functions */
static int parse_line(char *buf, int size);
static void strstrip(char *s, char *chars);
/* locale functions */

int parse_config(char *conf_file_name)
{
//    char conf_file_name[256] = "/etc/gdut-drcom.conf";

    char line_buf[1024];
#ifdef DEBUG
    fprintf(stdout, "conf_file_name = %s\n", conf_file_name);
    fflush(stdout);
#endif

    FILE *fp = fopen(conf_file_name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "open %s failed!\n", conf_file_name);
        fflush(stderr);
        exit(-1);
    }

    while(!feof(fp))
    {
        memset(line_buf, 0, sizeof(line_buf));
        fgets(line_buf, sizeof(line_buf)-1, fp);
        if (strlen(line_buf) > 0)
        {
            parse_line(line_buf, sizeof(line_buf));
        }
    }
    fclose(fp);

    return 0;
}

static int parse_line(char *buf, int size)
{
    char *p;
    struct option_s opt = {{0}};

    //comment
    p = strchr(buf, '#');
    if (p)
        *p = '\0';

    p = strchr(buf, '=');
    if (p == NULL)
        return 1;
    strncpy(opt.key, buf, p - buf);
    strstrip(opt.key, " \n\r\t");
    if ((opt.key[0]=='"' && opt.key[strlen(opt.key)-1]=='"') ||
            (opt.key[0]=='\'' && opt.key[strlen(opt.key)-1]=='\''))
        strstrip(opt.key, "\"'");

    strncpy(opt.value, p+1, strlen(p));
    strstrip(opt.value, " \r\t\n");
    if ((opt.value[0]=='"' && opt.value[strlen(opt.value)-1]=='"') ||
            (opt.value[0]=='\'' && opt.value[strlen(opt.value)-1]=='\''))
        strstrip(opt.value, "\"'");

    if (strcmp(opt.key, "remote_ip") == 0)
    {
        strcpy(drcom_config.remote_ip, opt.value);
    }
    else if (strcmp(opt.key, "remote_port") == 0)
    {
        drcom_config.remote_port = atoi(opt.value);
    }
    else if(strcmp(opt.key, "keep_alive1_flag") == 0)
    {
        sscanf(opt.value, "%02hhx", &drcom_config.keep_alive1_flag);
    }
/*    else if(strcmp(opt.key, "keep_alive2_flag") == 0)
    {
        sscanf(opt.value, "%02hhx", &drcom_config.keep_alive2_flag);
    }*/

    return 0;
}

static void strstrip(char *s, char *chars)
{
    int i;
    char *p;
    p = s;
    while (strchr(chars, *p)!=NULL && *p!='\0')
    {
        p++;
    }
    strcpy(s, p);

    i = strlen(s) - 1;
    while (strchr(chars, s[i])!=NULL && i>=0)
    {
        s[i] = '\0';
        i--;
    }
}

