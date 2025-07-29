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

class MachineLearning // 54:08 / 2:31:06 Machine Learning in C (Episode1)
{
public:
	void Run()
	{
	    float w = getRandomNumber(1.0f, 10.0f);
		float b = getRandomNumber(1.0f, 5.0f);
		const float eps = 1e-3;
		const float rate = 1e-3;

		std::println("{}", cost(w,b));

		const uint32_t repeat = 500;
		for (size_t i = 0; i < repeat; ++i)
		{
			const float c = cost(w, b);
			const float dw = (cost(w + eps, b) - c) / eps;
			const float db = (cost(w, b + eps) - c) / eps;
			w -= rate * dw;
			b -= rate * db;
			std::println("cost: {:.5f}, w: {:.5f}, b: {:.5f}", cost(w,b), w, b);
		}
		std::println("w: {:.5f}, b: {:.5f}", w, b);


	}

private:
	constexpr static float cost(const float w, const float b) noexcept
	{
		float result = 0.0f;
		for (const auto& point : m_train)
		{
			const float x = point[0];
			const float y = x * w + b;

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