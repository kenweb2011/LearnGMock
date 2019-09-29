#include "rapidjson/document.h"
#include "MovieDataFactory.h"
#include "ErrorParsingMovieDataException.h"


std::shared_ptr<MovieData> MovieDataFactory::CreateFromJson(const std::string& jsonString) const
{
	rapidjson::Document jsonDocument;
	jsonDocument.Parse(jsonString.c_str());
	if (!jsonDocument.IsObject())
	{
		throw ErrorParsingMovieDataException();
	}

	try
	{
		auto imdbId = jsonDocument["imdb_id"].GetString();
		auto title = jsonDocument["title"].GetString();
		auto plot = jsonDocument["overview"].GetString();
		auto lengthMin = jsonDocument["runtime"].GetUint();

		auto movieData = MovieData(title, imdbId, plot, lengthMin);
		auto result = std::make_shared<MovieData>(movieData);

		//auto result = std::make_shared<SettableMovieData>();
		//result->SetImdbId(imdbId);
		//result->SetTitle(title);
		//result->SetPlot(plot);
		//result->SetLengthMin(lengthMin);

		return result;
	}
	catch (...)
	{
		throw ErrorParsingMovieDataException();
	}
}