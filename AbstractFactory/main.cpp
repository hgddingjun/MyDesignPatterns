#include "AbstractFactory.h"


//客户端代码: 通过工厂创建和使用产品
void renderUI(GUIAbstractFactory& factory) {
	auto button = factory.createButton();
	auto textBox = factory.createTextBox();

	button->render();
	textBox->render();
}

int main(void) {
	//使用 windows 工厂创建产品
	std::cout << "Windows UI" << std::endl;
	WindowsFactory windowsFactroy;
	renderUI(windowsFactroy);

	//使用 Mac 工厂创建产品
	std::cout << "Mac UI" << std::endl;
	MacFactory macFactory;
	renderUI(macFactory);
	return 0;
}
