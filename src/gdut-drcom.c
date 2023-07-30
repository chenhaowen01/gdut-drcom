#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "auth.h"
#include "config.h"
#include "logger.h"

static void print_help(char * name);

int main(int argc, char *argv[])
{
    char conf_file_name[256] = {0};

    drcom_config.log_file = stdout;
    logger = Logger_create();
    logger->level = LOG_DEBUG;

    if (argc == 1)
    {
        print_help(argv[0]);
        exit(-1);
    }

    int opt;
    while (1)
    {
        int option_index = 0;
        static struct option long_options[] =
        {
            {"help",                no_argument,        0,  'h'},
            {"config-file",         required_argument,  0,  'c'},
            {"version",             no_argument,        0,  'v'},
            {"log-file",            required_argument,  0,  'l'},
            {"remote-ip",           required_argument,  0,  0},
            {"local-ip",            required_argument,  0,  1},
            {"remote-port",         required_argument,  0,  2},
            {"keep-alive1-flag",    required_argument,  0,  3},
            {"enable-crypt",        no_argument,        0,  4},
            {0,             0,                  0,  0},
        };
        opt = getopt_long(argc, argv, "hc:l:v", long_options, &option_index);
        if (opt == -1)
        {
            break;
        }
        switch (opt)
        {
            case 0:     //remote-ip
                strcpy(drcom_config.remote_ip, optarg);
                break;
            case 1:     //local-ip
                strcpy(drcom_config.local_ip, optarg);
                break;
            case 2:     //remote_port
                drcom_config.remote_port = atoi(optarg);
                break;
            case 3:     //keep_alive1_flag
                sscanf(optarg, "%02hhx", &drcom_config.keep_alive1_flag);
                break;
            case 4:
                drcom_config.enable_crypt = 1;
                break;
            case 'c':
                strcpy(conf_file_name, optarg);
                parse_config(conf_file_name);
                break;
            case 'h':
                print_help(argv[0]);
                exit(0);
                break;
            case 'v':
                fprintf(stdout, "version: %s\n", _VERSION);
                exit(0);
                break;
            case 'l':
                set_log_file(optarg, strlen(optarg));
                break;
            case '?':
                break;
            default:
                break;
        }
    }
//    if (!conf_file_name[0] == '\0')
//    {
//        parse_config(conf_file_name);
//    }
#ifdef DEBUG
    fflush(drcom_config.log_file);
#endif

    auth();

    return 0;
}

static void print_help(char *name)
{
//    fprintf(stdout, "gdut-drcom\n");
    fprintf(stdout,
        "                   __     __         __                 \n"
        "          ___  ___/ /_ __/ /_    ___/ /__________  __ _ \n"
        "         / _ `/ _  / // / __/   / _  / __/ __/ _ \\/  ' \\\n"
        "         \\_, /\\_,_/\\_,_/\\__/    \\_,_/_/  \\__/\\___/_/_/_/\n"
        "        /___/   "
            );

    fprintf(stdout, "A third-party drcom client for gdut. version %s\n", _VERSION);
    fprintf(stdout, "usage:\n");
    fprintf(stdout, "  %s\n", name);
    fprintf(stdout, "    --remote-ip <ip addr>               The server ip.\n");
    fprintf(stdout, "\n");
    fprintf(stdout, "    [--local-ip <ip addr>]              local ip, default as 0.0.0.0.\n");
    fprintf(stdout, "    [--remote-port <port>]              The server port, default as 61440.\n");
    fprintf(stdout, "    [--keep-alive1-flag <flag>]         The keep alive 1 packet's flag.\n"
                    "                                            default as 00.\n");
    fprintf(stdout, "    [--enable-crypt]                    Enable crypt of keep alive1 packet2\n");
    fprintf(stdout, "    [-c, --config-file <file>]          The path to config file.\n");
    fprintf(stdout, "    [-l, --log-file <file>]             The path to log file, default as stdout.\n");
    fprintf(stdout, "    [-h, --help]                        Print this message.\n");
    fprintf(stdout, "    [-v, --version]                     Print version infomatuon..\n");
}

