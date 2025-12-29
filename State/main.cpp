#include "State.h"

//客户端代码
int main() {
	//创建自动售货机并设置初始状态
	VendingMachine machine;
	machine.setState(std::make_shared<NoCoinState>(&machine));

	//测试售货机的功能
	std::cout << "=== 测试场景 1: 无硬币状态 ===" << std::endl;
	machine.selectProduct(); //未投硬币时选择商品
	machine.insertCoin();    //投入硬币

	std::cout << "=== 测试场景 2: 有硬币状态 ===" << std::endl;
	machine.selectProduct(); //投硬币后选择商品
	return 0;
}
