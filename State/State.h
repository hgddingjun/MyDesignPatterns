#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include <memory>
#include <string>

//抽象状态类
class State {
public:
	virtual ~State() = default;
	virtual void insertCoin() = 0;        //投入硬币
	virtual void selectProduct() = 0;     //选择商品
	virtual void dispenseProduct() = 0;   //出货
};

//前向声明: 解决状态类相互引用的问题
class VendingMachine;
class HasCoinState;

//上下文类: 自动售货机
class VendingMachine {
public:
	void setState(std::shared_ptr<State> state) {
		currentState_ = state;
	}

	void insertCoin() {
		currentState_->insertCoin();
	}

	void selectProduct() {
		currentState_->selectProduct();
	}

	void dispenseProduct() {
		currentState_->dispenseProduct();
	}
private:
	std::shared_ptr<State> currentState_;
};

//具体状态类: 无硬币状态
class NoCoinState : public State {
public:
	explicit NoCoinState(VendingMachine* machine): machine_(machine) {} 

	void insertCoin() override {
		std::cout << "硬币已投入，进入有硬币的状态。" << std::endl;
		machine_->setState(std::static_pointer_cast<State>(std::make_shared<HasCoinState>(machine_)));
	}

	void selectProduct() override {
		std::cout << "请先投入硬币。" << std::endl;
	}

	void dispenseProduct() override {
		std::cout << "请先投入硬币并选择商品。" << std::endl;
	}
private:
	VendingMachine* machine_;
};

//具体状态类: 有硬币状态
class HasCoinState : public State {
public:
	explicit HasCoinState(VendingMachine* machine) : machine_(machine) {}

	void insertCoin() override {
		std::cout << "硬币已存在，请选择商品。" << std::endl;
	}

	void selectProduct() override {
		std::cout << "商品已选择，正在出货。" << std::endl;
		machine_->setState(std::static_pointer_cast<State>(std::make_shared<NoCoinState>(machine_)));
	}

	void dispenseProduct() override {
		std::cout << "请先选择商品。" << std::endl;
	}
private:
	VendingMachine* machine_;
};

#endif //_STATE_H_






