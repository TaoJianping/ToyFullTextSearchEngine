//
// Created by tao on 2022/2/21.
//

#ifndef TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H
#define TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H

#include <vector>
#include <map>
#include "Document.h"
#include "tinyxml2.h"
#include "TextAnalyzer.h"

class SearchEngine
{
public:
	std::vector<Document*> loadDocuments(const std::string& path);

	void buildIndex(std::vector<Document*> docs);

	std::vector<std::vector<u_int64_t>> search(std::string text);

	void printIndex();

private:
	Document* parseDocument(tinyxml2::XMLNode* doc);

	std::map<std::string, std::vector<u_int64_t>> index_map{};
};


#endif //TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H
