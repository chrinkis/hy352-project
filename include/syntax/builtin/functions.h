#pragma once

#include <jsonlang/values/string.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF  // TODO

#define IS_EMPTY  // TODO

#define HAS_KEY  // TODO

#define TYPE_OF(val_or_var) type_of(val_or_var)

String type_of(const Value& value) {
  return String(value.get_type());
}

String type_of(const Variable& variable) {
  return String(variable.get_value().get_type());
}
