#include <values/string.h>

#include <cassert>

using namespace jsonlang::values;

String::String(const std::string& _data) : data(_data) {}

String::String(const String& other) : data(other.data) {}

int String::get_size() const {
  return 1;
}

bool String::is_emtpy() const {
  return false;
}

bool String::has_key(const std::string& key) const {
  return false;
}

const char* String::get_type() const {
  return "string";
}

String::operator std::string() const {
  return this->data;
}

String* String::clone_to_heap() const {
  return new String(*this);
}

bool String::eq_op(const Value& other) const {
  const String* other_string = dynamic_cast<const String*>(&other);

  if (!other_string) {
    throw errors::UnsupportedOperation();
  }

  return this->data == other_string->data;
}

String* String::add_op(const Value& other) const {
  const String* other_string = dynamic_cast<const String*>(&other);

  if (!other_string) {
    throw errors::UnsupportedOperation();
  }

  String* result = this->clone_to_heap();
  result->data += other_string->data;

  return result;
}

String::String(Value::Void) {
  assert(0);
}
