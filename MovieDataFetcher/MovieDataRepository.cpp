#include "MovieDataRepository.h"
#include "MovieNotFoundException.h"
#include "JsonHelper.h"

std::shared_ptr<MovieData> MovieDataRepository::FindMovieData(const std::string& movieName)
{
	//auto encodedMovieName = StringHtmlEncoder::Encode(movieName);
	auto encodedMovieName = m_client.Encode(movieName);

	auto getMovieListUrl = "http://api.themoviedb.org/3/search/movie?api_key=" + m_apiKey + "&page=1&query=" + encodedMovieName;
	auto movieList = m_client.HttpGet(getMovieListUrl);
	if (movieList.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	auto movieId = JsonHelper::GetMatchingTitleIdFromMovieList(movieName, movieList);
	if (movieId.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	auto getMovieDetailsUrl = "http://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + m_apiKey;
	auto movieDataJson = m_client.HttpGet(getMovieDetailsUrl);

	return m_movieDataFactory.CreateFromJson(movieDataJson);

	return std::shared_ptr<MovieData>();
}
