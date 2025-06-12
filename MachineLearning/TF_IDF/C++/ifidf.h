#include <sstream>
#include "ifidf.h"

using std::vector;
using std::string;
using std::unordered_map;
using std::istringstream;
using std::make_unique;

IFIDFVectorizer::IFIDFVectorizer(const vector<string>& phrases) : phrases(phrases)
{

}

void IFIDFVectorizer::process()
{
	string word;
	size_t docIndex{0};

	for (const auto& str : phrases) {
		auto ptmap = make_unique<unordered_map<string, size_t>(); 
		tf[docIndex] = ptmap;  
 
		istringstream ss(str);

		while (iss >> word) {
			ptmap->[word]++;
		}

		++docIndex;
	}
}

size_t IFIDFVectorizer::times_on_document(size_t docIndex, const string& word) const
{
	return tf[docIndex]->[word];
}
