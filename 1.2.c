#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_makefile(const char* filename){
    FILE* file =fopen("Makefile","r");
    if(file == NULL){
        printf("错误：找不到Makefile文件！\n");
        exit(1);
    }
    char line[256];
    while(fgets(line,sizeof(line),file)){
        line[strcspn(line,"\n")]='\0';
        while(strlen(line)>0&&(line[strlen(line)-1]==' '||line[strlen(line)-1]=='\t')){
            line[strlen(line)-1]='\0';
        }
        if(line[0]=='\0'||line[0]=='#'){
            continue;
        }
        printf("处理后的行:%s\n",line);
    }
    fclose(file);
}

int main(){
    read_makefile("Makefile");
    return 0;
}