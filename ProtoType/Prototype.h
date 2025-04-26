#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include <iostream>
#include <memory>
#include <string>

//抽象原型类
class Shape {
public:
	virtual ~Shape() = default;

	//克隆方法，返回一个复制对象
	virtual std::shared_ptr<Shape> clone() const = 0;

	//显示信息接口
	virtual void draw() const = 0;

	//设置名称
	virtual void setName(const std::string& name) {
		name_ = name;
	}

	//获取名称
	virtual std::string getName() const {
		return name_;
	}

private:
	std::string name_;

};

class Circle : public Shape {
public:
	Circle(double radius) : radius_(radius) {}

	//实现克隆方法
	std::shared_ptr<Shape> clone() const override {
		return std::make_shared<Circle>(*this);
	}

	//显示圆形信息
	void draw() const override {
		std::cout << "圆形对象 [" << getName() << "], 半径为: " << radius_ << std::endl;
	}

private:
	double radius_;
};


class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : width_(width), height_(height) {}

	//实现克隆方法
	std::shared_ptr<Shape> clone() const override {
		return std::make_shared<Rectangle>(*this);
	}

	//显示矩形信息
	void draw() const override {
		std::cout << "矩形对象 [" << getName() << "], 宽为: " << width_ << ", 高为: " << height_ << std::endl;
	}

private:
	double width_;
	double height_;
};







#endif /* _PROTOTYPE_H_ */
