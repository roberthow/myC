/*size为写入的字节数，mp为内存指针，返回实际写入的字节数*/
int add(uint64_t blockid, uint64_t size, char *mp){
    
}

/*返回值 0=成功，非0=失败*/
int clear(uint64_t blockid){
    
}

/*size为覆盖写入的字节数，mp为内存指针，返回实际写入的字节数*/
int replace(uint64_t blockid, uint64_t size, char *mp){
    
}

/*mp为内存指针，返回实际获取的字节数*/
int get(FILE *fp, uint64_t blockid, char *mp){
    BAT_NODE bnode;
    VDF vdf;
    
    vdf_getnodedesc(&bnode,blockid,fp);
    if(bnode->value){
        vdf_getdesc(&vdf,fp);
        vdf_bread(mp, vdf.blocksize, blockid, fp);
        return vdf.blocksize;
    }
    else{
        return 0;
    }
}
