#include "ChainOfResponsibility.h"

int main(void) {
	//创建具体的处理者
	auto departmentManager = std::make_shared<DepartmentManager>();
	auto financeManager = std::make_shared<FinanceManager>();
	auto generalManager = std::make_shared<GeneralManager>();

	//设置责任链
	departmentManager->setNextHandler(financeManager);
	financeManager->setNextHandler(generalManager);

	//模拟请求
	std::cout << "请求金额为300元:" << std::endl;
	departmentManager->handleRequest(300);

	std::cout << "请求金额为800元:" << std::endl;
	departmentManager->handleRequest(800);

	std::cout << "请求金额为1500元:" << std::endl;
	departmentManager->handleRequest(1500);

	std::cout << "请求金额为50元:" << std::endl;
	departmentManager->handleRequest(50);
	
	return 0;
}
