#include <iostream>

template<int v, int d>
struct HasDivisorGE {
  static constexpr bool value = []{
    if constexpr (d >= v) {
      return false;
    } else if constexpr (v % d == 0) {
      return true;
    } else {
      return HasDivisorGE<v, d + 1>::value;
    }
  }();
};

template<int v>
struct IsPrime {
  static const bool value = !HasDivisorGE<v, 2>::value;
};

int main() {
  std::cout << 7 << " : " << IsPrime<7>::value << std::endl;
  std::cout << 2000 << " : " << IsPrime<2000>::value << std::endl;

  // fatal error: template instantiation depth exceeds maximum of 900
  // (use ‘-ftemplate-depth=’ to increase the maximum)
  // std::cout << 2003 << " : " << IsPrime<2003>::value << std::endl;

  return 0;
}
