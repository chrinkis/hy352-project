#pragma once

#include "../value.h"

#include <sequence.h>
#include <memory>
#include <vector>

collections::Sequence<std::shared_ptr<jsonlang::values::Value> >& operator,(
    collections::Sequence<std::shared_ptr<jsonlang::values::Value> >& seq,
    const jsonlang::values::Value& val);

namespace jsonlang {
namespace values {
namespace array {

class Array : public Value {
  std::vector<std::shared_ptr<Value> > data;

 private:
  Array(const Array& other);

 public:
  Array();

  Array operator[](const Value& single_data);
  // should be const
  Array operator[](
      collections::Sequence<std::shared_ptr<Value> >& data_sequence);
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

 public:
  Array(std::nullptr_t null);
};

}  // namespace array
}  // namespace values
}  // namespace jsonlang
