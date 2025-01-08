#define FMT_HEADER_ONLY
#include <fmt/core.h> 
#include <iostream>
#include <thread>
#include <functional> // std::hash

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  fmt::println("hello makefile");

  std::hash<std::thread::id> hasher;
  std::size_t thread_id = hasher(std::this_thread::get_id());
  fmt::println("current thread id = {:#x}", thread_id);
  
  return 0;
}