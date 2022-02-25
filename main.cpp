#include <iostream>


#include "SearchEngine.h"

//
int main() {
	auto engine = SearchEngine{};
	auto docs = engine.loadDocuments("/home/tao/Documents/ToyFullTextSearchEngine/resource/enwiki-latest-abstract1.xml");

	for (auto doc: docs)
	{
		std::cout << "doc title:(" << doc->title << ")" << std::endl;
	}

	engine.buildIndex(docs);
//	engine.printIndex();

	auto ans = engine.search("on is movements");
	for (auto item : ans)
	{
		std::cout << "[";
		for (u_int64_t id: item)
		{
			std::cout << std::to_string(id) << ",";
		}
		std::cout << "]";
	}

    return 0;
}
