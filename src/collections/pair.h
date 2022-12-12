#pragma once

#include <memory>

namespace collections {

template <typename F, typename S>
class Pair {
  std::shared_ptr<F> first;
  std::shared_ptr<S> second;

 public:
  Pair(const F& _first, const S& _second)
      : first(_first.clone_to_heap()), second(_second.clone_to_heap()) {}

  std::shared_ptr<F> get_first() const { return this->first; }
  std::shared_ptr<S> get_second() const { return this->second; }
};

}  // namespace collections
