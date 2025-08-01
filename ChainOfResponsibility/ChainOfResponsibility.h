#ifndef _CHAIN_OF_RESPONSIBILITY_
#define _CHAIN_OF_RESPONSIBILITY_

#include <iostream>
#include <string>
#include <memory>

//抽象处理者类
class Handler {
public:
	//设置下一个处理者
	void setNextHandler(std::shared_ptr<Handler> handler) {
		nextHandler_ = handler;
	}

	//处理请求接口
	virtual void handleRequest(double amount) {
		if(nextHandler_) {
			nextHandler_->handleRequest(amount);
		} else {
			std::cout << "没有人可以处理金额为:" << amount << "元的请求，申请被拒绝!" << std::endl;
		}
	}

	virtual ~Handler() = default;
protected:
	std::shared_ptr<Handler> nextHandler_;
};

//具体处理者: 部门经理
class DepartmentManager : public Handler {
public:
	void handleRequest(double amount) override {
		if(amount <= 500) {
			std::cout << "部门经理审批通过，报销金额为:" << amount << "元。" << std::endl;
		} else if (nextHandler_) {
			std::cout << "部门经理无法处理金额为:" << amount << "元的请求，交给下一个处理者。" << std::endl;
			nextHandler_->handleRequest(amount);
		} else {
			std::cout << "金额过高，部门经理无法处理！" << std::endl;
		}
	}
};

//具体处理者: 财务经理
class FinanceManager : public Handler {
public:
	void handleRequest(double amount) override {
		if(amount > 500 && amount <=1000) {
			std::cout << "财务经理审批通过，报销金额为:" << amount << "元。" << std::endl;
		} else if (nextHandler_) {
			std::cout << "财务经理无法处理金额为:" << amount << "元的请求，交给下一个处理者。" << std::endl;
			nextHandler_->handleRequest(amount);
		} else {
			std::cout << "金额过高，财务经理无法处理！" << std::endl;
		}
	}
};

//具体处理者: 总经理
class GeneralManager : public Handler {
public:
	void handleRequest(double amount) override {
		if(amount > 1000) {
			std::cout << "总经理审批通过，报销金额为:" << amount << "元。" << std::endl;
		} else if (nextHandler_) {
			nextHandler_->handleRequest(amount);
		} else {
			std::cout << "请求金额无法处理！" << std::endl;
		}
	}
};


#endif /* _CHAIN_OF_RESPONSIBILITY_ */
