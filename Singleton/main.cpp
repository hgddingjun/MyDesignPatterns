#include "Singleton.h"

#include <thread>

#define MAX_THREADS 5
void simulate_logging( const std::string& threadName)
{
	Logger& logger = Logger::getInstance();
	for(int i=0; i<MAX_THREADS; i++) {
		logger.writeLog(threadName + " - 日志消息" + std::to_string(i));
	}
}


int main(void)
{
	Logger& logger = Logger::getInstance();

	logger.writeLog("主线程开始运行...");

	std::thread thread1(simulate_logging, "线程1");
	std::thread thread2(simulate_logging, "线程2");
	std::thread thread3(simulate_logging, "线程3");
	std::thread thread4(simulate_logging, "线程4");
	std::thread thread5(simulate_logging, "线程5");

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();

	logger.writeLog("主线程运行结束...");
	return 0;
}
