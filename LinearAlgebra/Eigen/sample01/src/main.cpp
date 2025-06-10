#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

typedef Eigen::Matrix<float, 3, 3> Matrix33f;
typedef Eigen::Matrix<float, 3, 1> Vector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> DynamicMatrix;

int main()
{
	Matrix2d mat;
	mat << 1, 2,
				 3, 4;

	Vector2d vec{5, 6};
	Vector2d result = mat * vec;

	std::cout << "Result:\n" << result << std::endl;

	Matrix33f a;
	Vector3f v;
	DynamicMatrix m{10, 15};

	a = Matrix33f::Zero(); 			// fill matrix elements with zeros
	a = Matrix33f::Identity(); 	// fill matrix as Identity matrix
	v = Vector3f::Random();			// fill matrix elements with random values

	a(0,0) = 3;

	Matrix2d x = Matrix2d::Random();
	Matrix2d y = Matrix2d::Random();
	Matrix2d res = x + y;
	res = x.array() * y.array(); // element wise multiplication
	res = x.array() / y.array();
	x += y;
	res = x * y; 				// matrix multiplication
	x = y.array() * 4; 	// scalar multiplication

	MatrixXf p{4, 4};
	Matrix2f q{p.block(1, 1, 2, 2)}; // copy the middle part of matrix
	p.block(1, 1, 2, 2) *= 4;				// change values in original matrix

	p.row(1).array() += 3;
	p.col(2).array() /= 4;

	MatrixXf t{2, 4};
	t = MatrixXf::Random();
	VectorXf vt{2};
	vt = VectorXf::Random();
	t.colwise() += vt;
		
	return EXIT_SUCCESS;
}

