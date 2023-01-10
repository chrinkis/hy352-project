#pragma once

#include <jsonlang/values/number.h>
#include <jsonlang/values/value.h>
#include <jsonlang/variable/variable.h>

using namespace jsonlang::values;
using namespace jsonlang::variable;

#define SIZE_OF(val_or_var) size_of(val_or_var)

#define IS_EMPTY  // TODO

#define HAS_KEY  // TODO

#define TYPE_OF  // TODO

Number size_of(const Value& value) {
  return Number(value.get_size());
}

Number size_of(const Variable& variable) {
  return Number(variable.get_value().get_size());
}
