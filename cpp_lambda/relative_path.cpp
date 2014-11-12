/*************************************************************************
	>    File Name: relative_path.cpp
	>       Author: huangjinqiang
	>        Email: ligelaige@gmail.com
	> Created Time: Thu 13 Nov 2014 01:59:18 AM CST
	>      Compile: g++ relative_path.cpp -std=c++14
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

auto split(const string &s, const char delim = ' ')
{
	stringstream ss(s);
	string item;
	vector<string> elems;

	while(getline(ss, item, delim) != NULL)
	{
		elems.push_back(item);
	}
	return  elems;
}

int main(void)
{
	string a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	auto diffpath = [](const string &a, const string &b) {
		int i = 0, k = 0;
		for (; i< a.length() && i<b.length() && a[i] == b[i]; ++i)
			if (a[i] == '/') k=i;
		return k+1;
	};

	int index = diffpath(a, b);

	a = a.substr(index);
	b = b.substr(index);

	auto vecta = split(a, '/');
	auto vectb = split(b, '/');

	string a_path_b = ""; //a relative to b path
	string b_path_a = ""; //b relative to a path

	for (int i=1; i<vecta.size(); ++i)
		a_path_b += "../";
	a_path_b += a;

	for(int i=1; i<vectb.size(); ++i)
		b_path_a += "../";
	b_path_a += b;

	cout << "a relative to b path: " << a_path_b << endl;
	cout << "b relative to a path: " << b_path_a << endl;

	return 0;
}
