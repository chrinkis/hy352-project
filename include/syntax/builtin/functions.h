#pragma once

#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF(val_or_var) size_of(val_or_var)

#define IS_EMPTY  // TODO

#define HAS_KEY  // TODO

#define TYPE_OF  // TODO

int size_of(const Value& value) {
  return value.get_size();
}

int size_of(const Variable& variable) {
  return variable.get_value().get_size();
}
