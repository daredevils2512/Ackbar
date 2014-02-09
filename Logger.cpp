#include <cstdio>
#include "Logger.h"

const std::string lognames [] = {"DEBUG", "INFO", "WARN", "ERROR"};


Logger::Logger(){
	currentLogLevel = LOG_DEBUG;
	logfile = fopen("log.txt", "a");
	LogDebug("Begin Logging");
}

void Logger::ChangeLogLevel(LogLevel newLogLevel){
	currentLogLevel = newLogLevel;
}

void Logger::Log(LogLevel loglevel, const char* message){
	if (loglevel >= currentLogLevel){
		fprintf(logfile, "%s:%s\n", lognames[loglevel].c_str(), message);
	}
}

void Logger::LogDebug(const char* message){
	Log(LOG_DEBUG, message);
}

void Logger::LogInfo(const char* message){
	Log(LOG_INFO, message);
}

void Logger::LogWarn(const char* message){
	Log(LOG_WARN, message);
}

void Logger::LogError(const char* message){
	Log(LOG_ERROR, message);
}
