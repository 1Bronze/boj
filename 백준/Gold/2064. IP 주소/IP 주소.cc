#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> IP(1001, vector<int>(33,0));

vector<string> split(string input) {
    vector<string> answer;
    stringstream ss(input); // 1. string을 stringstream으로 만든다.
    string temp;

    while (getline(ss, temp, '.')) { // 2. getline으로 .이전까지를 읽어 저장한다.
        answer.push_back(temp);
    }

    return answer;
}

void convertBinaryIP(vector<string> ip, int n) {
    stack<int> s;
    for(int i=0; i<=3; i++) {
        int tmp = stoi(ip.at(i));

        for (int j = 0; j < 8; j++) {
            s.push(tmp % 2);
            tmp /= 2;
        }

        int pos = 8*i;
        while(!s.empty()) {
            IP[n][pos + 1] = s.top();
            s.pop();
            pos++;
        }
    }
}

string getSubnetMask() {
    int pos=0; bool flag = true;
    while(flag) {
        if(N==1) {
            flag = false;
            pos = 33;
        }
        pos++;
        for(int i=1; i<N; i++) {
            if(IP[i][pos] != IP[i+1][pos]) {
                flag = false;
                break;
            }
        }
        if(pos==33) flag = false;
    }

    string answer = "";
    for(int i=1; i<pos; i++) {
        answer += to_string(1);
    }
    for(int i=pos; i<33; i++) {
        answer += to_string(0);
    }
    return answer;
}

string getNetworkIP() {
    int pos=0; bool flag = true;
    while(flag) {
        if(N==1) {
            flag = false;
            pos = 33;
        }
        pos++;
        for(int i=1; i<N; i++) {
            if(IP[i][pos] != IP[i+1][pos]) {
                flag = false;
                break;
            }
        }
        if(pos==33) flag = false;
    }

    string answer = "";
    for(int i=1; i<pos; i++) {
        answer += to_string(IP[1][i]);
    }
    for(int i=pos; i<33; i++) {
        answer += to_string(0);
    }
    return answer;
}

string binaryToDecimal(string bin) {

    string answer = "";

    for(int i=0; i<4; i++) {
        int result = 0;
        for(int j=0; j<8; j++) {
            result += (bin[8*i+j]-'0') * pow(2, 7-j);
        }
        answer += to_string(result);
        answer += '.';
    }

    return answer.substr(0, answer.length()-1);
}

void print(int n) {
    cout << " - ";
    for(int i=1; i<33; i++) cout << IP[n][i];
    cout << "\n";
}

void solve() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        string s; cin >> s;
        convertBinaryIP(split(s), i);
//        print(i);
    }
//    cout << getNetworkIP() << "\n";
//    cout << getSubnetMask() << "\n";
    cout << binaryToDecimal(getNetworkIP()) << "\n";
    cout << binaryToDecimal(getSubnetMask()) << "\n";
}

int main() {
    solve();
    return 0;
}