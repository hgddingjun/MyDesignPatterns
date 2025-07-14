#include "Mediator.h"

int main(void) {
	//创建聊天室(中介者)
	auto chatRoom = std::make_shared<ChatRoomMediator>();

	//创建用户并加入聊天室
	auto user1 = std::make_shared<UserColleague>("张三", chatRoom);
	auto user2 = std::make_shared<UserColleague>("李四", chatRoom);
	auto user3 = std::make_shared<UserColleague>("王五", chatRoom);

	chatRoom->addUser(user1);
	chatRoom->addUser(user2);
	chatRoom->addUser(user3);

	//用户发送消息
	user1->send("大家好，我叫张三！");
	user2->send("张三你好，我叫李四！");
	user3->send("张三李四，你们好，我叫王五！");
	return 0;
}
