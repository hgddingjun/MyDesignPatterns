
#include <iostream>
#include <string>
#include <memory>

#include "Image.h"
#include "BankAccount.h"

int main(void) {
	std::cout << "======虚拟代理示例(延迟加载图片)======" << std::endl;

	//创建代理图片对象
	std::unique_ptr<Image> image = std::make_unique<ProxyImage>("Q-linux.png");

	//第一次触发图片加载
	std::cout << "第一次显示图片:" << std::endl;
	image->display();

	//第二次直接显示已经加载的图片
	std::cout << "第二次显示图片:" << std::endl;
	image->display();

	std::cout << "======保护代理示例(银行账户访问控制)======" << std::endl;

	//普通用户访问
	std::unique_ptr<BankAccount> normalUser = std::make_unique<BankAccountProxy>(1000.0,"normalUser");
	std::cout << "普通用户查看账户余额:" << std::endl;
	normalUser->showBalance();

	//管理员用户访问
	std::unique_ptr<BankAccount> admin = std::make_unique<BankAccountProxy>(1000.0,"admin");

	std::cout << "管理员用户查看账户余额:" << std::endl;
	admin->showBalance();


	return 0;
}
