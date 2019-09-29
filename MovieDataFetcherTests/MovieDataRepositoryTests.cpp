#include <iostream>
#include <vector>
#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "MetaDataProcessor.h"
#include "MovieNotFoundException.h"
#include "MovieDataRepository.h"
#include "MovieDataFactory.h"
#include "MovieData.h"
#include "RestApiClient.h"
#include "FakeRestApiClient.h"

using namespace testing;
const std::string fictiveApiKey = "1234";

class MovieDataRepositoryTests
{
};

TEST(MovieDataRepositoryTests, FindMovieData_ApiReturnsEmptyString_ThrowsException)
{
	//FakeRestApiClient restApiClient("");
	FakeRestApiClient fakeClient;
	EXPECT_CALL(fakeClient, HttpGet(_)).WillOnce(Return(""));
	MovieDataFactory factory;

	MovieDataRepository repository(fictiveApiKey, factory, fakeClient);

	ASSERT_THROW(
		repository.FindMovieData("movie name"), MovieNotFoundException
	);

}

TEST(MovieDataRepositoryTests, FindMovieData_ApiReturnsStringWithoutMovie_ThrowsException)
{
	//FakeRestApiClient restApiClient("{}");
	FakeRestApiClient fakeClient;
	EXPECT_CALL(fakeClient, HttpGet(_)).WillOnce(Return("{\"results\":[]}"));
	MovieDataFactory factory;

	MovieDataRepository repository(fictiveApiKey, factory, fakeClient);

	ASSERT_THROW(
		repository.FindMovieData("movie name"), MovieNotFoundException
	);

}


TEST(TheMovieDbRepositoryTests, FindMovieData_ApiReturnsValidData_ReturnMovieResult)
{
	const char* movieList = "{\"page\":1,\"results\":[{\"id\":123,\"title\":\"my movie title\"}],\"total_results\":1,\"total_pages\":1}";
	const char* movieMeta = "{\"imdb_id\":\"myId\",\"title\":\"my movie title\",\"overview\":\"this is a plot\",\"runtime\":180}";

	MovieDataFactory factory;
	FakeRestApiClient fakeClient;

	EXPECT_CALL(fakeClient, HttpGet(HasSubstr("search/movie"))).WillOnce(Return(movieList));
	EXPECT_CALL(fakeClient, HttpGet(HasSubstr("movie/123"))).WillOnce(Return(movieMeta));

	MovieDataRepository repository(fictiveApiKey, factory, fakeClient);

	auto result = repository.FindMovieData("my movie title");

	EXPECT_EQ(result->GetImdbId(), "myId");
}