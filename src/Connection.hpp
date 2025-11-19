#include <curl/curl.h>
#include <iostream>
#include <string>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

class Connection
{
public:
	static Connection& getInstance()
	{
		static Connection instance;
		return instance;
	}

	// get a json parser and create getCourseInfo and getLessonInfo
private:
	Connection();

	std::string http_get(const std::string& url);
	CURL* mCurl;
};