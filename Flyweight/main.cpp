#include "Flyweight.h"

int main(void) {
	FlyweightFactory flyweightFactory;
	auto characterA = flyweightFactory.getFlyweight('A');
	auto characterB = flyweightFactory.getFlyweight('B');
	auto characterC = flyweightFactory.getFlyweight('C');

	auto characterA2 = flyweightFactory.getFlyweight('A');

	characterA->display("微软雅黑", 12, "红色");
	characterB->display("宋体", 14, "蓝色");
	characterC->display("楷体", 10, "黑色");
	characterA2->display("黑体", 16, "绿色");

	//输出享元对象个数
	std::cout << "享元对象总数:(" << flyweightFactory.getFlyweightSize() << ")个." << std::endl;
	return 0;
}
