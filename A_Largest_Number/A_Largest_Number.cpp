// A_Largest_Number.cpp : 定义控制台应用程序的入口点。
// Given a list of non negative integers, arrange them such that they form the largest number.
// For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
// Note: The result may be very large, so you need to return a string instead of an integer.

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Key point in this problem: using this compare method
* to sort the vector containing the input num
* in this problem, to generate the largest formed number
* we need to compare two numbers to determine which number should be
* positioned before another one.
* for example: 30 and 34, we need to compare 3034 with 3430,
* then we found that 3430 > 3034.
* According the above example, we can find some tricky point
* just concatenate two numbers, and find the greatest result.
*/
bool is_larger(const string& s1, const string& s2) {
	return (s1 + s2) > (s2 + s1);
}

string largestNumber(vector<int> &num) {
	vector<string> v_str_num;
	for (vector<int>::iterator it = num.begin(); it != num.end(); it++) {
		v_str_num.push_back(to_string(*it));
	}

	sort(v_str_num.begin(), v_str_num.end(), is_larger);

	string result;
	for (vector<string>::iterator it = v_str_num.begin(); it != v_str_num.end(); it++) {
		result += *it;
	}

	std::size_t found = result.find_first_not_of("0");
	if (found != string::npos) {
		result = result.substr(found, result.size() - found);
		return result;
	}

	return "0";
}

// test sort function on vector contains string
void test1() {
	vector<string> v_nums;

	v_nums.push_back("94");
	v_nums.push_back("98");
	v_nums.push_back("9");

	sort(v_nums.begin(), v_nums.end());

	for (vector<string>::iterator it = v_nums.begin();
		it != v_nums.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
}

// test2 on largestNumber
void test2() {
	vector<int> num;
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	cout << "test2 on largest number:" << endl;
	cout << largestNumber(num) << endl;

	return;
}

// test3 on largestNumber 3, 30, 34, 5, 9
void test3() {
	vector<int> num;
	num.push_back(3);
	num.push_back(30);
	num.push_back(34);
	num.push_back(5);
	num.push_back(9);
	cout << "test3 on largest number:" << endl;
	cout << largestNumber(num) << endl;

	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();

	test2();

	test3();

	return 0;
}