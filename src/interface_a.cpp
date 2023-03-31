#include <base_interface.hpp>

#include <iostream>

class DerivedClass : public factory::BaseInterface {
public:
    void doSomething() override { std::cout << "Hello World!" << std::endl; }
};

#include <register_macro.hpp>

REGISTER_CLASS("DerivedClass", DerivedClass)