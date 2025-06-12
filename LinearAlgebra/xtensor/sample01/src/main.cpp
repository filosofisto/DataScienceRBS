#include <iostream>
#include <vector>
#include <array>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xmath.hpp>     	// For xt::ones, xt::zeros
#include <xtensor/xbuilder.hpp>  	// For xt::eye
#include <xtensor/xadapt.hpp>  		// Required for xt::adapt
#include <xtensor/xrandom.hpp>  	// Required for xt::random::rand()
//#include <xtensor/xlinalg.hpp>  	// Required for xt::linalg::dot()
				
int main()
{
	xt::xarray<double> x = {{1.0, 2.0}, {3.0, 4.0}};
	xt::xarray<double> y = {{5.0, 6.0}, {7.0, 8.0}};
	
	auto result = x + y;

	std::cout << "Result: \n" << result << std::endl;

	std::vector<size_t> shape_a = {3, 2, 4};
	xt::xarray<double, xt::layout_type::row_major> a{shape_a};

	// std::array<size_t, 3> shape_b = {3, 2, 4};
	// xt::xtensor<double, 3> b{shape_b};

	xt::xarray<double> arr1{{1.0, 2.0, 3.0}, {2.0, 5.0, 7.0}, {2.0, 5.0, 7.0}};

	std::vector<uint64_t> shape_c{2, 2};
	auto m = xt::ones<double>(shape_c);
	auto n = xt::zeros<double>(shape_c);
	auto o = xt::eye<double>(2); 		// Identity matrix
	
	std::vector<size_t> shape_d{2, 2};
	std::vector<float> data{1, 2, 3, 4};
	auto data_x = xt::adapt(data, shape_d);

	std::vector<size_t> shape_e{3, 2, 4};
	xt::xarray<float> data_e = xt::ones<float>(shape_e);
	data_e(2,1,3) = 3.14f;

	/*auto data_f = xt::random::rand<double>({2,2});
	auto data_g = xt::random::rand<double>({2,2});
	auto data_h = data_f + data_g;
	data_f -= data_g;
	data_h = xt::linalg::dot(data_f, data_g);
	data_h = data_f + 5;*/

	return EXIT_SUCCESS;
}

