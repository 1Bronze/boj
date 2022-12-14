#define MAX_SIZE 10000

#include <iostream>
#include <string>
using namespace std;

int s = 0;
int front, back;
int queue[MAX_SIZE];

void push(int n) {
    if(s == 0) {
        front = 0; 
        back = -1;
    }
    back = (++back) % MAX_SIZE;
    queue[back] = n;
    s++;
}

int pop() {
	if(s == 0)
	    return -1;
	int returnIdx = front;
	front = (++front) % MAX_SIZE;
	s--;
	return queue[returnIdx];
}

int getSize() {
	return s;
}

int isEmpty() {
	return (s == 0) ? 1:0;
}

int getFront() {
    if(s == 0)
	    return -1;
    return queue[front];
}

int getBack() {
    if(s == 0)
	    return -1;
    return queue[back];
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
		} else if (ans == "size") {
			cout << getSize() << endl;
		} else if (ans == "empty") {
			cout << isEmpty() << endl;
		} else if (ans == "front") {
		    cout << getFront() << endl;
		} else {
		    cout << getBack() << endl;
		}
	}
}