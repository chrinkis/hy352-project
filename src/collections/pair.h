#pragma once

namespace collections {

template <typename F, typename S>
class Pair {
  F first;
  S second;

 public:
  Pair(const F& _first, const S& _second) : first(_first), second(_second) {}

  F get_first() const { return this->first; }
  S get_second() const { return this->second; }
};

}  // namespace collections
