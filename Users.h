#pragma once
#ifndef USERS_H
#define USERS_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Users {

private:
	string m_myAccount="0";
	string m_myPassword="0";


public:
	static bool isRight(string, string);
	Users(string, string);
	Users();
	void setAccount(string);
	void setPassword(string);
	void changePassword(string);
	void login_account(string,string);

};

#endif // !USERS_H


