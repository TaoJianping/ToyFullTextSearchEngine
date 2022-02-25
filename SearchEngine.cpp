//
// Created by tao on 2022/2/21.
//

#include <stdexcept>
#include <iostream>
#include "SearchEngine.h"

std::vector<Document*> SearchEngine::loadDocuments(const std::string& path)
{
	using namespace tinyxml2;
	std::vector<Document*> docs{};

	XMLDocument doc;
	XMLError error = doc.LoadFile(path.c_str());

	if (error != XMLError::XML_SUCCESS)
		throw std::runtime_error("Open Xml File Failed");

	XMLElement* root = doc.RootElement();
	std::cout << "RootElement name:" << root->Name() << std::endl;

	for (XMLNode* current = root->FirstChild(); current != nullptr; current = current->NextSibling())
	{
		docs.push_back(parseDocument(current));
	}

	return docs;
}

Document* SearchEngine::parseDocument(tinyxml2::XMLNode* doc)
{
	auto document = new Document{};
	auto child = doc->FirstChildElement();

	while (child != nullptr)
	{
		if (std::strcmp(child->Name(), "title") == 0)
		{
			document->title = std::string{ child->GetText() };
		}
		else if (std::strcmp(child->Name(), "url") == 0)
		{
			document->url = std::move(std::string{ child->GetText() });
		}
		else if (std::strcmp(child->Name(), "abstract") == 0)
		{
			document->text = std::move(std::string{ child->GetText() });
		}
		child = child->NextSiblingElement();
	}

	return document;
}
