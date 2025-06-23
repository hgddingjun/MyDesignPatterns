#include "Decorator.h"

int main(void) {
	//1. 创建基础黑咖啡
	std::shared_ptr<Beverage> coffee = std::make_shared<BlackCoffee>();
	std::cout << "基础订单:" << coffee->getDescription() << ", 价格:" << coffee->cost() << "(元)" << std::endl;

	coffee = std::make_shared<MilkDecorator>(coffee);
	std::cout << "加牛奶后:" << coffee->getDescription() << ", 价格:" << coffee->cost() << "(元)" <<std::endl;

	coffee = std::make_shared<SugarDecorator>(coffee);
	std::cout << "加糖后:" << coffee->getDescription() << ", 价格:" << coffee->cost() << "(元)" << std::endl;

	coffee = std::make_shared<ChocolateDecorator>(coffee);
	std::cout << "加巧克力后:" << coffee->getDescription() << ", 价格" << coffee->cost() << "(元)" << std::endl;

	return 0;
}
