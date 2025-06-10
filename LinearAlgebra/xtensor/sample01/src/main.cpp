#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

int main()
{
	xt::xarray<double> a = {{1.0, 2.0}, {3.0, 4.0}};
	xt::xarray<double> b = {{5.0, 6.0}, {7.0, 8.0}};
	
	auto result = a + b;

	std::cout << "Result: \n" << result << std::endl;

	return EXIT_SUCCESS;
}

