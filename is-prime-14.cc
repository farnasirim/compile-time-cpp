#include <iostream>

template<int v>
struct IsPrime;

template<int v, int d, typename = std::enable_if_t<(d < v)>>
struct HasDivisorGE {
  static const bool value = (d < v) &&
    ((v % d == 0) || HasDivisorGE<v, d + 1>::value);
};

template<int v>
struct IsPrime {
  static const bool value = !HasDivisorGE<v, 2>::value;
};

int main() {
  std::cout << 7 << " : " << IsPrime<7>::value << std::endl;

  // fatal error: template instantiation depth exceeds maximum of 900
  // (use ‘-ftemplate-depth=’ to increase the maximum)
  // std::cout << 2000 << " : " << IsPrime<2000>::value << std::endl;
  return 0;
}
