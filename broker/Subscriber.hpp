#include "../codec/stream.hpp"
class Subscriber{
public:
    virtual ~Subscriber(){};
    virtual void OnMessage(const Message &message) = 0;
};

