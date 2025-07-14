#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Colleague; //同事类前置声明

//中介者接口类
class Mediator {
public:
	virtual void sendMessage(const std::string& message, const std::string& sender) = 0;
	virtual void addUser(std::shared_ptr<Colleague> colleague) = 0;
	virtual ~Mediator() = default;
};

//同事类(用户基类)
class Colleague {
public:
	Colleague(const std::string& name, const std::shared_ptr<Mediator> mediator): name_(name), mediator_(mediator) {}
	virtual void send(const std::string& message) = 0;
	virtual void recv(const std::string& message, const std::string& sender) = 0;
	virtual ~Colleague() = default;

public:
	std::string name_;
	std::shared_ptr<Mediator> mediator_;
};

//具体同事类(用户类)
class UserColleague : public Colleague {
public:
	UserColleague(const std::string& name, const std::shared_ptr<Mediator> mediator): Colleague(name, mediator) {}

	void send(const std::string& message) override {
		std::cout << "[ " << name_ << " ]: 发送消息: " << "{ " << message << " }" << std::endl;
		mediator_->sendMessage(message, name_);
	}

	void recv(const std::string& message, const std::string& sender) override {
		std::cout << "[ " << name_ << " ]: 收到来自" << "( " << sender << " )的消息: " << "{ " << message << " }" << std::endl;
	}
};

//具体中间者类(聊天室)
class ChatRoomMediator : public Mediator {
public:
	//添加用户到聊天室
	void addUser(std::shared_ptr<Colleague> user) override {
		users_.push_back(user);
	}

	//发送消息给其他用户
	void sendMessage(const std::string& message, const std::string& sender) override {
		for(const auto& user : users_) {
			//不将消息发送给自己
			if(user->name_ != sender) {
				user->recv(message, sender);
			}
		}
	}
private:
	std::vector<std::shared_ptr<Colleague>> users_;
};


#endif /* _MEDIATOR_H_ */
