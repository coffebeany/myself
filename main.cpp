#include<string>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"Users.h"
#include"Sharedfile.h"
using namespace std;



void logIn(string account, string psd, Users* &user) {
	cout << "�����˺ţ�\n";
	cin >> account;
	cout << "�������룺\n";
	cin >> psd;
	if (Users::isRight(account, psd)) {
		user->login_account(account, psd);
	}
}

void signUp(string account,string psd,Users* &user) {
	cout << "�����˺ţ�\n";
	cin >> account;
	cout << "�������룺\n";
	cin >> psd;
		user->setAccount(account);
		user->setPassword(psd);
}



int main() {
	//Users* currUser=new Users;
	//currUser->setAccount("777899923");
	//currUser->setPassword("2004yk");
	//logIn("777899923", "2004yk", currUser);
	Sharedfile::search("˼��mooc");

	//delete currUser;
}

