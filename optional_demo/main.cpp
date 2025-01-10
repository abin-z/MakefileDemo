#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <optional>
#include <bitset>

struct Object
{
    int *ptr;
    int n;
};

int main()
{
    fmt::println("----------bitset----------");
    std::bitset<8> bset(0b11001100);
    fmt::println("Bitset as ulong: {}", bset.to_ulong());
    fmt::println("Bitset as string: {}", bset.to_string());
    bset.set(0); // 从右往左,将第0位置为1 
    fmt::println("bset.set(0) after: {}", bset.to_string());
    bset.reset(7); // 从右往左,将第7位置为0 
    fmt::println("bset.reset(7) after: {}", bset.to_string());

    fmt::println("----------optional----------");
    // Case 1: Optional without value (default)
    std::optional<Object> o1;
    if (o1.has_value())
    {
        fmt::println("o1 has value");
    }
    else
    {
        fmt::println("o1 doesn't have value");
    }

    // Case 2: Optional with value
    std::optional<Object> o2 = std::nullopt;
    if (true) // some condition
    {        
        Object o = Object{new int(10), 5};                       
        o2 = o; // assign value to o2
    }

    if (o2)
    {
        fmt::println("o2 has value");
        fmt::println("*(o2->ptr) = {}, o2->n = {}", *(o2->ptr), o2->n);
    }
    else
    {
        fmt::println("o2 doesn't have value");
    }

    // 使用 value_or 来提供默认值
    std::optional<int> opt;
    fmt::println("opt value = {}", opt.value_or(999)); // 输出默认值999
}
