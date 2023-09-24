#include <iostream>
#include <vector>
using namespace std;

#define PLAYER1 1
#define PLAYER2 2
#define PLAYER3 3

// N: 손모양 수, K: 우승에 필요한 승수
int N, K;
// judgement[i][j]: i가 j와 경기했을 때의 판정
vector<vector<int>> judgement(10, vector<int>(10, -1));
// selection[i][j]: i가 j번째에 낼 손모양
vector<vector<int>> selections(4, vector<int>(21, -1));
// history[i]: PLAYER1이 i라는 손모양을 냈는지 여부
vector<bool> history(10);
// participatingRounds[i]: i번째 PLAYER가 참여한 라운드의 수
vector<int> participatingRounds(4, 0);
// 편의상 0번째 원소도 추가해준다.
vector<int> playerStatus = {0, 0, 0, 0};

void input() {
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> judgement[i][j];
        }
    }
    for(int i=2; i<=3; i++) {
        for(int j=1; j<=20; j++) {
            cin >> selections[i][j];
        }
    }
}

int select(int player, int order) {
    if(player==PLAYER2 || player==PLAYER3){
        return selections[player][participatingRounds[player]];
    } else {
        return order;
    }
}

int playGame(int p1, int p2, int order) {
    participatingRounds[p1]++;
    participatingRounds[p2]++;
    int p1Selection = select(p1, order);
    int p2Selection = select(p2, order);
    if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = true;

    int winner = -1;
    if(judgement[p1Selection][p2Selection]==2) winner = p1;
    else if(judgement[p1Selection][p2Selection]==0) winner = p2;
    else {
        if(p1>p2) winner = p1;
        else winner = p2;
    }

    playerStatus[winner]++;
    return winner;
}

bool dfs(int p1, int p2, int order) {

    bool result = false;
    int winner = playGame(p1, p2, order), residue = 6 - p1 - p2;

    if(playerStatus[PLAYER1] == K) {
        participatingRounds[p1]--;
        participatingRounds[p2]--;
        playerStatus[winner]--;
        if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = false;
        return true;
    }
    else if(playerStatus[PLAYER2] == K) {
        participatingRounds[p1]--;
        participatingRounds[p2]--;
        playerStatus[winner]--;
        if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = false;
        return false;
    }
    else if(playerStatus[PLAYER3] == K) {
        participatingRounds[p1]--;
        participatingRounds[p2]--;
        playerStatus[winner]--;
        if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = false;
        return false;
    } else if(participatingRounds[1]+participatingRounds[2]+participatingRounds[3] > 16) {
        participatingRounds[p1]--;
        participatingRounds[p2]--;
        playerStatus[winner]--;
        if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = false;
        return false;
    }

    for(int i=1; i<=N; i++) {
        if((winner == PLAYER1 || residue == PLAYER1) && history[i]) continue;
        result = result || dfs(winner, residue, i);
    }

    participatingRounds[p1]--;
    participatingRounds[p2]--;
    playerStatus[winner]--;
    if(p1 == PLAYER1 || p2 == PLAYER1) history[order] = false;
    return result;
}

int main() {
    input();

    bool result = false;
    for(int i=1; i<=N; i++)
        result = result || dfs(PLAYER1, PLAYER2, i);

    cout << result;
}