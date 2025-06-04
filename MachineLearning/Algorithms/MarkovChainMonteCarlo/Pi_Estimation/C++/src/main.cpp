#include <iostream>
#include "pi_estimation.h"

using rbs::ds::pi_estimation;
using std::cout;
using std::pair;

int main()
{
	auto [pi, error] = pi_estimation();
	cout << "Estimated PI:   " << pi << '\n';
	cout << "Standard Error: " << error << '\n';
}

