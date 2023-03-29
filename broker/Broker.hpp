#include "Subscriber.hpp"
#include <string>
#include <map>
#include "Publisher.hpp"
#include <memory>
class Broker{
public:
    Broker(std::string name);
    void OnMessage(std::shared_ptr<Message> msg);
    void OnRequet(std::shared_ptr<Message> msg);
    void OnSubScribe(std::shared_ptr<Message> msg);
    void OnUnSubScribe(std::shared_ptr<Message> msg);
    void OnEvent(std::shared_ptr<Message> msg);
private:
    std::string name;
    Publisher m_publisher;
    std::map<int,std::shared_ptr<Subscriber>> m_subcribers;
};