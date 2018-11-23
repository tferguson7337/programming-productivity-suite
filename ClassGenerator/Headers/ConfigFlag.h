#pragma once

#include <type_traits>

#include <Types.h>

enum class ConfigFlag : uint64
{
    NONE = 0,

    Getters = 1 << 0,
    Setters = 1 << 1,
    MoveSemantics = 1 << 2,

    MAX,
    BEGIN = Getters
};

// Bitwise Operators
ConfigFlag operator~(const ConfigFlag& rhs) noexcept;
ConfigFlag operator|(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;
ConfigFlag operator&(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;
ConfigFlag operator^(const ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;

// Bitwise Assignment Operators
ConfigFlag& operator|=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;
ConfigFlag& operator&=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;
ConfigFlag& operator^=(ConfigFlag& lhs, const ConfigFlag& rhs) noexcept;

// Shift Operators
ConfigFlag operator<<(const ConfigFlag& lhs, const size_t n) noexcept;
ConfigFlag operator>>(const ConfigFlag& lhs, const size_t n) noexcept;

// Shift Assignment Operators
ConfigFlag& operator<<=(ConfigFlag& lhs, const size_t n) noexcept;
ConfigFlag& operator>>=(ConfigFlag& lhs, const size_t n) noexcept;
