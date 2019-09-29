#include <string>
#include <vector>
#include <memory>
#include "MovieDataRepository.h"
#include "MovieData.h"
#include "Logger.h"

//class MovieData;

typedef std::vector<std::shared_ptr<MovieData>> Movies;
//typedef std::vector<std::shared_ptr<MovieData>> Movies;

class MetaDataProcessor
{
	MovieDataRepositoryBase& m_repository;
	std::shared_ptr <LoggerFactory> m_loggerFactory;

public:
	MetaDataProcessor(MovieDataRepositoryBase& repository) : MetaDataProcessor(repository, std::make_shared<LoggerFactory>()) {};
	MetaDataProcessor(MovieDataRepositoryBase& repository, std::shared_ptr<LoggerFactory> loggerFactory) : m_repository(repository), m_loggerFactory(loggerFactory) {};
	//	MetaDataProcessor() {};
//	MetaDataProcessor();
	virtual ~MetaDataProcessor() {}

	void ProcessMovies(const std::vector<std::string>& movieNames, Movies& result);

	void debug() {};
};