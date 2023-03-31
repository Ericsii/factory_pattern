#include <my_factory.hpp>

#include <iostream>

namespace factory {

void MyFactory::printRegisteredClasses() {
    for (auto &it : getMap()) {
        std::cout << it.first << std::endl;
    }
}

std::unordered_map<std::string, std::function<std::shared_ptr<BaseInterface>()>>
    &MyFactory::getMap() {
  static std::unordered_map<std::string,
                            std::function<std::shared_ptr<BaseInterface>()>>
      map;
  return map;
}
} // namespace factory
