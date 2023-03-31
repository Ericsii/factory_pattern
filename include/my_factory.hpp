#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include <base_interface.hpp>

namespace factory {

class MyFactory {
public:
  static std::shared_ptr<BaseInterface> create(const std::string &key) {
    auto it = getMap().find(key);
    if (it == getMap().end()) {
      return nullptr;
    }
    return it->second();
  }

  template <typename T> static bool register_class(const std::string &key) {
    if (getMap().find(key) != getMap().end()) {
      return false;
    }
    getMap()[key] = []() -> std::shared_ptr<BaseInterface> {
      return std::make_shared<T>();
    };
    return true;
  }

  static void printRegisteredClasses();

private:
  static std::unordered_map<std::string,
                            std::function<std::shared_ptr<BaseInterface>()>> &
  getMap();
};
} // namespace factory