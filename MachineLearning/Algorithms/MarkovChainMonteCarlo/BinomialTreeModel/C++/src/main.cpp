#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

vector<vector<double>> binomial_tree(double mu, double sigma, int S0, int N, const vector<double>& T, double step)
{
	// compute state price and probability
	double u{exp(sigma * sqrt(step))};
	double d{1.0 / u};
	double p{0.5 + 0.5 * (mu / sigma) * sqrt(step)};

	random_device rd{};
	mt19937 gen{rd()};

	//vector<vector<int>> up_times(N, vector<int>(T.size()));
	//vector<vector<int>> down_times(N, vector<int>(T.size()));
	vector<vector<double>> ST(N, vector<double>(T.size(), 0.0));

	// Binomial simulation
	int trials;
	int up;
	int down;

	for (size_t idx{0}; idx < T.size(); ++idx) {
		trials = static_cast<int>(T[idx] / step);
		binomial_distribution<> binom{trials, p};

		for (int i{0}; i < N; ++i) {
			up = binom(gen);
			down = trials - up;

			// compute terminal price
			ST[i][idx] = S0 * pow(u, up) * pow(d, down);
		}
	}

	return ST;
}

void show_result(const vector<vector<double>>& matrix)
{
	for (const auto& row : matrix) {
  	for (const auto& value : row) {
    	std::cout << value << ' ';
    }
        
		std::cout << '\n';
	}
}

int main()
{
	double mu{0.1};
	double sigma{0.15};
	int S0{1};
	int N{10000};
	vector<double> T{21.0 / 252, 1.0};
	double step{1.0 / 252};

	show_result(binomial_tree(mu, sigma, S0, N, T, step));

	return EXIT_SUCCESS;
}
