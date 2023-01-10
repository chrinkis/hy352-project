#pragma once

#include <jsonlang/values/value.h>

#include <jsonlang/collections/sequence.h>
#include <memory>
#include <vector>

namespace jsonlang {
namespace values {

class Array : public Value {
  std::vector<SharedPtr> data;

 public:  // TODO private
  Array(const Array& other);

 public:
  Array();

  Array operator[](const Value& single_data);
  Array operator[](const Sequence& data_sequence);
  Value& operator[](const int index) const;

  void append(const Value& value) override;
  void set_at(const int index, const Value& value) override;
  void remove(const int index) override;
  void clear() override;

 public:
  int get_size() const override;
  bool is_emtpy() const override;
  bool has_key(const std::string& key) const override;
  const char* get_type() const override;

  operator std::string() const override;

  Array* clone_to_heap() const override;
  bool eq_op(const Value& other) const override;
  Array* add_op(const Value& other) const override;

 public:
  SharedPtr get(int i) const override;

 public:
  Array(Value::Void);
};

}  // namespace values
}  // namespace jsonlang
