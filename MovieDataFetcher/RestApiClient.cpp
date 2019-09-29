#include <iostream>
#include "RestApiClient.h"
#include "curl/curl.h"


size_t WriteCallback(void* ptr, size_t size, size_t nmemb, std::string* data) {
	data->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

std::string RestApiClient::HttpGet(std::string& url)
{
	CURL* curl = curl_easy_init();
	if (!curl)
	{
		// TODO: handle error
		curl_easy_cleanup(curl);
		return std::string();
	}

	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	//curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
	//curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
	//curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
	//curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

	std::string response_string;
	std::string header_string;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
	curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
	//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{}");

	long response_code;
	//double elapsed;
	//char* url;
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
	//curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
	//curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	curl = NULL;
	//std::cout << "Respons Code: " << response_code << std::endl;

	if (res != CURLE_OK)
	{
		// TODO: handle error
		std::cerr << url << std::endl;
		std::cerr << "Error Code: " << res << std::endl;
		return std::string();
	}
	return response_string;
}


std::string RestApiClient::Encode(const std::string& source) const
{
	CURL* curl = curl_easy_init();
	if (!curl)
	{
		// TODO: handle error
		curl_easy_cleanup(curl);
		return std::string();
	}
	auto encoded = curl_easy_escape(curl, source.c_str(), 0);
	curl_easy_cleanup(curl);

	return encoded;
}
