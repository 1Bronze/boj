#include <iostream>
#include <string>
using namespace std;

string s;
int num[26];

int main() {
    cin >> s;
    
   for(int i=0; i<s.length(); i++) {
       num[int(s[i])-97]++;
   } 
   
   for(int i=0; i<26; i++) cout << num[i] << " ";
   
   return 0;
}