#ifndef _BRIDGE_H_
#define _BRIDGE_H_

#include <iostream>
#include <string>
#include <memory>

//绘图接口，抽象类
class DrawingAPI {
public:
	virtual void drawCircle(double x, double y, double radius) = 0;
	virtual ~DrawingAPI() = default;
};

//具体实现，屏幕绘制
class ScreenDrawingAPI : public DrawingAPI {
public:
	void drawCircle(double x, double y, double radius) override {
		std::cout << "在屏幕上绘制圆形，位置(" << x << "," << y << ")" << ", 半径:" << radius << std::endl;
	}
};

//具体实现，打印机绘制
class PrinterDrawingAPI : public DrawingAPI {
public:
	void drawCircle(double x, double y, double radius) override {
		std::cout << "在打印机上绘制圆形，位置(" << x << "," << y << ")" << ", 半径:" << radius << std::endl;
	}
};


//图形类，抽象类
class Shape {
protected:
	std::shared_ptr<DrawingAPI> drawingAPI_;
public:
	Shape(std::shared_ptr<DrawingAPI> api): drawingAPI_(api) {}
	virtual void draw() = 0;
	virtual void resize(double factor) = 0;
	virtual ~Shape() = default;
};

//具体图形类，圆形
class Circle : public Shape {
private:
	double x_;
	double y_;
	double radius_;
public:
	Circle(double x, double y, double radius, std::shared_ptr<DrawingAPI> api):
		Shape(api), x_(x), y_(y), radius_(radius) {}

	void draw() override {
		drawingAPI_->drawCircle(x_, y_, radius_);
	}

	void resize(double factor) override {
		radius_ *= factor;
	}
};

#endif /* _BRIDGE_H_ */
