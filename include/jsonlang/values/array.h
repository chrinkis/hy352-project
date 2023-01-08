#pragma once

#include <jsonlang/values/value.h>

#include <jsonlang/collections/sequence.h>
#include <memory>
#include <vector>

namespace jsonlang {
namespace values {

class Array : public Value {
  std::vector<SharedPtr> data;

 private:
  Array(const Array& other);

 public:
  Array();

  Array operator[](const Value& single_data);
  // should be const
  Array operator[](Sequence& data_sequence);
  Value& operator[](const int index) const;
  Array operator+(const Array& other) const;
  bool operator==(const Array& other) const;
  bool operator!=(const Array& other) const;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Array* clone_to_heap() const;
  bool eq_op(const Value& other) const;
  Array* add_op(const Value& other) const override;

 public:
  Array(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
