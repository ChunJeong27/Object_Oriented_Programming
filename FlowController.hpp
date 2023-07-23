#include <iostream>
#include "ByteSource.hpp"

class FileDataReader : public ByteSource
{
public:
    std::byte* read() override
    {

    }
};

class SocketDataReader : public ByteSource
{
public:
    std::byte* read() override
    {

    }
};

class Encryptor
{
public:
    std::byte* encrypt(std::byte* data)
    {

    }
};

class FileDataWriter
{
public:
    void write(std::byte* data)
    {

    }
};

class ByteSourceFactory
{
public:
    ByteSource* create() // 객체 생성 기능을 위한 오퍼레이션 정의
    {
        if(useFile())
            return new FileDataReader();
        else
            return new SocketDataReader();
    }

private:
    bool useFile()
    {
        std::string useFileVal("useFile");
        return useFileVal != "useFile";
    }

public:
    // 싱글턴 패턴 적용
    static ByteSourceFactory* getInstance()
    {
        static ByteSourceFactory* instance = new ByteSourceFactory();
        return instance;
    }

private:
    ByteSourceFactory()
    { }

};

class FlowController
{
private:
    bool useFile;

public:
    FlowController(bool useFile) : useFile(useFile)
    { }

    void process()
    {
        ByteSource* source = nullptr;
        if(useFile)
            source = new FileDataReader();
        else
            source = new SocketDataReader();

        std::byte* data = source->read();        

        Encryptor* encryptor = new Encryptor();
        std::byte* encryptedData = encryptor->encrypt(data);

        FileDataWriter* writer = new FileDataWriter();
        writer->write(encryptedData);

        delete source;
        delete encryptor;
        delete writer;
    }
};