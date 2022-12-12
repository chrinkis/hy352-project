#pragma once

#include "../value.h"

namespace jsonlang {
namespace values {
namespace null {

class Null : public Value {
 public:
  bool operator==(const Null& other) const;
  bool operator!=(const Null& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;
};

}  // namespace null
}  // namespace values
}  // namespace jsonlang
