#include <stdio.h>
#include <string.h>

void print_help(){
    printf("用法:minimake [目标]\n");
    printf("选项:\n");
    printf("  --help     显示帮助信息\n");
}

int main(int argc,char *argv[]){
    if(argc == 1){
        printf("错误：未指定目标！\n");
        return 1;
    }

    if(strcmp(argv[1],"--help")==0){
        print_help();
        return 0;
    }


    printf("正在构建目标：%s\n",argv[1]);
    return 0;
}