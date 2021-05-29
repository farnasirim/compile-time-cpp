#include <iostream>

constexpr bool is_prime(int v) {
  for (int i = 2; i < v; i++) {
    if (v % i == 0) {
      return false;
    }
  }
  return true;
}

template<int v>
struct IsPrime {
  static constexpr bool value = is_prime(v);
};

int main() {
  std::cout << 7 << " : " << IsPrime<7>::value << std::endl;
  std::cout << 2000 << " : " << IsPrime<2000>::value << std::endl;
  std::cout << 2003 << " : " << IsPrime<2003>::value << std::endl;

  return 0;
}
