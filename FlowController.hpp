#include <iostream>

class FileDataReader
{
public:
    std::byte* read()
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

class SocketDataReader
{
public:
    std::byte* read()
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
        std::byte* data = nullptr;
        if(useFile)
        {
            FileDataReader* fileReader = new FileDataReader();
            data = fileReader->read();

            delete fileReader;
        }
        else
        {
            SocketDataReader* socketReader = new SocketDataReader();
            data = socketReader->read();

            delete socketReader;
        }

        Encryptor* encryptor = new Encryptor();
        std::byte* encryptedData = encryptor->encrypt(data);

        FileDataWriter* writer = new FileDataWriter();
        writer->write(encryptedData);

        delete encryptor;
        delete writer;
    }
};