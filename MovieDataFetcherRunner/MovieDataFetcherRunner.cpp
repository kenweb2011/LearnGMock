#include <iostream>
#include <string>
#include <vector>
#include "MovieData.h"
#include "MetaDataProcessor.h"
#include "MovieDataRepository.h"
#include "../MovieDataFetcherTests/ApiKey.h"
#include "MovieDataFactory.h"
#include "RestApiClient.h"
/*
cd w : \x64\Debug
copy w : \packages\curl.redist.7.30.0.2\build\native\bin\v110\x64\Debug\dynamic\libcurl.dll
copy w : \packages\libssh2.redist.1.4.3.1\build\native\bin\v110\x64\Debug\dynamic\cdecl\libssh2.dll
copy w : \packages\openssl.redist.1.0.1.21\build\native\bin\v110\x64\Debug\dynamic\cdecl\ssleay32.dll
copy w : \packages\openssl.redist.1.0.1.21\build\native\bin\v110\x64\Debug\dynamic\cdecl\libeay32.dll
copy w : \packages\zlib.redist.1.2.8.1\build\native\bin\v110\x64\Debug\dynamic\cdecl\zlib.dll
*/

int main()
{
    std::cout << "Hello World!\n";

	RestApiClient restApiClient;
	MovieDataFactory dataFactory;
	MovieDataRepository repository(MY_API_KEY, dataFactory, restApiClient);
	MetaDataProcessor processor(repository);

	Movies result;
	processor.ProcessMovies({"Doctor Strange", "Dr. Strangelove"}, result);

	for (auto movie : result)
	{
		std::cout << "Title: " << movie->GetTitle() << std::endl;
		std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl << std::endl;
		std::cout << movie->GetPlot() << std::endl << std::endl;
		std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl << std::endl;
		std::cout << "-----------------------" << std::endl;
	}

	std::cout << "Done.\n";

}
