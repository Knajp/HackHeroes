#include <curl/curl.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "Logger.hpp"
#include <map>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

namespace sk
{
	namespace server
	{
		struct CourseInfo
		{
			std::string name;
			std::string description;
		};
		struct LessonInfo
		{
			std::string name;
			std::string description;
		};

		class Connection
		{
		public:
			static Connection& getInstance()
			{
				static Connection instance;
				return instance;
			}

			// get a json parser and create getCourseInfo and getLessonInfo
			void loadDataFromServer();
			void loadCourseLessons(unsigned int id, std::map<unsigned int, LessonInfo>& map);

			CourseInfo getCourseInfo();
			LessonInfo getLessonInfo();
		private:
			Connection();

			std::string http_get(const std::string& url);
			CURL* mCurl;

			sk::debug::Logger mLogger = sk::debug::Logger("Server connection logger", spdlog::level::debug);

			std::map<unsigned int, CourseInfo> mCourses;
		};
	}
}
