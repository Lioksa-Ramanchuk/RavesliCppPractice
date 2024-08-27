#ifndef RAVESLI_CPP_PRACTICE_UTILS_TYPE_ALIASES_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_TYPE_ALIASES_HPP

#include <cstdint>
#include <cstddef>  

namespace ravesli_cpp_practice::utils::type_aliases {

using schar = signed char;
using uchar = unsigned char;

using char16 = char16_t;
using char32 = char32_t;

using wchar = wchar_t;

using sshort = signed short;
using ushort = unsigned short;

using sint = signed int;
using uint = unsigned int;

using slong = signed long;
using ulong = unsigned long;

using llong = long long;
using sllong = signed long long;
using ullong = unsigned long long;

using int8 = std::int8_t;
using uint8 = std::uint8_t;

using int16 = std::int16_t;
using uint16 = std::uint16_t;

using int32 = std::int32_t;
using uint32 = std::uint32_t;

using int64 = std::int64_t;
using uint64 = std::uint64_t;

using ldouble = long double;

using sz = std::size_t;
using ptrdiff = std::ptrdiff_t;

}  // namespace ravesli_cpp_practice::utils::type_aliases

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_TYPE_ALIASES_HPP