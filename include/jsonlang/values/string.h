#pragma once

#include <jsonlang/values/value.h>

#include <cstddef>
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
  bool is_equal_to(const Value& other) const;

 public:
  String(std::nullptr_t null);
};

}  // namespace values
}  // namespace jsonlang
