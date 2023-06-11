#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int arr[27] = {0, };
    for(int i = 0; i < str.length(); i++)
        arr[(int)str[i]-65]++;

    if(arr[1]&&arr[8]&&arr[12]&&arr[14]&&arr[18])
        cout << "YES";
    else
        cout << "NO";
}