//
// Created by tao on 2022/2/21.
//

#include <stdexcept>
#include <iostream>
#include "SearchEngine.h"
#include "algorithm"


static uint32_t docCount = 0;


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
	document->id = docCount++;

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

void SearchEngine::buildIndex(std::vector<Document*> docs)
{
	auto analyzer = TextAnalyzer{};
	for (const auto& doc: docs)
	{
		auto tokens = analyzer.analyze(doc->text);
		for (const auto& token: tokens)
		{
			if (index_map.count(token))
			{
				auto& list = index_map.at(token);
				if (std::find(list.begin(), list.end(), doc->id) == list.end())
				{
					list.push_back(doc->id);
				}
			}
			else
			{
				index_map.insert_or_assign(token, std::vector<u_int64_t> {doc->id});
			}
		}
	}
}

void SearchEngine::printIndex()
{
	for (auto const& [key, val] : index_map)
	{

		std::string valFormat {};

		for (auto id : val)
		{
			valFormat += std::to_string(id);
			valFormat += ",";
		}

		std::cout << key        // string (key)
				  << ':'
				  << valFormat        // string's value
				  << std::endl;
	}
}

std::vector<std::vector<u_int64_t>> SearchEngine::search(std::string text)
{
	std::vector<std::vector<u_int64_t>> ret{};
	auto analyzer = TextAnalyzer{};
	auto tokens = analyzer.analyze(text);
	for (auto & token : tokens)
	{
		if (index_map.count(token))
		{
			auto ans = index_map.at(token);
			ret.push_back(ans);
		}
	}

	return ret;
}
