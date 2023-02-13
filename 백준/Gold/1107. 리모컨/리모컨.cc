#include <iostream>
#include <string>
using namespace std;

int N, M, result;
bool broken[10] = {false, };
int channel[1000001];

int main() {
    cin >> N;

    int cnt; cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        int btn; cin >> btn;
        broken[btn] = true;
    }

    string goal = to_string(N);
    int min = 1000000;

    for (int i = 0; i <= 1000000; i++) {
        if(i==99 || i==101) channel[i]=1;
        else if(i==102) channel[i]=2;
        else if(i==100) channel[i]=0;
        else {
            bool flag = false;

            string tmp = to_string(i);
            for (int j = 0; j < tmp.length(); j++) {
                for (int k = 0; k < 10; k++) {
                    if (broken[k] && (k == tmp[j] - '0')) flag = true;
                }
            }

            if (flag) channel[i] = 1000000;
            else channel[i] = tmp.length();
        }

        min = (min>(channel[i]+abs(N-i))) ? (channel[i]+abs(N-i)):min;
//        cout << "channel[" << i << "] " << channel[i] << "\n";
    }

    result = (min>abs(N-100)) ? abs(N-100):min;
    cout << result;
}