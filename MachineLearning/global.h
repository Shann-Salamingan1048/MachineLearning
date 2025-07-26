#pragma once
#include <string>
#include <array>
#include <print>
#include <random>
#include <type_traits>
#include <vector>
#include <iostream>
#include <concepts>

// Common type traits
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

// Base template for zero initialization
template<Numeric Number>
constexpr Number zero_init() 
{
    if constexpr (std::is_integral_v<Number>) return 0;
    else return Number(0.0);
}