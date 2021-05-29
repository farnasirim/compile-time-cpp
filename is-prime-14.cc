#include <iostream>

template<int v>
struct IsPrime;

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
  // compile-time-cpp/is-prime-14.cc: In instantiation of ‘const bool HasDivisorGE<7, 7, void>::value’:
  // compile-time-cpp/is-prime-14.cc:9:46:   recursively required from ‘const bool HasDivisorGE<7, 3, void>::value’
  // compile-time-cpp/is-prime-14.cc:9:46:   required from ‘const bool HasDivisorGE<7, 2, void>::value’
  // compile-time-cpp/is-prime-14.cc:14:50:   required from ‘const bool IsPrime<7>::value’
  // compile-time-cpp/is-prime-14.cc:18:42:   required from here
  // compile-time-cpp/is-prime-14.cc:9:46: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
  //     9 |     ((v % d == 0) || HasDivisorGE<v, d + 1>::value);
  //                                                      ^~~~~
  std::cout << 7 << " : " << IsPrime<7>::value << std::endl;

  // fatal error: template instantiation depth exceeds maximum of 900
  // (use ‘-ftemplate-depth=’ to increase the maximum)
  // std::cout << 2000 << " : " << IsPrime<2000>::value << std::endl;
  return 0;
}
