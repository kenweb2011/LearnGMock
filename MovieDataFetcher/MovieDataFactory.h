#pragma once
#include <memory>
#include "MovieData.h"

class MovieDataFactoryBase
{
public:
	virtual ~MovieDataFactoryBase() = default;

	virtual std::shared_ptr<MovieData> CreateFromJson(const std::string& jsonString) const = 0;
};


class MovieDataFactory : MovieDataFactoryBase
{

public:
	MovieDataFactory() {}

	std::shared_ptr<MovieData> CreateFromJson(const std::string& jsonString) const override;
};

