#pragma once

#include <base_interface.hpp>
#include <my_factory.hpp>

#define REGISTER_CLASS(key, class_name)                                        \
  static bool class_name##_registered =                                        \
      factory::MyFactory::register_class<class_name>(key);