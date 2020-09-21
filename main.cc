#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

#include "utility.h"

// A demo for creating two threads
// Run this using one of the following methods:
//  1. With bazel: bazel run src/main:main
//  2. With plain g++: g++ -std=c++17 -lpthread GitHub/Distributed-Computing-Project-1/main.cc  -I ./

int main() {
  const int number_of_threads = 10;
  uint64_t number_of_elements = 10 * 10 * 10;
  uint64_t step = number_of_elements / number_of_threads;
  std::vector<std::future<uint64_t>> tasks;
  std::vector<uint64_t> partial_sums(number_of_threads);

  for (uint64_t i = 0; i < number_of_threads; i++) {
    tasks.push_back(std::async([i, step] {
      uint64_t r = 0;
      for (uint64_t j = i * step; j < (i + 1) * step; j++) {
        r += j;
      }
      return r;
    }));
  }
  uint64_t max = 0;
  uint64_t total = 0;
  for (auto &t : tasks) {
    //std::cout << "total: " << total << std::endl;
    std::cout << "total: " << t.get() << std::endl;
    total += t.get();
  }
  //std::cout << "max: " << max << std::endl;
  //std::cout << "total: " << total << std::endl;

  return 0;
}