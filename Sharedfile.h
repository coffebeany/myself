#pragma once
#ifndef SHAREDFILE_H
#define SHAREDFILE_H
#include<string>
using namespace std;

class Sharedfile {
private:
	string m_link;
	string m_code;
	string m_title;
	long m_subscribe=0;
	long m_like=0;
public:
	void display();
	void like();
	void subscribe();
	void setInfo();
	static void search(string);
	static int countMatchingCharacters(const string&, const string&);
	static void deleteStaff();
};


#endif // !SHAREDFILE_H