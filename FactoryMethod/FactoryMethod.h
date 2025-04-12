#ifndef _FACTORY_METHOD_H_
#define _FACTORY_METHOD_H_

#include <iostream>
#include <memory>
#include <string>

//抽象产品
class Document {
public:
	virtual void open() const = 0;
	virtual ~Document() = default;
};

//具体产品
class WordDocument : public Document {
public:
	void open() const override {
		std::cout << "打开Word文档!" << std::endl;
	}
};

class PDFDocument : public Document {
public:
	void open() const override {
		std::cout << "打开PDF文档!" << std::endl;
	}
};

//抽象工厂类: 文档工厂接口
class DocumentFactory {
public:
	//工厂方法，返回一个抽象文档对象
	virtual std::unique_ptr<Document> createDocument() const = 0;
	virtual ~DocumentFactory() = default;
};

class WordDocumentFactory : public DocumentFactory {
public:
	std::unique_ptr<Document> createDocument() const override {
		return std::make_unique<WordDocument>();
	}
};

class PDFDocumentFactory : public DocumentFactory {
public:
	std::unique_ptr<Document> createDocument() const override {
		return std::make_unique<PDFDocument>();
	}
};



#endif /* _FACTORY_METHOD_H_ */
