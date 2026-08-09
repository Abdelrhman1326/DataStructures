#include <bits/stdc++.h>
using namespace std;

#define _42 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class SegmentTree {
private:
    vector<long long> tree;
    int n;

    long long query(int node, int left, int right, int index) {
        if (left == right) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {
            return tree[node] + query(node * 2 + 1, left, mid, index);
        } else {
            return tree[node] + query(node * 2 + 2, mid + 1, right, index);
        }
    }

    void update(int node, int left, int right, int uLeft, int uRight, int value) {
        // No overlap
        if (uRight < left || uLeft > right) {
            return;
        }

        // Full overlap
        if (uLeft <= left && right <= uRight) {
            tree[node] += value;
            return;
        }

        // Partial overlap
        int mid = left + (right - left) / 2;
        update(node * 2 + 1, left, mid, uLeft, uRight, value);
        update(node * 2 + 2, mid + 1, right, uLeft, uRight, value);
    }

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(n * 4, 0LL);
    }

    long long query(int index) {
        return query(0, 0, n - 1, index);
    }

    void update(int left, int right, int value) {
        if (left > right) return;
        update(0, 0, n - 1, left, right, value);
    }
};

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;

    SegmentTree segmentTree(n);

    while (m--) {
        int operation; cin >> operation;
        if (operation == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            segmentTree.update(l, r - 1, v);
        } else if (operation == 2) {
            int index; cin >> index;
            cout << segmentTree.query(index) << '\n';
        }
    }
}

int main() {
    _42
    solve();
    return 0;
}