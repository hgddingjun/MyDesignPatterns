#ifndef _IMAGE_H_
#define _IMAGE_H_

//#include <iostream>
//#include <string>
//#include <memory>

//抽象图片接口
class Image {
public:
	virtual void display() = 0;
	virtual ~Image() = default;
};

class RealImage : public Image {
public:
	RealImage(const std::string& fileName):
		fileName_(fileName) {
		loadFromDisk();
	}
	void display() override {
		std::cout << "显示图片:" << fileName_ << std::endl;
	}
private:
	std::string fileName_;
	void loadFromDisk() {
	//模拟加载图片
		std::cout << "加载图片:" << fileName_ << std::endl;
	}
};

class ProxyImage : public Image {
public:
	ProxyImage(const std::string& fileName):
		fileName_(fileName) {}
	void display() override {
		if(!realImage_) {
			realImage_ = std::make_unique<RealImage>(fileName_);
		}
		realImage_->display();
	}

private:
	std::string fileName_;
	std::unique_ptr<RealImage> realImage_;
};

#endif /* _IMAGE_H_ */
