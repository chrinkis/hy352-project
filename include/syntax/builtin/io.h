#pragma once

#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>
#include <iostream>

#define PRINT \
  ;           \
  Printer(),

struct Printer {
  const Printer& operator,(const jsonlang::values::Value& value) const {
    std::cout << value << std::endl;

    return *this;
  }

  const Printer& operator,(const jsonlang::variable::Variable& variable) const {
    std::cout << variable << std::endl;

    return *this;
  }
};
