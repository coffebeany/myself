#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include"Sharedfile.h"
using namespace std;


// 辅助函数：统计字符串中与目标字符串相同的字符数
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
	string filename = "file_list.txt";  // 文件名字文本文件路径
	ifstream file(filename);
	if (!file) {
		cout << "查找文件列表打开失败" << endl;
		return ;
	}

	map<string, int> matches;  // 用于存储匹配的文件名字及其出现次数

	string line;
	while (getline(file, line)) {
		int matchCount = countMatchingCharacters(line, searchline);
		if (matchCount == 0)continue;
		matches[line] = matchCount;
	}

	file.close();

	// 将匹配结果按照出现次数从多到少排序
	vector<pair<string, int>> sortedMatches(matches.begin(), matches.end());
	sort(sortedMatches.begin(), sortedMatches.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
		});

	// 输出排序后的结果
	for (const auto& match : sortedMatches) {
		cout << match.first << " (" << match.second << " matches)" << endl;
	}
	return ;
	}










