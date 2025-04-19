#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

#include <iostream>
#include <memory>
#include <string>

//抽象产品 A
class Button {
public:
	virtual void render() const = 0;
	virtual ~Button() = default;
};

//抽象产品 B
class TextBox {
public:
	virtual void render() const = 0;
	virtual ~TextBox() = default;
};


//具体产品A1, windows 风格按钮
class WindowsButton : public Button {
public:
	void render() const override {
		std::cout << "渲染 Windows 风格按钮" << std::endl;
	}
};

//具体产品A2, Mac 风格按钮
class MacButton : public Button {
public:
	void render() const override {
		std::cout << "渲染 Mac 风格按钮" << std::endl;
	}
};

//具体产品B1, windows 风格文本框
class WindowsTextBox : public TextBox {
public:
	void render() const override {
		std::cout << "渲染 Windows 风格文本框" << std::endl;
	}
};

//具体产品B2, Mac 风格文本框
class MacTextBox : public TextBox {
	void render() const override {
		std::cout << "渲染 Mac 风格文本框" << std::endl;
	}
};

//抽象工厂: 定义创建一组产品的方法
class GUIAbstractFactory {
public:
	virtual std::unique_ptr<Button> createButton() const = 0;
	virtual std::unique_ptr<TextBox> createTextBox() const = 0;
	virtual ~GUIAbstractFactory() = default;
};


class WindowsFactory : public GUIAbstractFactory {
public:
	std::unique_ptr<Button> createButton() const override {
		return std::make_unique<WindowsButton>();
	}

	std::unique_ptr<TextBox> createTextBox() const override {
		return std::make_unique<WindowsTextBox>();
	}
};

class MacFactory : public GUIAbstractFactory {
public:
	std::unique_ptr<Button> createButton() const override {
		return std::make_unique<MacButton>();
	}

	std::unique_ptr<TextBox> createTextBox() const override {
		return std::make_unique<MacTextBox>();
	}
};


#endif /* _ABSTRACTFACTORY_H_ */
