#define MAX_SIZE 10000

#include <iostream>
#include <string>
using namespace std;

int queue[MAX_SIZE];

int s = 0;
int front = 0;
int back = 0;

void nextFront() {
    front++;
    if(front >= MAX_SIZE) {
        front -= MAX_SIZE;
    }
}

void nextBack() {
    back++;
    if(back >= MAX_SIZE) {
        back -= MAX_SIZE;
    }
}

void prevFront() {
    front--;
    if(front == -1) {
        front = MAX_SIZE - 1;
    }
}

void prevBack() {
    back--;
    if(back == -1) {
        back = MAX_SIZE - 1;
    }
}

void push_front(int n) {
    prevFront();
    queue[front] = n;
    if(s == 0) // 빈 곳에 삽입할 경우, back도 front와 같은 곳을 가리키도록 설정
        prevBack();
    s++;
}

void push_back(int n) {
    nextBack();
    queue[back] = n;
    if(s == 0) // 빈 곳에 삽입할 경우, front도 back과 같은 곳을 가리키도록 설정
        nextFront();
    s++;
}

int pop_front() {
    if(s == 0)
        return -1;
    int returnVal = front;
    if(s != 1) // size가 1일 경우, front와 back이 같은 위치를 가리키고 있으므로 front를 이동시키면 문제 발생!
        nextFront();
    s--;
    return queue[returnVal];
}

int pop_back() {
    if(s == 0)
        return -1;
    int returnVal = back;
    if(s != 1) // size가 1일 경우, front와 back이 같은 위치를 가리키고 있으므로 back을 이동시키면 문제 발생!
        prevBack();
    s--;
    return queue[returnVal];
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
		if(ans == "push_front") {
			int n;
			cin >> n;
			push_front(n);
		} else if(ans == "push_back") {
			int n;
			cin >> n;
			push_back(n);
		} else if (ans == "pop_front") {
			cout << pop_front() << endl;
		} else if (ans == "pop_back") {
			cout << pop_back() << endl;
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