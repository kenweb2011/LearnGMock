#pragma once
#include "gmock/gmock.h"
#include "MovieDataRepository.h"

class FakeMovieDataRepository : public MovieDataRepositoryBase
{
public:
	MOCK_METHOD1(FindMovieData, std::shared_ptr<MovieData>(const std::string& movieName));
};

