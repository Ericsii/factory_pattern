#pragma once

namespace factory {

class BaseInterface {
public:
    virtual ~BaseInterface() = default;
    virtual void doSomething() = 0;
};
} // namespace factory
