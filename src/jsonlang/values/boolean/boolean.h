#pragma once

#include "../value.h"

namespace jsonlang {
namespace values {
namespace boolean {

class Boolean : public Value {
  bool data;

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
};

}  // namespace boolean
}  // namespace values
}  // namespace jsonlang
