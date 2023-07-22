#include <iostream>

class FileDataReader
{
public:
    std::byte read()
    {

    }

};

class FlowController
{
    void process()
    {
        FileDataReader* reader = new FileDataReader();
        std::byte data = reader->read();

    }
};