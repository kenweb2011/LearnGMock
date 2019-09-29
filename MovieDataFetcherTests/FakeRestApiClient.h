#pragma once
#include "gmock/gmock.h"
#include "RestApiClient.h"

class FakeRestApiClient : public RestApiClient
{
	//std::string m_result;
public:

	//FakeRestApiClient(std::string result) : m_result(result) {}
	//std::string HttpGet(std::string& url) override {
	//	return m_result;
	//}

	MOCK_METHOD1(HttpGet, std::string(std::string&));

};

