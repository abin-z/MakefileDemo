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
    fmt::println("hello optional.");
    std::bitset<1> bset;
    fmt::println("std::bitset<1> size = {}", sizeof(bset));

    // Case 1: Optional without value (default)
    std::optional<Object> o1;
    if (o1)
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
    }
    else
    {
        fmt::println("o2 doesn't have value");
    }
}
