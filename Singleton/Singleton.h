#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>

class Logger {
public:
	static Logger& getInstance(void){
		static Logger instance; //静态局部变量，线程安全
		return instance;
	}

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	void writeLog(const std::string& message) {
		std::lock_guard<std::mutex> lock(log_mutex_);
		log_file_ << message << std::endl;
		std::cout << "日志已记录:" << message << std::endl;
	}

private:
	Logger() {
		log_file_.open("application.log", std::ios::app);
		if(!log_file_.is_open()) {
			std::cout << "打开日志文件失败!" << std::endl;
		} else {
			std::cout << "日志记录器初始化成功!" << std::endl;
		}
	}

	~Logger(){
		if(log_file_.is_open()) {
			log_file_.close();
		}
	}

private:
	std::ofstream log_file_;
	std::mutex log_mutex_;
};

#endif /* _SINGLETON_H_ */
