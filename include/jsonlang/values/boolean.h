#pragma once

#include <jsonlang/values/value.h>

namespace jsonlang {
namespace values {

class Boolean : public Value {
  bool data;

 public:  // TODO private
  Boolean(const Boolean& other);

 public:
  Boolean(const bool _data);

 public:
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  Boolean* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;

  bool not_op() const override;
  bool and_op(const Value& other) const override;
  bool or_op(const Value& other) const override;

 public:
  Boolean(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
