#include "Connection.hpp"

using json = nlohmann::json;

void sk::server::Connection::loadDataFromServer()
{
	// LOADING COURSES
	std::string serverReturn = http_get("http://194.28.222.28:8080/api/catergories");

	json json;
	try
	{
		json::parse(serverReturn);
	}
	catch (json::parse_error& e)
	{
		mLogger.error(e.what());
	}

	if (json.is_array())
	{
		for (const auto& item : json)
		{
			sk::server::CourseInfo c;
			c.name = item.value("name", "");
			c.description = item.value("description", "");
			
			mCourses.insert(std::make_pair(item.value("id", 0), c));
		}
	}

}

void sk::server::Connection::loadCourseLessons(unsigned int id, std::map<unsigned int, LessonInfo>& map)
{
	std::string url = "http://194.28.222.28:8080/api/catergories/lesson/" + std::to_string(id);
	std::string serverReturn = http_get(url);

	json json;
	try
	{
		json::parse(serverReturn);
	}
	catch (json::parse_error& e) { mLogger.error(e.what()); }

	if (json.is_array())
	{
		for (const auto& item : json)
		{
			sk::server::LessonInfo l;
			l.description = item.value("description", "");
			l.name = item.value("name", "");

			map.insert(std::make_pair(item.value("id", 0), l));
		}
	}
}

sk::server::CourseInfo sk::server::Connection::getCourseInfo()
{
	return sk::server::CourseInfo();
}

sk::server::LessonInfo sk::server::Connection::getLessonInfo()
{
	return LessonInfo();
}

sk::server::Connection::Connection()
{
	mCurl = curl_easy_init();
	if (!mCurl) throw std::runtime_error("Failed to init cURL!");
}

std::string sk::server::Connection::http_get(const std::string& url)
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
