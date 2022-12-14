#include <iostream>
#include <string>
using namespace std;

int ssize = 0;
int stack[10000];

void push(int n) {
	stack[++ssize] = n;
}

int pop() {
	if(ssize == 0) 
		return -1;
	return stack[ssize--];
}

int top() {
	if(ssize == 0) 
		return -1;
	return stack[ssize];
}

int getSize() {
	return ssize;
}

int empty() {
	return (ssize == 0) ? 1:0;
}

int main() {
	int cnt;
	string ans;
	cin >> cnt;
	for(int i=0; i<cnt; i++) {
		cin >> ans;
		if(ans == "push") {
			int n;
			cin >> n;
			push(n);
		} else if (ans == "pop") {
			cout << pop() << endl;
		} else if (ans == "top") {
			cout << top() << endl;
		} else if (ans == "size") {
			cout << getSize() << endl;
		} else {
			cout << empty() << endl;
		}
	}
}