#pragma once

#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF  // TODO

#define IS_EMPTY  // TODO

#define HAS_KEY  // TODO

#define TYPE_OF(val_or_var) type_of(val_or_var)

std::string type_of(const Value& value) {
  return value.get_type();
}

std::string type_of(const Variable& variable) {
  return variable.get_value().get_type();
}
