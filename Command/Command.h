#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>
#include <string>
#include <memory>
#include <stack>

//抽象命令接口
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command() = default;
};

//接收者: 灯
class Light {
public:
	void on() {
		std::cout << "开灯！" << std::endl;
	}
	void off() {
		std::cout << "关灯！" << std::endl;
	}
};


//接收者: 风扇
class Fan {
public:
	void on() {
		std::cout << "开风扇！" << std::endl;
	}
	void off() {
		std::cout << "关风扇！" << std::endl;
	}
};

//具体命令: 打开灯
class LightOnCommand : public Command {
public:
	explicit LightOnCommand(std::shared_ptr<Light> light) : light_(light) {}
	void execute() override {
		light_->on();
	}
	void undo() override {
		light_->off();
	}
private:
	std::shared_ptr<Light> light_;
};

//具体命令: 关闭灯
class LightOffCommand : public Command {
public:
	explicit LightOffCommand(std::shared_ptr<Light> light) : light_(light) {}
	void execute() override {
		light_->off();
	}
	void undo() override {
		light_->on();
	}
private:
	std::shared_ptr<Light> light_;
};

//具体命令: 打开风扇
class FanOnCommand : public Command {
public:
	explicit FanOnCommand(std::shared_ptr<Fan> fan) : fan_(fan) {}
	void execute() override {
		fan_->on();
	}
	void undo() override {
		fan_->off();
	}
private:
	std::shared_ptr<Fan> fan_;
};

//具体命令: 关闭风扇
class FanOffCommand : public Command {
public:
	explicit FanOffCommand(std::shared_ptr<Fan> fan) : fan_(fan) {} 
	void execute() override {
		fan_->off();
	}
	void undo() override {
		fan_->on();
	}

private:
	std::shared_ptr<Fan> fan_;
};

//调用者: 控制面板
class RemoteControl {
public:
	void executeCommand(std::shared_ptr<Command> command) {
		command->execute();
		historyCommand_.push(command);
	}

	void undoLastCommand() {
		if(!historyCommand_.empty()) {
			historyCommand_.top()->undo();
			historyCommand_.pop();
		} else {
			std::cout << "没有可撤销的命令！" << std::endl;
		}
	}
private:
	std::stack<std::shared_ptr<Command>> historyCommand_;
};


#endif /* _COMMAND_H_ */
