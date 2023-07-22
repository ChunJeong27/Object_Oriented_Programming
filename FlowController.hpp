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

class FlowController
{
public:
    void process()
    {
        FileDataReader* reader = new FileDataReader();
        std::byte* data = reader->read();

        Encryptor* encryptor = new Encryptor();
        std::byte* encryptedData = encryptor->encrypt(data);

        FileDataWriter* writer = new FileDataWriter();
        writer->write(encryptedData);

        delete reader;
        delete encryptor;
        delete writer;
    }
};