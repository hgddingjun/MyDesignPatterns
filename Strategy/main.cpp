#include "Strategy.h"

int main(void) {
	double originPrice = 150;  //原始价格
	ShoppingCart shoppingCart; //创建购物车
	
	shoppingCart.setPricingStrategy(std::make_shared<NormalPricing>());
	std::cout << "最终价格：{" << shoppingCart.calculateTotalPrice(originPrice) << "} 元。" << std::endl;

	shoppingCart.setPricingStrategy(std::make_shared<FullReductionPricing>());
	std::cout << "最终价格：{" << shoppingCart.calculateTotalPrice(originPrice) << "} 元。" << std::endl;
	
	shoppingCart.setPricingStrategy(std::make_shared<DiscountPricing>());
	std::cout << "最终价格：{" << shoppingCart.calculateTotalPrice(originPrice) << "} 元。" << std::endl;
	
	return 0;
}
