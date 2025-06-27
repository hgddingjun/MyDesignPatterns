#include "Facade.h"

int main(void) {
	HomeTheaterFacade homeTheaterFacade;
	std::cout << "======开始观影======" << std::endl;
	homeTheaterFacade.startMovie("哪吒🟤童魔闹海");
	std::cout << "======观影完毕======" << std::endl;
	homeTheaterFacade.stopMovie();
	return 0;
}
