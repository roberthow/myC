#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024*1024*10

int main(int argc, char** argv) {
    //printf("hello!");
    
    int rv=mc_create_file("d:/mytemp.myt",1024*1024*256); /* 1024M */
    if(rv<0){
        return (EXIT_FAILURE);
    }
    else{
        return (EXIT_SUCCESS);
    }
}

int mc_create_file(const char *path, long size){
    long size_left=size;
    char s[MAX_SIZE]={0};
    FILE *fp = fopen(path, "wb");
    if(fp==NULL) return -1;
    while(size_left>0){
        if(size_left>MAX_SIZE){
            printf("1.write %d byte to file.\n",MAX_SIZE);
            fwrite(s,MAX_SIZE,sizeof(char),fp);
            size_left-=MAX_SIZE;
        }
        else{
            printf("2.write %d byte to file.\n",size_left);
            fwrite(s,sizeof(char),size_left,fp);
            size_left=0;
        }
    }
    fputc(0,fp);
    fclose(fp);
    return 0;
}