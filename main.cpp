#include <iostream>

#include "TextAnalyzer.h"
#include "SearchEngine.h"

//
int main() {
	auto engine = SearchEngine{};
	auto docs = engine.loadDocuments("/home/tao/Documents/tmp/enwiki-latest-abstract1.xml");

	for (auto doc: docs)
	{
		std::cout << "doc title:(" << doc->title << ")" << std::endl;
	}
	auto a = TextAnalyzer{};




    return 0;
}
