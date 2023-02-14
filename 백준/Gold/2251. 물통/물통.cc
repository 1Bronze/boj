/**
* 2251. 물통
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
using namespace std;

int A, B, C;
queue<vector<int>> q;
bool result[201];
set<string> visited;

void bfs() {
    int curA = 0, curB = 0, curC = C;
    q.push({curA, curB, curC});
    string status = to_string(curA) + " " + to_string(curB) + " " + to_string(curC);
    visited.insert(status);
    result[C] = true;

    while(!q.empty()) {
        curA = q.front().at(0), curB = q.front().at(1), curC = q.front().at(2);
        q.pop();

        int nextA, nextB, nextC, gap;

        if (curA != 0) {
            // A->B로 옮기기
            gap = B - curB;
            if (curA >= gap) nextA = curA - gap, nextB = curB + gap, nextC = curC;
            else nextA = 0, nextB = curB + curA, nextC = curC;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if (visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }

            // A->C로 옮기기
            gap = C - curC;
            if (curA >= gap) nextA = curA - gap, nextB = curB, nextC = curC + gap;
            else nextA = 0, nextB = curB, nextC = curC + curA;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if (visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }
        }

        if (curB!=0) {
            // B->A로 옮기기
            gap = A - curA;
            if(curB>=gap) nextA = curA + gap, nextB = curB - gap, nextC = curC;
            else nextA = curA + curB, nextB = 0, nextC = curC;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if(visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }

            // B->C로 옮기기
            gap = C - curC;
            if(curB>=gap) nextA = curA, nextB = curB - gap, nextC = curC + gap;
            else nextA = curA, nextB = 0, nextC = curC + curB;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if(visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }
        }

        if (curC!=0) {
            // C->A로 옮기기
            gap = A - curA;
            if(curC>=gap) nextA = curA + gap, nextB = curB, nextC = curC - gap;
            else nextA = curA + curC, nextB = curB, nextC = 0;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if(visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }

            // C->B로 옮기기
            gap = B - curB;
            if(curC>=gap) nextA = curA, nextB = curB + gap, nextC = curC - gap;
            else nextA = curA, nextB = curB + curC, nextC = 0;

            status = to_string(nextA) + " " + to_string(nextB) + " " + to_string(nextC);
            if(visited.find(status) == visited.end()) {
                visited.insert(status);
                if(nextA==0) result[nextC] = true;
                q.push({nextA, nextB, nextC});
            }
        }
    }
}

int main() {
    cin >> A >> B >> C;
    bfs();

    for (int i = 0; i <= C; i++) {
        if(result[i]) cout << i << " ";
    }
}