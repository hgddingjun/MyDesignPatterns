#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

//#include <iostream>
//#include <string>
//#include <memory>

class BankAccount {
public:
	virtual void showBalance() = 0; //查看余额
	virtual ~BankAccount() = default;
};

class RealBankAccount : public BankAccount {
public:
	RealBankAccount(double balance): balance_(balance) {}
	void showBalance() override {
		std::cout << "账户余额: $" << balance_ << std::endl;
	}
private:
	double balance_;
};

class BankAccountProxy : public BankAccount {
public:
	BankAccountProxy(double balance, const std::string& role): 
		role_(role),realBankAccount_(std::make_unique<RealBankAccount>(balance)) {}

	void showBalance() override {
		if(role_ == "admin") {
			realBankAccount_->showBalance();
		} else {
			std::cout << "访问被拒绝: 只有管理员才有权限查看余额." << std::endl;
		}
	}
private:
	std::string role_;
	std::unique_ptr<RealBankAccount> realBankAccount_;
};

#endif /* _BANK_ACCOUNT_H_ */
