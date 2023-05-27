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
		cout << "�˺�δ�ɹ�����\n";
		return;
	}

	if (password == m_myAccount) {
		cout << "�˺������벻����ͬ\n";//������ͬ�𣿴��������
		return;
	}
	m_myPassword = password;
	ofstream file("account_and_password.txt", ios::app);
	if (file.is_open())
		file << password << endl;
	else cout << "�ļ�д������ʧ��\n";
	file.close();
}

void Users::setAccount(string account) {
	//cout << "set your account:\n";
	//cin >> account;
	fstream file("account_and_password.txt", ios::in);
	string searchStr = account;  // Ҫ���ҵ�����
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line == searchStr) {
				cout << "�˺��Ѵ���\n";
				return;
			}
		}
	}
	else { cout << "����˺��Ƿ��ظ�ʱ�ļ��򿪴���\n"; }
	file.close();

	file.open("account_and_password.txt", ios::app|ios::out);
	m_myAccount = account;
	if (file.is_open()) {
		file << account << endl;
		cout << "�˺ųɹ�д��\n";
	}
	file.close();
}

void Users::changePassword(string newPassword) {
	fstream file("account_and_password.txt", ios::in | ios::out);
	fstream tempfile("tempfile.txt", ios::app);
	if (!file) {
		std::cout << "�޷���ԭʼ�ļ���" << endl;
		return ;
	}
	if (!tempfile) {
		cout << "�޷�����ʱ�ļ�" << endl;
		return;
	}

	// ��λ��Ҫ�滻��λ��
	file.seekg(0, std::ios::beg);

	// ��ȡ�ļ�����
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
		// �ر��ļ�
		file.close();
		tempfile.close();
		remove("account_and_password.txt");
		rename("tempfile.txt", "account_and_password.txt");
}

bool Users::isRight(string account, string password)  {
	ifstream file("account_and_password.txt", ios::app);
	string searchStr = account;  // Ҫ���ҵ�����

	if (file.is_open()) {
		string line;
		bool found = false;

		while (getline(file, line)) {
			// ��������
			if (line==account) {
				found = true;
				continue;  // �ҵ�Ŀ�����ݣ�������һ��ѭ��
			}

			if (found && line == password) {
				return true; 
			}
			else if (found && line != password) {
				cout << "�������";
				return false;
			}
		}

		if (!found) {
			//����ĩβ��û���ҵ��˺�
				cout << "��������ȷ���˺�\n"; return false;
		}
		file.close();
	}

	//û�гɹ����ļ�
	else {
		cout << "�˺������ļ���ȡ����\n";
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







