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

#pragma pack(1)
typedef struct {
    char version;      /*文件版本标志，此为版本"1"*/
    char flag[3];      /*文件标志位，此版本为第一版，填充为"vd",意为Virtual Disk*/
    uint64_t fsize;    /*文件长度*/
    uint8_t bsizeflag; /*block size flag*/
    uint64_t bcount;   /*block 数量*/
    uint64_t tstart;   /*block分配表起始位置*/
    uint64_t tend;     /*block分配表结束位置*/
    uint64_t bstart;   /*block起始位置*/
    uint64_t bend;     /*block结束位置*/
} VDF_HEADER;

typedef struct vdf_descriptor {
    VDF_HEADER header;
    int blocksize;
    FILE *vdfp;
} VDFPTR;

typedef struct bat_node_descriptor{
    int id;
    int offset;
    uint8_t umask;
    uint8_t value;
} BATNODEPTR;

typedef struct block_descriptor {
    VDFPTR vdfpoint;
    BATNODEPTR batnodepoint;
    int offset;
    char *data;
} BLOCKPTR;

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



