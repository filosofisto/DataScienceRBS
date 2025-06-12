#ifndef __IF_IDF__
#define __IF_IDF__

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class IFIDFVectorizer
{
	public:
		IFIDFVectorizer(const std::vector<std::string>& phrases);
		~IFIDFVectorizer() = default;

		void process();
		size_t times_on_document(size_t docIndex, const std::string& word);
	private:
		std::vector<std::string> phrases;
		std::unordered_map<std::string, size_t> frequence;
		std::unordered_map<size_t, std::unique_ptr<std::unordered_map<std::string, size_t>>> tf;
};

#endif
