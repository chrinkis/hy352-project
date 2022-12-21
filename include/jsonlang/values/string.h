#pragma once

#include <jsonlang/values/value.h>

#include <string>

namespace jsonlang {
namespace values {

class String : public Value {
  std::string data;

 private:
  String(const String& other);

 public:
  String(const std::string& _data);

  String operator+(const String& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  String* clone_to_heap() const;
  bool eq_op(const Value& other) const;

 public:
  String(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
