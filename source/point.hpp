#include <math.h>
#include <iostream>

using namespace std;

template<typename T1,typename T2>
std::array<T1,3> vector_add(std::array<T1,3> i1,std::array<T2,3> i2)
{
	std::array<T1,3> ret;
	for (size_t ii=0; ii<3; ++ii)
		ret[ii] = i1[ii] + i2[ii];

	return ret;
}

template<typename T1,typename T2>
std::array<T1,3> vector_scale(T1 constant,std::array<T2,3> input)
{
	std::array<T1,3> ret;
	for (size_t ii=0; ii<3; ++ii)
		ret[ii] = input[ii] * constant;

	return ret;
}

template<typename T1,typename T2>
float vector_sp(std::array<T1,3> i1,std::array<T2,3> i2)
{
	float ret = 0.0;
	for (size_t ii=0; ii<3; ++ii)
		ret += i1[ii] * i2[ii];

	return ret;
}

template<typename T1>
T1 vector_abs(std::array<T1,3> input)
{
	T1 ret = 0;
	for (size_t ii=0; ii<3; ++ii)
		ret += sqrt(input[ii]*input[ii]);

	return ret;
}
