# myC

My target database test repo.

1.VirtualDataSystem 虚拟数据系统
1.1 存储形式 key-value key的长度为最大为255字节
1.2 VDF-BLOCK存储格式 0~1字节(uint16_t)：数据长度；2~9字节(uint64_t)：下一个块的位置（0表示此块为数据的最后一个块）；10~ N字节：数据（N-10+1=数据长度）
1.3 DAT(Data Allocation Table)数据分配表 起始位于Block 0，每一项长度为16字节，0~3字节，key值的位置，4~7字节，key的长度，8~11，value的block ID，12~15，value长度
1.4 Key Data Area 起始位于Block 1