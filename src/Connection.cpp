#include "Connection.hpp"

Connection::Connection()
{
	mCurl = curl_easy_init();
	if (!mCurl) throw std::runtime_error("Failed to init cURL!");
}

std::string Connection::http_get(const std::string& url)
{
	std::string response;

	curl_easy_setopt(mCurl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(mCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(mCurl, CURLOPT_WRITEDATA, &response);

	CURLcode res = curl_easy_perform(mCurl);
	curl_easy_cleanup(mCurl);

	if (res != CURLE_OK)
		return "";

	return response;
}
