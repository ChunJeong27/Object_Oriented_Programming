#include <iostream>

class ByteSource
{
public:
    virtual std::byte* read() = 0;

};