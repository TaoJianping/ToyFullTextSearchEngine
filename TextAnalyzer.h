//
// Created by tao on 2022/2/23.
//

#ifndef TOYFULLTEXTSEARCHENGINE_TEXTANALYZER_H
#define TOYFULLTEXTSEARCHENGINE_TEXTANALYZER_H

#include <vector>
#include <string>
#include <regex>
#include <algorithm>

class TextAnalyzer
{
public:
	std::vector<std::string> analyze(std::string text);

private:
	std::vector<std::string> tokenize(std::string text);
	std::vector<std::string> lowercaseFilter(std::vector<std::string> tokens);
	std::vector<std::string> stopWordFilter(std::vector<std::string> tokens);
	std::vector<std::string> stemmerFilter(std::vector<std::string> tokens);

	std::vector<std::string> stopWords {"a", "and", "be", "have", "i", "in", "of", "that", "the", "to"};
};


#endif //TOYFULLTEXTSEARCHENGINE_TEXTANALYZER_H
