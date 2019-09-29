#include "MetaDataProcessor.h"
#include <iostream>
#include <exception>

//MetaDataProcessor::MetaDataProcessor(TheMovieDbRepository& repository)
//{
//}

//MetaDataProcessor::MetaDataProcessor()
//{
//}
//
//MetaDataProcessor::~MetaDataProcessor()
//{
//}

void MetaDataProcessor::ProcessMovies(const std::vector<std::string>& movieNames, Movies& result)
{
	if (movieNames.size() == 0) return;

	for (auto movieName : movieNames)
	{
		try
		{
			std::shared_ptr<MovieData> movieData = m_repository.FindMovieData(movieName);

			result.push_back(movieData);

		}
		catch (...)
		//catch (std::exception& e)
		{
			//std::cerr << "Fail to find movie " << movieName << "\n";
			//std::cerr << e.what() << "\n";
			m_loggerFactory->CreateLogger()->LogError(movieName);
			//m_loggerFactory->CreateLogger()->LogError("Fail to find movie " + movieName + "\n");
		}
	}
}

//void MetaDataProcessor::debug() {}
