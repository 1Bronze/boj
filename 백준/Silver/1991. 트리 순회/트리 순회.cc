/**
 * 1991. 트리 순회
 */

#include <iostream>
using namespace std;

#define LEFT 0
#define RIGHT 1

int tree[50][2];

void preorder (int parent) {
    if (parent == -1) return;
    cout << (char)(parent + 'A');
    preorder(tree[parent][LEFT]);
    preorder(tree[parent][RIGHT]);
}

void inorder (int parent) {
    if (parent == -1) return;
    inorder(tree[parent][LEFT]);
    cout << (char)(parent + 'A');
    inorder(tree[parent][RIGHT]);
}

void postorder (int parent) {
    if (parent == -1) return;
    postorder(tree[parent][LEFT]);
    postorder(tree[parent][RIGHT]);
    cout << (char)(parent + 'A');
}

int main() {

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;

        parent -= 'A'; // 'A'를 0으로 설정

        if (leftChild == '.') tree[parent][LEFT] = -1;
        else tree[parent][LEFT] = leftChild-'A';

        if (rightChild == '.') tree[parent][RIGHT] = -1;
        else tree[parent][RIGHT] = rightChild-'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;
}