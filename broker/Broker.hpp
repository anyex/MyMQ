#include "Subscriber.hpp"
#include <string>
#include <map>
#include "Publisher.hpp"
#include <memory>
class Broker{
public:
    Broker(std::string name);

private:
    std::string name;
    Publisher m_publisher;
    std::map<int,std::shared_ptr<Subscriber>> m_subcribers;
};