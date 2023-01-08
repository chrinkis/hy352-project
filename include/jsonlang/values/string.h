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
  bool operator==(const String& other) const;

 public:
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  String* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;
  String* add_op(const Value& other) const override;

 public:
  String(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
