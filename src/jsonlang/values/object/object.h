#pragma once

#include "../value.h"

#include <cstddef>
#include <map>
#include <memory>

#include "key.h"
#include "pair.h"

namespace jsonlang {
namespace values {
namespace object {

class Object : public Value {
 public:
  using Key = jsonlang::values::object::Key;
  using ValuePtr = std::shared_ptr<Value>;
  using Pair = collections::Pair<Key, ValuePtr>;

 private:
  std::map<Key, ValuePtr> data;

 private:
  Object(const Object& other);

 public:
  Object(std::initializer_list<Pair>);

  Value& operator[](const std::string& key);

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Value* clone_to_heap() const;

 public:
  Object(std::nullptr_t null);
};

}  // namespace object
}  // namespace values
}  // namespace jsonlang

jsonlang::values::object::Object::Pair operator<<=(
    const jsonlang::values::object::Object::Key& key,
    const jsonlang::values::Value& value);
