#ifndef __PI_ESTIMATION__
#define __PI_ESTIMATION__

#include <tuple>

namespace rbs::ds
{
	std::pair<double, double> pi_estimation(double radius=1.0, int numIter=1'000'000);
}

#endif

