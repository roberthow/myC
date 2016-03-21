# myC

*My target database test repo.*

## 1. Virtual Disk File API

1. 增删改查
        * int add(uint64\_t blockid, uint64\_t size, char *mp);//size为写入的字节数，mp为内存指针，返回实际写入的字节数
        * int clear(uint64\_t blockid);//返回值 0=成功，非0=失败
        * int replace(uint64\_t blockid, uint64\_t size, char *mp);//size为覆盖写入的字节数，mp为内存指针，返回实际写入的字节数
        * int get(uint64\_t blockid, char *mp); //mp为内存指针，返回实际获取的字节数

## 1. Virtual Data System 虚拟数据系统

1. 存储形式  
	* *key-value*  
	* *key的长度为最大为255字节*  
2. VDF-BLOCK存储格式:
	* *0~1字节(uint16\_t)：数据长度；*  
	* *2~9字节(uint64\_t)：下一个块的位置(0表示此块为数据的最后一个块);*  
	* *10~ N字节：数据(N-10+1=数据长度)*	
3. DAT(Data Allocation Table)数据分配表
	* *起始位于Block 0，每一项长度为16字节*
	* *0~3字节，key值的位置*
	* *4~7字节，key的长度*
	* *8~11，value的block ID*
	* *12~15，value长度*
4. Key Data Area
	* *起始位于Block 1*

5. API
        * 请求一块连续区域
        * 