#pragma once

#include <jsonlang/values/value.h>
#include <string>

namespace jsonlang {
namespace variable {

class Variable;

class Appender {
  Variable& variable;

 public:
  Appender(Variable& _variable);

 public:
  Appender& operator,(const values::Value& value);
};

}  // namespace variable
}  // namespace jsonlang
