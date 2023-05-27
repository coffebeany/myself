#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include"Sharedfile.h"
using namespace std;


// ����������ͳ���ַ�������Ŀ���ַ�����ͬ���ַ���
int Sharedfile::countMatchingCharacters(const std::string& str, const std::string& target) {
	int count = 0;
	for (char ch : str) {
		if (target.find(ch) != std::string::npos) {
			count++;
		}
	}
	return count;
}


void Sharedfile::search(string searchline) {
	string filename = "file_list.txt";  // �ļ������ı��ļ�·��
	ifstream file(filename);
	if (!file) {
		cout << "�����ļ��б��ʧ��" << endl;
		return ;
	}

	map<string, int> matches;  // ���ڴ洢ƥ����ļ����ּ�����ִ���

	string line;
	while (getline(file, line)) {
		int matchCount = countMatchingCharacters(line, searchline);
		if (matchCount == 0)continue;
		matches[line] = matchCount;
	}

	file.close();

	// ��ƥ�������ճ��ִ����Ӷൽ������
	vector<pair<string, int>> sortedMatches(matches.begin(), matches.end());
	sort(sortedMatches.begin(), sortedMatches.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
		});

	// ��������Ľ��
	for (const auto& match : sortedMatches) {
		cout << match.first << " (" << match.second << " matches)" << endl;
	}
	return ;
	}










