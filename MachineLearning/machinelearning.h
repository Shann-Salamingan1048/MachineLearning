#pragma once
#include "global.h"
template<typename T>
T getRandomNumber(T min, T max)
{
	thread_local std::mt19937 gen(std::random_device{}());

	if constexpr (std::is_integral_v<T>) {
		return std::uniform_int_distribution<T>(min, max)(gen);
	}
	else {
		return std::uniform_real_distribution<T>(min, max)(gen);
	}
}

class MachineLearning // 33:44 / 2:31:06 Machine Learning in C (Episode1)
{
public:
	void Run()
	{
		const float w = getRandomNumber(1.0f, 10.0f);
		
		const float eps = 1e-3;
		std::println("cost: {}", cost(w));
		std::println("cost: {}", cost(w - eps));
		std::println("cost: {}", cost(w - eps * 2));
	}

private:
	constexpr static float cost(const float w) noexcept
	{
		float result = 0.0f;
		for (const auto& point : m_train)
		{
			const float x = point[0];
			const float y = x * w;

			const float d = y - point[1];
			result += d * d;

		}
		result /= static_cast<float>(m_train.size());
		return result;
	}
private:
	constexpr static std::array<std::array<float, 2>,5> m_train =
	{
		{
			{0,0},
			{1,2},
			{2,4},
			{3,6},
			{4,8},
		}

	};
};