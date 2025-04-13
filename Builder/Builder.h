#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <iostream>
#include <memory>
#include <string>

class House {
public:
	void setFoundation(const std::string& foundation ) {
		foundation_ = foundation;
	}

	void setStructure(const std::string& structure) {
		structure_ = structure;
	}

	void setRoof(const std::string& roof) {
		roof_ = roof;
	}

	void show() const {
		std::cout << "房子地基:" << foundation_ << ", 结构:" << structure_ << ", 屋顶:" << roof_ << std::endl;
	}

private:
	std::string foundation_;
	std::string structure_;
	std::string roof_;
};


//抽象建造者类: 定义房子的建造步骤
class HouseBuilder {
public:
	virtual ~HouseBuilder() = default;
	virtual void buildFoundation() = 0;
	virtual void buildStructure() = 0;
	virtual void buildRoof() = 0;
	virtual std::shared_ptr<House> getHouse() = 0;
};

class WoodenHouseBuilder : public HouseBuilder {
public:
	WoodenHouseBuilder() {
		house_ = std::make_shared<House>();
	}

	void buildFoundation() override {
		house_->setFoundation("木制地基");
	}

	void buildStructure() override {
		house_->setStructure("木质结构");
	}

	void buildRoof() override {
		house_->setRoof("木制屋顶");
	}

	std::shared_ptr<House> getHouse() override {
		return house_;
	}

private:
	std::shared_ptr<House> house_;
};


class GlassHouseBuilder : public HouseBuilder {
public:
	GlassHouseBuilder() {
		house_ = std::make_shared<House>();
	}

	void buildFoundation() override {
		house_->setFoundation("玻璃地基");
	}

	void buildStructure() override {
		house_->setStructure("玻璃结构");
	}

	void buildRoof() override {
		house_->setRoof("玻璃屋顶");
	}

	std::shared_ptr<House> getHouse() override {
		return house_;
	}

private:
	std::shared_ptr<House> house_;
};

//指挥者类: 负责控制建造流程
class Director {
public:
	void setBuilder(std::shared_ptr<HouseBuilder> housebuilder) {
		house_builder_ = housebuilder;
	}

	//按照固定步骤建造房子
	void constructHouse() {
		if(house_builder_) {
			house_builder_->buildFoundation();
			house_builder_->buildStructure();
			house_builder_->buildRoof();
		}

	}

private:
	std::shared_ptr<HouseBuilder> house_builder_;

};

#endif/* _BUILDER_H_ */
