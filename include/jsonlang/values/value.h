#pragma once

#include <jsonlang/collections/sequence.h>
#include <memory>
#include <string>

namespace jsonlang {
namespace values {

class Value {
 public:
  class Void {};
  using Ptr = Value*;
  using SharedPtr = std::shared_ptr<Value>;
  using Sequence = collections::Sequence<SharedPtr>;

 public:
  virtual ~Value() {}

 public:
  virtual int get_size() const = 0;
  virtual bool is_emtpy() const = 0;
  virtual bool has_key(const std::string& key) const = 0;
  virtual const char* get_type() const = 0;

  virtual operator std::string() const = 0;

  virtual Value* clone_to_heap() const = 0;
  virtual Sequence operator,(const Value& other) final;

 public:  // TODO or protected ?
  virtual bool eq_op(const Value& other) const = 0;
  virtual bool neq_op(const Value& other) const;

  virtual bool gt_op(const Value& other) const;
  virtual bool ge_op(const Value& other) const;
  virtual bool lt_op(const Value& other) const;
  virtual bool le_op(const Value& other) const;

  virtual Ptr add_op(const Value& other) const;
  virtual Ptr sub_op(const Value& other) const;
  virtual Ptr mul_op(const Value& other) const;
  virtual Ptr div_op(const Value& other) const;
  virtual Ptr mod_op(const Value& other) const;

  virtual bool not_op() const;
  virtual bool and_op(const Value& other) const;
  virtual bool or_op(const Value& other) const;
};

Value::Sequence& operator,(Value::Sequence& seq, const Value& val);

}  // namespace values
}  // namespace jsonlang
