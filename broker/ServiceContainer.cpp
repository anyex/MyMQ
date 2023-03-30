#include<unordered_map>
#include<memory>
template <typename T> 
class ServiceContainer{
public:
    static void Init();
    static void Register(){
        services[typeid(T).name()] = std::make_shared<T>();
    };
private:
    std::unordered_map<std::string,std::shared_ptr<T>> services;
};