#include <iostream>

template<int v, int d, typename = std::enable_if_t<(d <= v)>>
struct HasDivisorGE {
  static const bool value = (d < v) &&
    ((v % d == 0) || HasDivisorGE<v, d + 1>::value);
};

template<int v>
struct IsPrime {
  static const bool value = !HasDivisorGE<v, 2>::value;
};

int main() {
  // In instantiation of ‘const bool HasDivisorGE<7, 7, void>::value’:
  //   recursively required from ‘const bool HasDivisorGE<7, 3, void>::value’
  //   required from ‘const bool HasDivisorGE<7, 2, void>::value’
  //   required from ‘const bool IsPrime<7>::value’
  //   required from here
  // error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
  //       |     ((v % d == 0) || HasDivisorGE<v, d + 1>::value);
  //                                                      ^~~~~
  std::cout << 7 << " : " << IsPrime<7>::value << std::endl;

  // fatal error: template instantiation depth exceeds maximum of 900
  // (use ‘-ftemplate-depth=’ to increase the maximum)
  std::cout << 2000 << " : " << IsPrime<2000>::value << std::endl;
  return 0;
}
