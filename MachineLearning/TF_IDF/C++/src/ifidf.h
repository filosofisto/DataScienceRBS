#ifndef __IF_IDF__
#define __IF_IDF__

#include <unordered_map>
#include <vector>
#include <string>
#include <expected>

class IFIDFVectorizer
{
	public:
		IFIDFVectorizer(const std::vector<std::string>& phrases);
		~IFIDFVectorizer() = default;

		std::expected<size_t, std::string> times_in_document(size_t docIndex, const std::string& word);
		std::expected<size_t, std::string> total_terms_in_document(size_t docIndex) const;
		size_t total_number_documents() const;
		size_t total_number_documents_with(const std::string& word);
		double idf(const std::string& word);
	private:
		std::vector<std::string> phrases;
		std::unordered_map<size_t, std::unordered_map<std::string, size_t>> map;
};

#endif
