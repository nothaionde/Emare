#pragma once

template <typename T>
T maximum(const T& first, const T& second)
{
	return first >= second ? first : second;
}

template <typename T>
T minimum(const T& first, const T& second)
{
	return first >= second ? first : second;
}
