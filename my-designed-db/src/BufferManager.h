#pragma once
#include <cstdlib>
#include <string>

typedef char Byte;
typedef std::string FileNameType;
typedef int FileBlockIdType;
typedef int BufferBlockIdType;

static const int MAX_BLOCK_NUM = 25600;    // 内存中最大 block 数
static const int BLOCK_BYTE_SIZE = 4096; // 每个 block 大小4KB

class BufferBlock
{
public:
    FileNameType fileName; // 文件名
    FileBlockIdType fileBlockId; // 文件 block 号
    Byte *data; // 指向数据区域的指针
    int LRU;
    int tail;
    bool pinned;
    bool modified; // 是否被修改
    bool avail; // 是否可用

    BufferBlock() : fileName(""), fileBlockId(-1), LRU(-1), tail(0), pinned(false), modified(false), avail(true)
    {
        data = new Byte[BLOCK_BYTE_SIZE];
    }
    ~BufferBlock()
    {
        delete[] data;
    }
    // 更新数据
    bool updateBufferBlockData(const Byte newData[])
    {
        for (int i = 0; i < BLOCK_BYTE_SIZE; i++)
        {
            data[i] = newData[i];
        }
        return true;
    }
    // 读数据
    const Byte *readBufferBlockData() const
    {
        return data;
    }
    // 获取数据指针
    Byte *getBufferBlockDataHandle()
    {
        return data;
    }
    // 获取文件名
    FileNameType getFileName() const
    {
        return fileName;
    }
    // 设置文件名
    void setFileName(const FileNameType &newFileName)
    {
        fileName = newFileName;
    }
    // 获取文件 block 号
    FileBlockIdType getFileBlockId() const
    {
        return fileBlockId;
    }
    // 设置文件 block 号
    void setFileBlockId(const FileBlockIdType &newFileBlockId)
    {
        fileBlockId = newFileBlockId;
    }
    int getLRU() const
    {
        return LRU;
    }
    void initLRU()
    {
        LRU = 0;
    }
    void incrementLRU()
    {
        LRU++;
    }
    void pin()
    {
        pinned = true;
    }
    void unPin()
    {
        pinned = false;
    }
    bool isPinned() const
    {
        return pinned;
    }
    void setModified()
    {
        modified = true;
    }
    void setUnmodified()
    {
        modified = false;
    }
    // 该 block 是否被修改
    bool isModified() const
    {
        return modified;
    }
    void setAvail()
    {
        avail = true;
    }
    void setUnavail()
    {
        avail = false;
    }
    // 该 block 是否可用
    bool isAvail() const
    {
        return avail;
    }
};

class Buffer
{
public:
    BufferBlock *buffer;

    Buffer()
    {
        buffer = new BufferBlock[MAX_BLOCK_NUM];
    }
    ~Buffer()
    {
        for (BufferBlockIdType id = 0; id < MAX_BLOCK_NUM; id++)
        {
            if (!buffer[id].isAvail() && buffer[id].isModified())
                output(id, buffer[id].getFileName(), buffer[id].getFileBlockId());
        }
        delete[] buffer;
    }
    // 根据文件名和文件 block 号获取指定 block
    BufferBlock *getBlock(const FileNameType &fileName, const FileBlockIdType &fileBlockId);
    // 获取当前 block 的下一个 block
    BufferBlock *getNextBlock(BufferBlock *const &bufferBlockPtr);
    // 获取指定文件的 block 数
    int getBlockNum(const FileNameType &fileName);
    // 新建一个文件
    void newFile(const FileNameType &newFileName);
    // 删除文件
    void deleteFile(const FileNameType &fileName);
    // 添加新的 block
    void addBlock(BufferBlock *const &bufferBlockPtr);
    // 为指定文件添加新的 block
    BufferBlock *addBlock(const FileNameType &fileName);
    // 写入磁盘文件
    void output(const BufferBlockIdType &bufferBlockId, const FileNameType &fileName, const FileBlockIdType &fileBlockId);
    // 从磁盘文件加载
    void input(const BufferBlockIdType &bufferBlockId, const FileNameType &fileName, const FileBlockIdType &fileBlockId);
    // 找到一个可用的 block
    BufferBlockIdType findAvailBufferBlock();
};
