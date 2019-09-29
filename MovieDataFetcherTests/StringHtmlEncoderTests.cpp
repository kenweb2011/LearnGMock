#pragma once
#include <iostream>
#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "RestApiClient.h"

using namespace std;

RestApiClient restApiClient;

TEST(StringHtmlEncoderTests, Encode_StringWithoutSpaces_RetureSameString)
{
	auto result = restApiClient.Encode("1234");

	ASSERT_EQ(result, "1234");
}

TEST(StringHtmlEncoderTests, Encode_StringWithOneSpace_RetureStringWithEncoding)
{
	auto result = restApiClient.Encode("A B");

	ASSERT_EQ(result, "A%20B");
}

TEST(StringHtmlEncoderTests, Encode_StringWithMultipleSpaces_RetureStringWithEncoding)
{
	auto result = restApiClient.Encode("A B C D");

	ASSERT_EQ(result, "A%20B%20C%20D");
}

struct EncoderTestRow
{
	EncoderTestRow(std::string input, std::string expected) : input(input), expected(expected) {  }

	std::string input, expected;
};

::std::ostream& operator<<(::std::ostream& os, const EncoderTestRow& row) {
	return os << "input:" << row.input << " expected result: " << row.expected;
}


class StringHtmlEncoderTests : public ::testing::TestWithParam<EncoderTestRow> { };

TEST_P(StringHtmlEncoderTests, EncodeStringToHtml)
{
	auto row = GetParam();

	auto result = restApiClient.Encode(row.input);

	ASSERT_EQ(row.expected, result);
}

INSTANTIATE_TEST_CASE_P(WhiteSpaceEncoding, StringHtmlEncoderTests, ::testing::Values(
	EncoderTestRow("A", "A"),
	EncoderTestRow("A B", "A%20B"),
	EncoderTestRow("A B C D", "A%20B%20C%20D")
));


