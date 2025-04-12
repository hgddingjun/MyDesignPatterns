#include "FactoryMethod.h"
void client_test(const DocumentFactory& factory) {
	//使用工厂方法创建文档
	auto document = factory.createDocument();
	//打开文档
	document->open();
}

int main() {
	std::cout << "使用Word文档工厂:" << std::endl;
	WordDocumentFactory wordFactroy;
	client_test(wordFactroy);

	std::cout << "使用PDF文档工厂:" << std::endl;
	PDFDocumentFactory pdfFactory;
	client_test(pdfFactory);

	return 0;
}
