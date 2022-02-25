//
// Created by tao on 2022/2/21.
//

#ifndef TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H
#define TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H

#include <vector>
#include "Document.h"
#include "tinyxml2.h"


class SearchEngine
{
public:
	std::vector<Document*> loadDocuments(const std::string& path);
private:
	Document* parseDocument(tinyxml2::XMLNode* doc);
};


#endif //TOYFULLTEXTSEARCHENGINE_SEARCHENGINE_H
