#include <values/value.h>
#include <cassert>

using namespace jsonlang::values;

Value::Sequence Value::operator,(const Value& other) {
  return (Sequence(), SharedPtr(this->clone_to_heap()),
          SharedPtr(other.clone_to_heap()));
}

bool Value::neq_op(const Value& other) const {
  return !this->eq_op(other);
}

bool Value::gt_op(const Value& other) const {
  assert(0);
}

bool Value::ge_op(const Value& other) const {
  assert(0);
}

bool Value::lt_op(const Value& other) const {
  assert(0);
}

bool Value::le_op(const Value& other) const {
  assert(0);
}

Value::Ptr Value::add_op(const Value& other) const {
  assert(0);
}

Value::Ptr Value::sub_op(const Value& other) const {
  assert(0);
}

Value::Ptr Value::mul_op(const Value& other) const {
  assert(0);
}

Value::Ptr Value::div_op(const Value& other) const {
  assert(0);
}

Value::Ptr Value::mod_op(const Value& other) const {
  assert(0);
}

bool Value::not_op() const {
  assert(0);
}

bool Value::and_op(const Value& other) const {
  assert(0);
}

bool Value::or_op(const Value& other) const {
  assert(0);
}

namespace jsonlang {
namespace values {

Value::Sequence& operator,(Value::Sequence& seq, const Value& val) {
  return (seq, Value::SharedPtr(val.clone_to_heap()));
}

}  // namespace values
}  // namespace jsonlang
