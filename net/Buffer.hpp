#include <algorithm>
#include <vector>
#include <string>
#define BUFFER_SIZE 1024
#define CHEAP_PREPEND 8


class Buffer{
public:
   Buffer(std::string &content);
   void Encode();
   void Decode();
private:
   void WriteRawVarint32(std::string &out,int value);
   int ComputeRawVarint32Size(int value);
   int ReadRawVarint32(std::string &buffer);
};