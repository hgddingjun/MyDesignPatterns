#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

//抽象组件类
class Component {
public:
	//展示信息的接口，所有子类都必须实现
	virtual void display(int depth) const = 0;

	//以下两个接口仅供组合节点使用，叶子节点不需要实现
	virtual void add(std::shared_ptr<Component> component) {
		(void) component;
	}
	virtual void remove(std::shared_ptr<Component> component) {
		(void) component;
	}

	virtual ~Component() = default;
};

//叶子节点：Employee员工
class Employee : public Component {
public:
	explicit Employee(const std::string& name): name_(name) {}

	void display(int depth) const override {
		std::cout << std::string(depth, '-') << "员工:" << name_ << std::endl;
	}

private:
	std::string name_;
};

//组合节点类：department部门
class Department : public Component {
public:
	explicit Department(const std::string& name): name_(name) {}

	void display(int depth) const override {
		std::cout << std::string(depth, '-') << "部门:" << name_ << std::endl;

		//遍历所有子节点，递归调用他们的display方法
		for(const auto& c : children_) {
			c->display(depth + 2);
		}
	}

	void add(std::shared_ptr<Component> component) override {
		children_.push_back(component);
	}

	void remove(std::shared_ptr<Component> component) override {
		children_.erase(
			std::remove(children_.begin(), children_.end(), component),
			children_.end()
		);
	}

private:
	std::string name_; //部门名称
	std::vector<std::shared_ptr<Component>> children_; //子节点集合
};

#endif/* _COMPONENT_H_ */
