#include "string.h"

using namespace jsonlang::values::string;

String::String(const std::string& _data) : data(_data) {}

String::String(const String& other) : data(other.data) {}

String String::operator+(const String& other) const {
  return String(this->data + other.data);
}

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
  return new String(*(this));
}
