
class Channel;

class EventLoop
{
public:
    EventLoop();
    ~EventLoop();

private:
    void HandleRead();
    void Loop();
};