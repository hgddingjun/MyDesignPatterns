#include "TemplateMethod.h"

int main() {
	std::cout << "制作咖啡: " << std::endl;
	Coffee coffee;
	coffee.prepareRecipe();

	std::cout << "\n制作茶: " << std::endl;
	Tea tea;
	tea.prepareRecipe();
	return 0;
}
