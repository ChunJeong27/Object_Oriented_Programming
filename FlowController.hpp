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