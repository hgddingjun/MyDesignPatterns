#ifndef _TEMPLATE_METHOD_H_
#define _TEMPLATE_METHOD_H_

#include <iostream>
#include <string>

//抽象类 饮品
class Beverage {
public:
	//模版方法: 定义制作饮品的流程
	void prepareRecipe() {
		boilWater();        //煮沸水,固定步骤
		brew();             //冲泡  (具体饮品不同)
		pourInCup();        //倒入杯中,固定步骤
		addCondiments();    //加配料 (具体饮品不同)
	}

protected:
	//固定步骤: 煮水
	void boilWater() {
		std::cout << "将水煮沸。" << std::endl;
	}
	
	//固定步骤: 倒入杯中
	void pourInCup() {
		std::cout << "将饮品倒入杯中。" << std::endl;
	}

	//抽象步骤: 冲水(需要子类实现)
	virtual void brew() = 0;

	//抽象步骤: 加配料(需要子类实现)
	virtual void addCondiments()  = 0;

	//虚析构函数，正确释放资源
	virtual ~Beverage() = default;
};

//具体类: 咖啡
class Coffee : public Beverage {
protected:
	//实现冲泡步骤
	void brew() override {
		std::cout << "用沸水冲泡咖啡。" << std::endl;
	}

	//实现加配料步骤
	void addCondiments() override {
		std::cout << "加入糖和牛奶。" << std::endl;
	}
};

//具体类: 茶
class Tea : public Beverage {
	//实现冲泡步骤
	void brew() override {
		std::cout << "用沸水冲泡茶叶。" << std::endl;
	}

	//实现加配料步骤
	void addCondiments() override {
		std::cout << "加入柠檬。" << std::endl;
	}
};


#endif /*_TEMPLATE_METHOD_H_*/
