#include "Prototype.h"

int main()
{
	std::shared_ptr<Shape> circlePrototype = std::make_shared<Circle>(10.0);
	circlePrototype->setName("原始圆形");

	std::shared_ptr<Shape> rectanglePrototype = std::make_shared<Rectangle>(20.0, 16.0);
	rectanglePrototype->setName("矩形对象");

	std::shared_ptr<Shape> cloneCircle = circlePrototype->clone();
	cloneCircle->setName("拷贝圆形");

	std::shared_ptr<Shape> cloneRectangle = rectanglePrototype->clone();
	cloneRectangle->setName("拷贝矩形");

	std::cout << "=======原始对象======" << std::endl;
	circlePrototype->draw();
	rectanglePrototype->draw();

	std::cout << "======拷贝对象======" << std::endl;
	cloneCircle->draw();
	cloneRectangle->draw();
	return 0;
}
