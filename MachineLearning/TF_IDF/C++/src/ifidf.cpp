#include <sstream>
#include <cmath>
#include "ifidf.h"

using std::vector;
using std::string;
using std::unordered_map;
using std::istringstream;
using std::expected;
using std::unexpected;
using std::log;

IFIDFVectorizer::IFIDFVectorizer(const vector<string>& phrases) : phrases(phrases)
{

}

expected<size_t, string> IFIDFVectorizer::times_in_document(size_t docIndex, const std::string& word)
{
	if (docIndex < 0 || docIndex > phrases.size()-1) return unexpected{"Invalid index"};
	
	if (map.find(docIndex) != map.end()) {
		return map.at(docIndex)[word];
	}

	unordered_map<string, size_t> inner_map{};
	string phrase{phrases[docIndex]};
	istringstream iss{phrase};
	string token;

	while (iss >> token) {
		inner_map[token]++;
	}

	map[docIndex] = inner_map;

	return inner_map[word];
}

std::expected<size_t, std::string> IFIDFVectorizer::total_terms_in_document(size_t docIndex) const
{
	if (docIndex < 0 || docIndex > map.size()-1) return unexpected{"Invalid index"};

	if (map.find(docIndex) != map.end()) {
		return map.at(docIndex).size();
	}

	return 0;	
}

size_t IFIDFVectorizer::total_number_documents() const
{
	return phrases.size();
}

size_t IFIDFVectorizer::total_number_documents_with(const std::string& word)
{
	size_t count{0};
	string token{};

	for (int i{0}; i < phrases.size(); ++i) {
		if (map.find(i) == map.end()) {
				istringstream iss(phrases[i]);
				unordered_map<string, size_t> inner_map{};

				while (iss >> token) {
					inner_map[token]++;
				}

				map[i] = inner_map;
		}

		if (map.at(i).find(word) != map.at(i).end()) {
			++count;
		}
	}

	return count; 
}

double IFIDFVectorizer::idf(const std::string& word)
{
	return log(static_cast<double>(total_number_documents()) / total_number_documents_with(word));	
}

