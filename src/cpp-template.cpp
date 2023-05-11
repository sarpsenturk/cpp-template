#include "cpp-template.h"

#include <fmt/format.h>

namespace cpp_template
{
    auto hello_world() -> std::string
    {
        return fmt::format("Hello {}", "cpp_template");
    }
} // namespace cpp_template
