#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getOrder(char c) {
    if(c=='a') return 0;
    else if(c=='b') return 1;
    else if(c=='c') return 2;
    else if(c=='d') return 3;
    else if(c=='e') return 4;
    else if(c=='f') return 5;
    else if(c=='g') return 6;
    else if(c=='h') return 7;
    else if(c=='i') return 8;
    else if(c=='j') return 9;
    else if(c=='k') return 10;
    else if(c=='l') return 11;
    else if(c=='m') return 12;
    else if(c=='n') return 13;
    else if(c=='o') return 14;
    else if(c=='p') return 15;
    else if(c=='q') return 16;
    else if(c=='r') return 17;
    else if(c=='s') return 18;
    else if(c=='t') return 19;
    else if(c=='u') return 20;
    else if(c=='v') return 21;
    else if(c=='w') return 22;
    else if(c=='x') return 23;
    else if(c=='y') return 24;
    else if(c=='z') return 25;
    else return 26;
}

int main() {
    
    string s; cin >> s;
    
    int arr[26];
    
    for(int i=0; i<26; i++) arr[i] = -1; 
    
    for(int i=0; i<s.length(); i++) {
        if(arr[getOrder(s[i])]!=-1) continue;
        
        arr[getOrder(s[i])] = i;
    }
    
    for(int i=0; i<26; i++) {
        cout << arr[i] << " ";
    }
}