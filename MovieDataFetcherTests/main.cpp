// This file contains the 'main' function. Program execution begins and ends there.
//
/*
cd w : \x64\Debug
copy w : \packages\curl.redist.7.30.0.2\build\native\bin\v110\x64\Debug\dynamic\libcurl.dll
copy w : \packages\libssh2.redist.1.4.3.1\build\native\bin\v110\x64\Debug\dynamic\cdecl\libssh2.dll
copy w : \packages\openssl.redist.1.0.1.21\build\native\bin\v110\x64\Debug\dynamic\cdecl\ssleay32.dll
copy w : \packages\openssl.redist.1.0.1.21\build\native\bin\v110\x64\Debug\dynamic\cdecl\libeay32.dll
copy w : \packages\zlib.redist.1.2.8.1\build\native\bin\v110\x64\Debug\dynamic\cdecl\zlib.dll

MovieDataFetcherTests.exe
MovieDataFetcherTests.exe --gtest_list_tests
MovieDataFetcherTests.exe --gtest_also_run_disabled_tests
MovieDataFetcherTests.exe --gtest_filter=*Encode*
MovieDataFetcherTests.exe --gtest_filter=*Encode*-*String
MovieDataFetcherTests.exe --gtest_output=xml
*/

#include <iostream>
#include "gtest\gtest.h"
#include "gmock\gmock.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello MovieDataFetcherTests!\n";

	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
