#include "Builder.h"

int main(void) {
	Director director;

	auto woodenBuilder = std::make_shared<WoodenHouseBuilder>();
	director.setBuilder(woodenBuilder);
	director.constructHouse();
	woodenBuilder->getHouse()->show();

	auto glassBuilder = std::make_shared<GlassHouseBuilder>();
	director.setBuilder(glassBuilder);
	director.constructHouse();
	glassBuilder->getHouse()->show();
	return 0;
}
