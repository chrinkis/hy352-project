#pragma once

#include <jsonlang/values/value.h>

#include <map>
#include <memory>

#include <jsonlang/collections/pair.h>
#include <jsonlang/values/object/key.h>

namespace jsonlang {
namespace values {

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
  Object operator+(const Object& other) const;

 public:
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  Value* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;

 public:
  SmartPtr get(const std::string& key) const override;

 public:
  Object(Value::Void);
};

}  // namespace values
}  // namespace jsonlang

jsonlang::values::Object::Pair operator<<=(
    const jsonlang::values::Object::Key& key,
    const jsonlang::values::Value& value);
