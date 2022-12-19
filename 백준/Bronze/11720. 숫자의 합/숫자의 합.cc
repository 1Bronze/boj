#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; int sum = 0;
	cin >> n;

	string str;
	cin >> str;

	for(int i=0; i<n; i++) {
		sum += str[i] - '0';
	}

	cout << sum << endl;
}