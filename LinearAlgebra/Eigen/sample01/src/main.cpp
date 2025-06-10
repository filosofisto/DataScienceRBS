#include <iostream>
#include <Eigen/Dense>

int main()
{
	Eigen::Matrix2d mat;
	mat << 1, 2,
				 3, 4;

	Eigen::Vector2d vec{5, 6};
	Eigen::Vector2d result = mat * vec;

	std::cout << "Result:\n" << result << std::endl;

	return EXIT_SUCCESS;
}

