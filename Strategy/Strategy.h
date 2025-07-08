#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <iostream>
#include <string>
#include <memory>

//抽象策略: 定义计算价格的统一接口
class PricingStrategy {
public:
	virtual double calculatePrice(double originPrice) const = 0;
	virtual ~PricingStrategy() = default;
};

//具体策略1: 正常价格(无折扣)
class NormalPricing : public PricingStrategy {
public:
	double calculatePrice(double originPrice) const override {
		std::cout << "正常价格，无折扣。"; //<< std::endl;
		return originPrice;
	}
};

//具体策略2: 满减(满100减20)
class FullReductionPricing : public PricingStrategy {
public:
	double calculatePrice(double originPrice) const override {
		if(originPrice >= 100) {
			std::cout << "满减促销，满100减20活动。"; //<< std::endl;
			return originPrice - 20;
		} else {
			std::cout << "未达到满减条件，原价结算。"; //<< std::endl;
			return originPrice;
		}
	}
};

//具体策略3: 七折优惠
class DiscountPricing : public PricingStrategy {
public:
	double calculatePrice(double originPrice) const override {
		std::cout << "打折促销，七折优惠。"; //<< std::endl;
		return originPrice * 0.7;
	}
};

//上下文环境, 促销优惠来计算价格
class ShoppingCart {
public:
	void setPricingStrategy(std::shared_ptr<PricingStrategy> newStrategy) {
		strategy_ = newStrategy;
	}

	double calculateTotalPrice(double originPrice) const {
		if(strategy_) {
			return strategy_->calculatePrice(originPrice);
		} else {
			std::cout << "错误：未设置促销策略，按原价结算" << std::endl;
			return originPrice;
		}
	}
private:
	std::shared_ptr<PricingStrategy> strategy_;
};

#endif /* _STRATEGY_H_ */
