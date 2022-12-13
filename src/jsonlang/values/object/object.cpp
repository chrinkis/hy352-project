#include "object.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace jsonlang::values;
using namespace jsonlang::values::object;

Object::Object(std::initializer_list<Pair> pairs) {
  for (Object::Pair pair : pairs) {
    Object::Key key = pair.get_first();
    Object::ValuePtr value_ptr = pair.get_second();

    this->data[key] = value_ptr;
  }
}

Object::Object(const Object& other) {
  for (auto pair : other.data) {
    Object::Key key = pair.first;
    Object::ValuePtr value_ptr = pair.second;

    this->data[key] = Object::ValuePtr(value_ptr->clone_to_heap());
  }
}

Value& Object::operator[](const std::string& key) {
  auto resoult = this->data[Object::Key(key)];

  assert(resoult);

  return *resoult;
}

Object Object::operator+(const Object& other) const {
  Object first = Object(*this);
  Object second = Object(other);

  for (auto pair : second.data) {
    first.data[pair.first] = pair.second;
  }

  return first;
}

int Object::get_size() const {
  return this->data.size();
}

bool Object::is_emtpy() const {
  return this->data.empty();
}

bool Object::has_key(const std::string& key) const {
  auto search = this->data.find(Object::Key(key));

  return search != this->data.end();
}

const char* Object::get_type() const {
  return "object";
}

Object::operator std::string() const {
  std::string resoult = "{";

  for (auto pair : this->data) {
    resoult += pair.first.get_key();
    resoult += ": ";
    resoult += std::string(*pair.second);
    resoult += ", ";
  }

  resoult += "}";

  return resoult;
}

Value* Object::clone_to_heap() const {
  return new Object(*this);
}

Object::Object(std::nullptr_t null) {
  assert(0);
}

Object::Pair operator<<=(const Object::Key& key, const Value& value) {
  return Object::Pair(key, Object::ValuePtr(value.clone_to_heap()));
}
