#pragma once

#include "../value.h"

namespace jsonlang {
namespace values {
namespace null {

class Null : public Value {
 private:
  Null(const Null& other);

 public:
  bool operator==(const Null& other) const;
  bool operator!=(const Null& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Null* clone_to_heap() const;
};

}  // namespace null
}  // namespace values
}  // namespace jsonlang
