#include "Subscriber.hpp"
class Publisher{

public:
    Publisher();
    void Subscribe(int tag,std::shared_ptr<Subscriber> subscriber){
        m_subscribers[tag] = subscriber;
    }
    void OnRequet();
    void OnMessage();
private:
    std::map<int,std::shared_ptr<Subscriber>> m_subscribers;
};