#include "Adapter.h"

int main() {
	AudioPlayer player;
	//测试播放mp3文件
	player.play("mp3", "song.mp3");

	//测试播放mp4文件
	player.play("mp4", "video.mp4");

	//测试播放avi文件
	player.play("avi", "movie.avi");

	//测试不支持的文件类型
	player.play("flv", "clip.flv");

	return 0;
}
