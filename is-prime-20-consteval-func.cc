#include <iostream>
#include <array>

template<int v>
consteval std::array<int, v + 1> sieve() {
  std::array<int, v + 1> arr = {};
  for(long long i = 2; i <= v; i++) {
    if(arr[i]) {
      continue;
    }
    for(long long j = i * i; j <= v; j+= i) {
      arr[j] = 1;
    }
  }
  return arr;
}

int main() {
  auto sieve_array = sieve<12345>();
  std::cout << 7 << " : " << sieve_array[7] << std::endl;
  std::cout << 2000 << " : " << sieve_array[2000]<< std::endl;
  std::cout << 2003 << " : " << sieve_array[2003]<< std::endl;

  size_t i = 0;
  std::cin >> i;
  std::cout << sieve_array[i] << std::endl;

  return 0;
}
