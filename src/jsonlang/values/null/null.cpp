#include "null.h"

#include <cassert>

using namespace jsonlang::values::null;

Null::Null() {}

Null::Null(const Null& other) {}

bool Null::operator==(const Null& other) const {
  return true;
}

bool Null::operator!=(const Null& other) const {
  return false;
}

int Null::get_size() const {
  return 1;
}

bool Null::is_emtpy() const {
  return false;
}

bool Null::has_key(const std::string& key) const {
  return false;
}

const char* Null::get_type() const {
  return "null";
}

Null::operator std::string() const {
  return "Null";
}

Null* Null::clone_to_heap() const {
  return new Null(*this);
}

Null::Null(std::nullptr_t null) {
  assert(0);
}
