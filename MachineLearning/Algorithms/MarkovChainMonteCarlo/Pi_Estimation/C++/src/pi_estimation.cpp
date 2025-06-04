#include <random>
#include <vector>
#include <numeric>

#include "pi_estimation.h"

namespace rbs::ds
{
	std::pair<double, double> pi_estimation(double radius, int numIter)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist(-radius, radius);

		int inside = 0;
		double x, y, r2;

		for (int i{0}; i < numIter; ++i) {
			x = dist(gen);
			y = dist(gen);

			if ((x * x + y * y) < radius * radius) {
				++inside;
			}
		}

		auto p{static_cast<double>(inside) / numIter};
		auto piHat = 4.0 * p;
		auto piHatSe = 4.0 * std::sqrt(p * (1 - p) / numIter);

		return { piHat, piHatSe };	
	}
}

