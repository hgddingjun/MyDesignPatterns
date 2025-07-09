#include "Command.h"

int main(void) {
	//创建接收者
	auto light = std::make_shared<Light>();
	auto fan = std::make_shared<Fan>();

	//创建命令
	auto cmdLightOn = std::make_shared<LightOnCommand>(light);
	auto cmdLightOff = std::make_shared<LightOffCommand>(light);
	auto cmdFanOn = std::make_shared<FanOnCommand>(fan);
	auto cmdFanOff = std::make_shared<FanOffCommand>(fan);

	//调用者
	RemoteControl rc;

	//执行命令
	std::cout << "用户操作:" << std::endl;
	rc.executeCommand(cmdLightOn);
	rc.executeCommand(cmdLightOff);
	rc.executeCommand(cmdFanOn);

	//撤销命令
	std::cout << "\n撤销操作:" << std::endl;
	rc.undoLastCommand();
	rc.undoLastCommand();
	rc.undoLastCommand();
	rc.undoLastCommand();

	return 0;
}
