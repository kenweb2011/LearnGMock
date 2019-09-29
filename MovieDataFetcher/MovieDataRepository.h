#pragma once
#include <string>
#include <memory>
#include "MovieDataFactory.h"
#include "MovieData.h"
#include "RestApiClient.h"

class MovieDataRepositoryBase
{
public:
	virtual ~MovieDataRepositoryBase() {}
	virtual std::shared_ptr<MovieData> FindMovieData(const std::string& movieName) = 0;
};

class MovieDataRepository : public MovieDataRepositoryBase
{
	RestApiClient& m_client;
	const std::string& m_apiKey;
	const MovieDataFactory& m_movieDataFactory;

public:
	MovieDataRepository(const std::string& apikey, const MovieDataFactory& dataFactory, RestApiClient& client) : m_apiKey(apikey), m_movieDataFactory(dataFactory), m_client(client) {};

	std::shared_ptr<MovieData> FindMovieData(const std::string& movieName);
};

