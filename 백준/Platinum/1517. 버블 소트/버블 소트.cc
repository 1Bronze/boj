/**
* 1517. 버블 소트
*/

#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[500000];
int tmp[500000];
long long result = 0;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void merge(int l, int r) {
    int mid = (l+r)/2;
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i<=mid && j<=r) {
        if(arr[i]>arr[j]) { // 오른쪽 배열의 원소가 더 작은 경우
            tmp[k++] = arr[j++];
            result += (mid-i+1); // 왼쪽 배열에 남은 원소의 수 만큼 교차가 발생한다.
        } else { // 왼쪽 배열의 원소가 더 작거나 같은 경우
            tmp[k++] = arr[i++];
            // 이때는 교차가 발생하지 않는다.
        }
    }

    while(i<=mid) { // 오른쪽 배열이 빈 경우
        tmp[k++] = arr[i++];
        // 왼쪽 배열에서는 당연히 교차가 발생하지 않는다.
    }
    while(j<=r) { // 왼쪽 배열이 빈 경우
        tmp[k++] = arr[j++];
        // 왼쪽 배열이 비었기 때문에 오른쪽 배열을 내려도 교차는 발생하지 않는다.
    }

    for (int t = l; t <= r; t++) arr[t] = tmp[t];

}

void mergeSort(int l, int r) {
    int mid = (l+r)/2;

    if(l<r) {
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, r);
    }
}

int main() {
    init();
    mergeSort(0, N-1);
    cout << result;

}