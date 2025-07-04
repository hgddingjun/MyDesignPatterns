#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

//抽象享元类: Flyweight
class Flyweight {
public:
	virtual void display(const std::string& font, int size, const std::string& color) = 0;
	virtual ~Flyweight() = default;
};

//具体享元类: ConcreteFlyweight
class ConcreteFlyweight : public Flyweight {
public:
	explicit ConcreteFlyweight(char is) : internalState_(is) {}
	void display(const std::string& font, int size, const std::string& color) override {
		std::cout << "字符:[" << internalState_
			<< "],字体:[" << font
			<< "],大小:[" << size
			<< "],颜色:[" << color
			<< "]" << std::endl;
	}

private:
	char internalState_;
};

//享元工厂类: FlyweightFactory
class FlyweightFactory {
public:
	//获取享元对象
	std::shared_ptr<Flyweight> getFlyweight(char c) {
		if(flyweights_.find(c) == flyweights_.end()) {
			flyweights_[c] = std::make_shared<ConcreteFlyweight>(c);
			std::cout << "创建新的享元对象:" << c << std::endl;
		}
		return flyweights_[c];
	}
	size_t getFlyweightSize() const {
		return flyweights_.size();
	}
private:
	std::unordered_map<char, std::shared_ptr<Flyweight>> flyweights_; //存储享元对象
};



#endif /* _FLYWEIGHT_H_ */
