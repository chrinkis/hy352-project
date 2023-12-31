#include <values/null.h>

#include <cassert>

using namespace jsonlang::values;

Null::Null() {}

Null::Null(const Null& other) {}

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

bool Null::eq_op(const Value& other) const {
  return dynamic_cast<const Null*>(&other);
}

Null::Null(Value::Void) {
  assert(0);
}
