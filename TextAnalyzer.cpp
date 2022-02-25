//
// Created by tao on 2022/2/23.
//

#include "TextAnalyzer.h"

#include <utility>
#include <iostream>
#include "porter2_stemmer.h"


std::vector<std::string> TextAnalyzer::analyze(std::string text)
{
	auto tokens = tokenize(std::move(text));
	tokens = lowercaseFilter(tokens);
	tokens = stopWordFilter(tokens);
	tokens = stemmerFilter(tokens);
	return tokens;
}

std::vector<std::string> TextAnalyzer::tokenize(std::string text)
{
	std::string pattern = R"(\w+)";
	std::regex reg(pattern);
	std::vector<std::string> ret{};

	for (std::sregex_iterator it(text.begin(), text.end(), reg), it_end; it != it_end; ++it)
	{
		ret.push_back(it->str());
	}

	return ret;
}

std::vector<std::string> TextAnalyzer::lowercaseFilter(std::vector<std::string> tokens)
{
	std::transform(std::begin(tokens), std::end(tokens), std::begin(tokens),
			[](std::string word)
			{
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				return word;
			});
	return tokens;
}

std::vector<std::string> TextAnalyzer::stopWordFilter(std::vector<std::string> tokens)
{
	std::vector<std::string> ret{};
	std::copy_if(tokens.begin(), tokens.end(), std::back_inserter(ret),
			[this](const std::string& word)
			{
				if ( std::find(this->stopWords.begin(), this->stopWords.end(), word) != this->stopWords.end() )
					return false;
				else
					return true;
			});

	return ret;
}

std::vector<std::string> TextAnalyzer::stemmerFilter(std::vector<std::string> tokens)
{
	std::vector<std::string> ret{};
	std::transform(tokens.begin(), tokens.end(), std::back_inserter(ret),
			[](std::string word)
			{
				Porter2Stemmer::trim(word);
				Porter2Stemmer::stem(word);
				return word;
			});

	return ret;
}
