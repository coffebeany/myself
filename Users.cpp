#include<string>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"Users.h"
using namespace std;

void Users::setPassword(string password) {
	//cout << "set your password:\n";
	//cin >> password;
	if (m_myAccount == "0") {
		cout << "账号未成功创建\n";
		return;
	}

	if (password == m_myAccount) {
		cout << "账号与密码不能相同\n";//可以相同吗？待解决问题
		return;
	}
	m_myPassword = password;
	ofstream file("account_and_password.txt", ios::app);
	if (file.is_open())
		file << password << endl;
	else cout << "文件写入密码失败\n";
	file.close();
}

void Users::setAccount(string account) {
	//cout << "set your account:\n";
	//cin >> account;
	fstream file("account_and_password.txt", ios::in);
	string searchStr = account;  // 要查找的内容
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line == searchStr) {
				cout << "账号已存在\n";
				return;
			}
		}
	}
	else { cout << "检查账号是否重复时文件打开错误\n"; }
	file.close();

	file.open("account_and_password.txt", ios::app|ios::out);
	m_myAccount = account;
	if (file.is_open()) {
		file << account << endl;
		cout << "账号成功写入\n";
	}
	file.close();
}

void Users::changePassword(string newPassword) {
	fstream file("account_and_password.txt", ios::in | ios::out);
	fstream tempfile("tempfile.txt", ios::app);
	if (!file) {
		std::cout << "无法打开原始文件！" << endl;
		return ;
	}
	if (!tempfile) {
		cout << "无法打开临时文件" << endl;
		return;
	}

	// 定位到要替换的位置
	file.seekg(0, std::ios::beg);

	// 读取文件内容
	string line;
	size_t currPosition;
	while (getline(file, line)) {
		if (line == m_myAccount) {
			tempfile << line << endl;
			getline(file, line);
			line = newPassword;
			tempfile << line<<endl;
			continue;
		}
		tempfile << line << endl;
	}
		// 关闭文件
		file.close();
		tempfile.close();
		remove("account_and_password.txt");
		rename("tempfile.txt", "account_and_password.txt");
}

bool Users::isRight(string account, string password)  {
	ifstream file("account_and_password.txt", ios::app);
	string searchStr = account;  // 要查找的内容

	if (file.is_open()) {
		string line;
		bool found = false;

		while (getline(file, line)) {
			// 查找内容
			if (line==account) {
				found = true;
				continue;  // 找到目标内容，继续下一次循环
			}

			if (found && line == password) {
				return true; 
			}
			else if (found && line != password) {
				cout << "密码错误";
				return false;
			}
		}

		if (!found) {
			//到了末尾还没有找到账号
				cout << "请输入正确的账号\n"; return false;
		}
		file.close();
	}

	//没有成功打开文件
	else {
		cout << "账号密码文件读取出错\n";
		return false;
	}
}

Users::Users(string account, string psd) {
	Users::setAccount(account);
	Users::setPassword(psd);
}

Users::Users() {
	string m_myAccount = "0";
	string m_myPassword = "0";
}

void Users::login_account(string account, string psd) {
	m_myAccount = account;
	m_myPassword = psd;
}







