/* 
 * File:   VirtualDiskSystem.c
 * Author: yrobert2
 *
 * Created on March 9, 2016, 2:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct {
    size_t length;
    char path[1000];
} FILENAME;

#define MAX_OPEN_FILE 65535
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

FILENAME getInitVirtualDiskFile(){
    FILENAME fn;
    fn.length=strlen("asdasdasdasd");
    strncpy(fn.path,"asdasdasdasd",fn.length);
    return fn;
}

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fp[MAX_OPEN_FILE];
    int i;
    FILENAME fn;
    
    fn=getInitVirtualDiskFile();
    printf("%s,%d\n",fn.path,fn.length);
    return (EXIT_SUCCESS);
}

/*@Unperfect*/
/*向系统配置文件vdf.conf中添加文件*/
int vdf_addvdf(const char *filepath){
    FILE *configfp=fopen("vdf.conf","ab");/*以添加方式打开*/
    if(configfp==NULL)return E_FBADIO;
    if(access(filepath,F_OK))return E_FBADIO; /*文件不存在*/
    fwrite(filepath,strlen(filepath),1,configfp);
    fputc(0xAA,configfp);
    fclose(configfp);
    return E_SUCCESS;
}

/*@Unperfect*/
/*从系统配置文件vdf.conf中删除文件*/
int vdf_rmvdf(const char *filepath){
    
}

/*@Unperfect*/
/*从系统配置文件中读取一个vdf文件,并返回一个可读写的文件描述符*/
FILE * vdf_getvdf(FILE *conf){
    char f[1000];
    int i;
    if(feof(conf))return NULL;
    for(i=0;i<1000;i++){
        f[i]=fgetc(conf);
        if(f[i]==0xAA){
            f[i]='\0';
            break;
        }
    }
    return fopen(f,"r+b");
}



