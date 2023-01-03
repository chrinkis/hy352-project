#pragma once

#include <jsonlang/values/value.h>

#include <jsonlang/collections/sequence.h>
#include <memory>
#include <vector>

namespace jsonlang {
namespace values {

class Array : public Value {
 public:
  using ValuePtr = std::shared_ptr<Value>;
  using ValuePtrSequence = collections::Sequence<ValuePtr>;

 private:
  std::vector<ValuePtr> data;

 private:
  Array(const Array& other);

 public:
  Array();

  Array operator[](const Value& single_data);
  // should be const
  Array operator[](ValuePtrSequence& data_sequence);
  Value& operator[](const int index) const;
  Array operator+(const Array& other) const;
  bool operator==(const Array& other) const;
  bool operator!=(const Array& other) const;

  void append(const Value& value) override;
  void remove(const std::string index) override;

 public:
  int get_size() const;
  bool is_emtpy() const;
  bool has_key(const std::string& key) const;
  const char* get_type() const;

  operator std::string() const;

  Array* clone_to_heap() const;
  bool eq_op(const Value& other) const;

 public:
  SmartPtr get(int i) const override;

 public:
  Array(Value::Void);
};

}  // namespace values
}  // namespace jsonlang

jsonlang::values::Array::ValuePtrSequence& operator,(
    jsonlang::values::Array::ValuePtrSequence& seq,
    const jsonlang::values::Value& val);
