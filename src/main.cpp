#include <my_factory.hpp>
// #include <register_macro.hpp>

#include <iostream>

// class DerivedClass;

// REGISTER_CLASS("DerivedClass", DerivedClass)

int main() {
  auto obj = factory::MyFactory::create("DerivedClass");
  if (!obj) {
    std::cout << "Failed to create object" << std::endl;
    return 1;
  }
  obj->doSomething();
  factory::MyFactory::printRegisteredClasses();
  return 0;
}