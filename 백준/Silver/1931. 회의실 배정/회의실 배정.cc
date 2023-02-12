#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meet {
    int start;
    int end;
};

int N;
Meet arr[100000];
int s, e, result;

bool compare(Meet a, Meet b) {
    if(a.end == b.end) return a.start < b.start;
    else return a.end < b.end;
}

int main() {
    cin >> N;

    int start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;

        arr[i].start = start;
        arr[i].end = end;
    }

    sort(arr, arr+N, compare);

    s = arr[0].start; e = arr[0].end;
    result = 1;
    for (int i = 1; i < N; i++) {
        if(e<=arr[i].start) {
            result += 1;
            e = arr[i].end;
        }
    }

    cout << result;
}