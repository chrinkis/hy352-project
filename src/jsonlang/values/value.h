#pragma once

#include <string>

namespace jsonlang {
namespace values {

class Value {
 public:
  virtual int get_size() const = 0;
  virtual bool is_emtpy() const = 0;
  virtual bool has_key(const std::string& key) const = 0;
  virtual const char* get_type() const = 0;

  virtual operator std::string() const = 0;
};

}  // namespace values
}  // namespace jsonlang
