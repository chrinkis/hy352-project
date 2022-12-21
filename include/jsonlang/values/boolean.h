#pragma once

#include <jsonlang/values/value.h>

namespace jsonlang {
namespace values {

class Boolean : public Value {
  bool data;

 private:
  Boolean(const Boolean& other);

 public:
  Boolean(const bool _data);

  Boolean operator&&(const Boolean& other) const;
  Boolean operator||(const Boolean& other) const;
  Boolean operator!() const;
  bool operator==(const Boolean& other) const;
  bool operator!=(const Boolean& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Boolean* clone_to_heap() const;
  bool eq_op(const Value& other) const;

 public:
  Boolean(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
