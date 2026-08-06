#include <bits/stdc++.h>
using namespace std;

#define _42 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class SegmentTree {
private:
    vector<int> tree;
    int n;

    int query(int node, int left, int right, int qLeft, int qRight) {

        // Completely outside
        if (right < qLeft || left > qRight)
            return 0;

        // Completely inside
        if (qLeft <= left && right <= qRight)
            return tree[node];

        // Leaf node
        if (left == right)
            return tree[node];

        int mid = (left + right) / 2;

        return query(node * 2 + 1, left, mid, qLeft, qRight)
             + query(node * 2 + 2, mid + 1, right, qLeft, qRight);
    }

    void update(int node, int left, int right, int index, int value) {

        // leaf node
        if (left == right) {
            tree[node] = value;
            return;
        }

        int mid = (left + right) / 2;

        if (index > mid) {
            update(node * 2 + 2, mid + 1, right, index, value);
        } else {
            update(node * 2 + 1, left, mid, index, value);
        }

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

public:
    SegmentTree(int n) {
        this-> n = n;
        this->tree.assign(4 * n, 0);
    }

    void update(int index, int value) {
        return update(0, 0, n - 1, index, value);
    }

    int query(int left, int right) {
        if (left > right)
            return 0;

        return query(0, 0, n - 1, left, right);
    }
};

int main() {
    _42;

    int n; cin >> n;
    vector<int> array(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> array[i];
    }

    SegmentTree segmentTree = SegmentTree(2 * n);
    vector<int> firstIndex(n + 1, -1);
    vector<int> answer(n + 1);

    for (int i = 0; i < 2 * n; i++) {

        int currNum = array[i];
        if (firstIndex[currNum] == -1) {

            firstIndex[currNum] = i;
        } else {
            int left = firstIndex[currNum];
            int right = i;

            answer[currNum] = segmentTree.query(left + 1, right - 1);
            segmentTree.update(left, 1);
        }
    }

    for (int i = 1; i < n + 1; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}