#include "Bridge.h"

int main(void) {
	std::shared_ptr<ScreenDrawingAPI> screenAPI = std::make_shared<ScreenDrawingAPI>();
	std::shared_ptr<PrinterDrawingAPI> printerAPI = std::make_shared<PrinterDrawingAPI>();

	Circle c1(1, 2, 3, screenAPI);
	Circle c2(4, 5, 6, printerAPI);

	c1.draw();
	c2.draw();

	c1.resize(2.0);
	c1.draw();
	return 0;
}
