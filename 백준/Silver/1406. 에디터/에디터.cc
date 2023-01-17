#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<char> leftDeque; deque<char> rightDeque;

void cursorLeft() {
    if(!leftDeque.empty()) {
        rightDeque.push_back(leftDeque.back());
        leftDeque.pop_back();
    }
}

void cursorRight() {
    if(!rightDeque.empty()) {
        leftDeque.push_back(rightDeque.back());
        rightDeque.pop_back();
    }
}

void backspace() {
    if(!leftDeque.empty()) leftDeque.pop_back();
}

void write() {
    char tmp; cin >> tmp;
    leftDeque.push_back(tmp);
}

int main() {
    string str;
    int cnt; char key;
    cin >> str;
    
    for(char& c : str) {
        leftDeque.push_back(c);
    }
    
    cin >> cnt;
    for(int i=0; i<cnt; i++) {
        cin >> key;
        
        if(key == 'L') cursorLeft();
        else if(key == 'D') cursorRight();
        else if(key == 'B') backspace();
        else if(key == 'P') write();
    }
    
    while(!leftDeque.empty()) {
        cout << leftDeque.front();
        leftDeque.pop_front();
    }
    while(!rightDeque.empty()) {
        cout << rightDeque.back();
        rightDeque.pop_back();
    }
}