#include <ConfigFlag.h>

using CFT = std::underlying_type_t<ConfigFlag>;

/// Bitwise Operators \\\

// Bitwise Not
ConfigFlag operator~(const ConfigFlag& rhs) noexcept
{
    return static_cast<ConfigFlag>(~static_cast<CFT>(rhs));
}

// Bitwise Or
ConfigFlag operator|(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return static_cast<ConfigFlag>(static_cast<CFT>(lhs) | static_cast<CFT>(rhs));
}

// Bitwise And
ConfigFlag operator&(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return static_cast<ConfigFlag>(static_cast<CFT>(lhs) & static_cast<CFT>(rhs));
}

// Bitwise Xor
ConfigFlag operator^(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return static_cast<ConfigFlag>(static_cast<CFT>(lhs) ^ static_cast<CFT>(rhs));
}

/// Bitwise Assignment Operators \\\
    
// Bitwise Or
ConfigFlag& operator|=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return lhs = lhs | rhs;
}

// Bitwise And
ConfigFlag& operator&=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return lhs = lhs & rhs;
}

// Bitwise Xor
ConfigFlag& operator^=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept
{
    return lhs = lhs ^ rhs;
}

/// Shift Operators \\\

// Left Shift
ConfigFlag operator<<(const ConfigFlag& lhs, const size_t n) noexcept
{
    return static_cast<ConfigFlag>(static_cast<CFT>(lhs) << n);
}

// Right Shift
ConfigFlag operator>>(const ConfigFlag& lhs, const size_t n) noexcept
{
    return static_cast<ConfigFlag>(static_cast<CFT>(lhs) >> n);
}

/// Shift Assignment Operators \\\

// Left Shift
ConfigFlag& operator<<=(ConfigFlag& lhs, const size_t n) noexcept
{
    return lhs = lhs << n;
}

// Right Shift
ConfigFlag& operator>>=(ConfigFlag& lhs, const size_t n) noexcept
{
    return lhs = lhs >> n;
}
