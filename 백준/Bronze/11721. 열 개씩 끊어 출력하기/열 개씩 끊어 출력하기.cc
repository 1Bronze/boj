#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int curPos = 0;
	int len = str.length();

	while(curPos<len) {
		cout << str.substr(curPos, 10) << endl;
		curPos = curPos + 10;
	}
}