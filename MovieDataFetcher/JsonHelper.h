#pragma once

#include <string>

class JsonHelper
{
public:
	JsonHelper() {}
	virtual ~JsonHelper() {}

	static std::string GetMatchingTitleIdFromMovieList(const std::string& title, const std::string& jsonString);

};

