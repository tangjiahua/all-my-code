#include "pch.h"
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int x[40025], y[40025], ans[40025];
string str;
int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	//转换s1与s2
	int s1_len, s2_len, ans_len;
	s1_len = s1.length();
	s2_len = s2.length();
	for (int i = 1; i <= s1_len; i++) {
		x[i] = s1[s1_len - i] - '0';
	}
	for (int i = 1; i <= s2_len; i++) {
		y[i] = s2[s2_len - i] - '0';
	}
	//乘积运算
	for (int i = 1; i <= s1_len; i++) {
		for (int j = 1; j <= s2_len; j++) {
			ans[i + j - 1] += x[i] * y[j];
		}
	}
	//将ans每位转换为一位的数字
	for (int i = 1; i <= s1_len + s2_len+2; i++) {//最多到s1_len+s2_len位这么多
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans[i] % 10;
	}

	if (ans[s1_len + s2_len] == 0) ans_len = s1_len + s2_len - 1;
	else ans_len = s1_len + s2_len;
	for (int i = ans_len; i >= 1; i--) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}