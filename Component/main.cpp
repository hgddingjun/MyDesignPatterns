#include "Component.h"

int main(void) {
	//创建叶子节点，员工
	auto employee1 = std::make_shared<Employee>("张三");
	auto employee2 = std::make_shared<Employee>("李四");
	auto employee3 = std::make_shared<Employee>("王五");
	
	//创建组合节点，部门
	auto department1 = std::make_shared<Department>("人力资源部");
	auto department2 = std::make_shared<Department>("技术部");

	//给部门添加员工
	department1->add(employee1);
	department2->add(employee2);
	department2->add(employee3);

	//创建公司根节点
	auto company = std::make_shared<Department>("总部");

	//将部门加入公司
	company->add(department1);
	company->add(department2);

	company->display(0);
	
	//删除员工2
	std::cout << "-删除员工2-" << std::endl;
	department2->remove(employee2);
	company->display(0);
	return 0;
}
