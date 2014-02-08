#include <string>


class Logger {
private:
	enum LogLevel {LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_NONE};
	
	LogLevel currentLogLevel;
	FILE *logfile;
public:
	Logger();
	void ChangeLogLevel(LogLevel newLogLevel);
	
	void Log(LogLevel log, const char* message);
	
	void LogDebug(const char* message);
	void LogInfo(const char* message);
	void LogWarn(const char* message);
	void LogError(const char* message);
};
