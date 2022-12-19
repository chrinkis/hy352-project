#pragma once

#include <jsonlang/values/value.h>
#include <cstddef>

namespace jsonlang {
namespace values {

class Null : public Value {
 private:
  Null(const Null& other);

 public:
  Null();

  bool operator==(const Null& other) const;
  bool operator!=(const Null& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Null* clone_to_heap() const;
  bool is_equal_to(const Value& other) const;

 public:
  Null(std::nullptr_t null);
};

}  // namespace values
}  // namespace jsonlang
