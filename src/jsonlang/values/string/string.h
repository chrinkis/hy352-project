#pragma once

#include "../value.h"

#include <string>

namespace jsonlang {
namespace values {
namespace string {

class String : public Value {
  std::string data;

 public:
  String(const std::string& _data);
  String(const String& other);

  String operator+(const String& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  String* clone_to_heap() const;
};

}  // namespace string
}  // namespace values
}  // namespace jsonlang
