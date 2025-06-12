#include <iostream>
#include <string>
#include <vector>
#include "ifidf.h"

using namespace std;

int main()
{
	string docA{"The car is driven on the read"};
	string docB{"The truck is driven on the highway"};
	vector<string> phrases{docA, docB};
	IFIDFVectorizer ifidf{phrases};

	cout << "TF(t) = (Number of terms t in the document / Total number of terms on the document)\n\n";
	auto r1 = ifidf.times_in_document(0, "car");
	if (r1.has_value()) {
		cout << "Number of terms 'car' in Doc0: " << r1.value() << '\n';
	} else {
		cerr << r1.error() << '\n';
	}

	auto r2 = ifidf.total_terms_in_document(0);
	if (r2.has_value()) {
		cout << "Total terms 'car' in Doc0: " << r2.value() << '\n';
	} else {
		cerr << r2.error() << '\n';
	}

	if (r1.has_value() && r2.has_value()) {
		cout << "TF('car') = " << static_cast<float>(r1.value()) / r2.value() << '\n';
	}

	cout << "\n\nIDF(t) = log(Total Number of Documents / Number of documents with term t in it)\n\n";
	cout << "IDF('car') = log(" << ifidf.total_number_documents() << " / " << ifidf.total_number_documents_with("car") << ") = " << ifidf.idf("car") << '\n'; 

	return EXIT_SUCCESS;
}

