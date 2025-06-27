#ifndef _FACADE_H_
#define _FACADE_H_

#include <iostream>
#include <string>

//子系统1: 播放器
class Player {
public:
	void turnOn() {
		std::cout << "播放器==>[已打开]" << std::endl;
	}

	void turnOff() {
		std::cout << "播放器==>[已关闭]" << std::endl;
	}

	void playMovie(const std::string& movie) {
		std::cout << "播放器==>[正在播放<" << movie << ">电影]" << std::endl;
	}
};

//子系统2: 投影仪
class Projector {
public:
	void turnOn() {
		std::cout << "投影仪==>[已打开]" << std::endl;
	}

	void turnOff() {
		std::cout << "投影仪==>[已关闭]" << std::endl;
	}

	void setMode(const std::string& mode) {
		std::cout << "投影仪==>[模式设置为<" << mode << ">]" << std::endl;
	}
};

//子系统3: 音响
class SoundSystem {
public:
	void turnOn() {
		std::cout << "音响系统==>[已打开]" << std::endl;
	}

	void turnOff() {
		std::cout << "音响系统==>[已关闭]" << std::endl;
	}

	void setVolume(int level) {
		std::cout << "音响系统==>[音量设置为<" << level << ">]" << std::endl;
	}
};

//子系统4: 灯光
class LightSystem {
public:
	void dimLights() {
		std::cout << "灯光系统==>[已打开]" << std::endl;
	}

	void brightLights() {
		std::cout << "灯光系统==>[已关闭]" << std::endl;
	}
};

//外观类: 家庭影院外观
class HomeTheaterFacade {
public:
	HomeTheaterFacade() {}

	//一键启动家庭影院
	void startMovie(const std::string& movie) {		std::cout << "正在启动家庭影院系统..." << std::endl;
		lightSystem_.dimLights();
		player_.turnOn();
		projector_.turnOn();
		projector_.setMode("影院模式");
		soundSystem_.turnOn();
		soundSystem_.setVolume(50);
		player_.playMovie(movie);
		std::cout << "家庭影院已经准备就绪，请享受您的电影！" << std::endl;
	}

	//一键关闭家庭影院
	void stopMovie() {
		std::cout << "正在关闭家庭影院系统..." << std::endl;
		player_.turnOff();
		projector_.turnOff();
		soundSystem_.turnOff();
		lightSystem_.brightLights();
		std::cout << "家庭影院系统已经关闭..." << std::endl;
	}

private:
	Player player_;
	Projector projector_;
	SoundSystem soundSystem_;
	LightSystem lightSystem_;
};

#endif /* _FACADE_H_ */
