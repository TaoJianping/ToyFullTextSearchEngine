//
// Created by tao on 2022/2/21.
//

#ifndef TOYFULLTEXTSEARCHENGINE_DOCUMENT_H
#define TOYFULLTEXTSEARCHENGINE_DOCUMENT_H

#include <string>


class Document
{
public:
	u_int64_t id;
	std::string title {};
	std::string url {};
	std::string text {};

};


#endif //TOYFULLTEXTSEARCHENGINE_DOCUMENT_H
