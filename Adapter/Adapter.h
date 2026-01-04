#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include <iostream>
#include <string>

//目标接口: 定义客户端需要的统一接口，抽象类
class MediaPlayer {
public:
	//定义播放器方法: 接收文件类型和文件名作为参数
	virtual void play(const std::string& mediaType, const std::string& fileName) = 0;
	virtual ~MediaPlayer() = default;
};

//适配者接口: Adaptee, 定义高级媒体播放器接口
class AdvancedMediaPlayer {
public:
	//播放MP4文件方法
	virtual void playMp4(const std::string& fileName) = 0;

	//播放AVI文件方法
	virtual void playAvi(const std::string& fileName) = 0;

	virtual ~AdvancedMediaPlayer()  = default;
};

//具体适配者，(concrete Adaptee) MP4播放器
class Mp4Player : public AdvancedMediaPlayer {
public:
	//实现播放MP4文件方法
	void playMp4(const std::string& fileName) override {
		std::cout << "Playing MP4 file: " << fileName << std::endl;
	}

	//不支持播放AVI文件
	void playAvi(const std::string& /*fileName*/) override {
		std::cout << "AVI format not be supported by Mp4Player." << std::endl;
	}
};

//具体适配者，(concrete Adaptee) AVI播放器
class AviPlayer : public AdvancedMediaPlayer {
public:
	//不支持播放MP4文件
	void playMp4(const std::string& /*fileName*/) override {
		std::cout << "MP4 format be not supported by AviPlayer." << std::endl;
	}

	//实现播放AVI文件方法
	void playAvi(const std::string& fileName) override {
		std::cout << "Playing AVI file: " << fileName << std::endl;
	}
};

//适配器:(Adapter) 将高级播放器接口适配成目标接口
class MediaAdapter : public MediaPlayer {
public:
	//根据媒体类型选择适配的高级播放器
	MediaAdapter(const std::string& mediaType) {
		if(mediaType == "mp4") {
			advancedMediaPlayer_ = new Mp4Player();
		} else if (mediaType == "avi") {
			advancedMediaPlayer_ = new AviPlayer();
		} else {
			advancedMediaPlayer_ = nullptr;
		}
	}

	//将目标接口的调用转换为高级播放器接口的调用
	void play(const std::string& mediaType, const std::string& fileName) override {
		if(mediaType == "mp4") {
			advancedMediaPlayer_->playMp4(fileName);
		} else if(mediaType == "avi") {
			advancedMediaPlayer_->playAvi(fileName);
		} else {
			std::cout << "Invalid media type: " << mediaType << std::endl;
		}
	}
	
	//析构释放内存资源
	virtual ~MediaAdapter() {
		if(advancedMediaPlayer_ != nullptr) {
			delete advancedMediaPlayer_;
		}
	}	
private:
	AdvancedMediaPlayer* advancedMediaPlayer_; //适配持有高级播放器的指针
};

//具体播放器类(Concrete Target): 实现默认播放器逻辑
class AudioPlayer : public MediaPlayer {
public:
	//实现统一的播放方法, 支持MP3, 并通过适配器支持MP4和AVI
	void play(const std::string& mediaType, const std::string& fileName) override {
		if(mediaType == "mp3") {
			//如果是MP3文件，直接播放
			std::cout << "Playing MP3 file: " << fileName << std::endl;
		} else if (mediaType == "mp4" || mediaType == "avi") {
			//对于MP4和AVI文件，使用适配器
			MediaAdapter adapter(mediaType);
			adapter.play(mediaType, fileName);
		} else {
			//不支持文件类型
			std::cout << "Unsupport media type: " << mediaType << std::endl;
		}
	}
};

#endif /* _ADAPTER_H_ */
