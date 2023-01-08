#pragma once

#include <jsonlang/values/value.h>

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
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  Null* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;

 public:
  Null(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
