#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>
#include <string>
#include <memory>

//1. 抽象组件: 定义所有饮料基本行为接口
class Beverage {
public:
	virtual std::string getDescription() const = 0;
	virtual double cost() const = 0;
	virtual ~Beverage() = default;
};

//2. 具体组件: 基础咖啡(黑咖啡)
class BlackCoffee : public Beverage {
public:
	std::string getDescription() const override {
		return "黑咖啡";
	}

	double cost() const override {
		return 5.0;
	}
};

//3. 抽象装饰器: 持有一个Beverage指针，用于扩展功能
class BeverageDecorator : public Beverage {
public:
	explicit BeverageDecorator(std::shared_ptr<Beverage> b): beverage_(std::move(b)) {}
	virtual ~BeverageDecorator() = default;

protected:
	std::shared_ptr<Beverage> beverage_;
}; 

//4. 具体装饰器: 实现动态扩展功能
//4.1 牛奶装饰器
class MilkDecorator : public BeverageDecorator {
public:
	explicit MilkDecorator(std::shared_ptr<Beverage> b): BeverageDecorator(std::move(b)) {}
	std::string getDescription() const override {
		return beverage_->getDescription() + " + 牛奶";
	}

	double cost() const override {
		return beverage_->cost() + 1.0;
	}
};

//4.2 糖装饰器
class SugarDecorator : public BeverageDecorator {
public:
	explicit SugarDecorator(std::shared_ptr<Beverage> b): BeverageDecorator(std::move(b)) {}
	std::string getDescription() const override {
		return beverage_->getDescription() + " + 糖";
	}

	double cost() const override {
		return beverage_->cost() + 0.5;
	}
};

//4.3 巧克力装饰器
class ChocolateDecorator : public BeverageDecorator {
public:
	explicit ChocolateDecorator(std::shared_ptr<Beverage> b): BeverageDecorator(std::move(b)) {}
	std::string getDescription() const override {
		return beverage_->getDescription() + " + 巧克力";
	}

	double cost() const override {
		return beverage_->cost() + 2.0;
	}
};

#endif /* _DECORATOR_H_ */
