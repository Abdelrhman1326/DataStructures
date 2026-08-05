#include <bits/stdc++.h>
using namespace std;

#define _42 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class SegmentTree {
private:
    vector<long long> tree;
    vector<long long> arr;
    int n;

    // Build the tree
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }


    // Query sum in [ql, qr]
    long long query(int node, int l, int r, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr)
            return 0;

        // Complete overlap
        if (ql <= l && r <= qr)
            return tree[node];

        // Partial overlap
        int mid = (l + r) / 2;

        return query(node * 2 + 1, l, mid, ql, qr)
             + query(node * 2 + 2, mid + 1, r, ql, qr);
    }


    // Update arr[idx] = value
    void update(int node, int l, int r, int idx, long long value) {
        // Leaf node
        if (l == r) {
            tree[node] = value;
            arr[idx] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2 + 1, l, mid, idx, value);
        else
            update(node * 2 + 2, mid + 1, r, idx, value);

        // Recalculate current node
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }


public:
    SegmentTree(vector<long long>& a) {
        arr = a;
        n = a.size();

        tree.assign(4 * n, 0);

        build(0, 0, n - 1);
    }

    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, long long value) {
        update(0, 0, n - 1, idx, value);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> array(n);

    for (int i = 0; i < n; i++)
        cin >> array[i];

    SegmentTree segmentTree(array);

    while (q--) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int index;
            long long value;
            cin >> index >> value;

            segmentTree.update(index, value);
        }
        else {
            int left, right;
            cin >> left >> right;

            cout << segmentTree.query(left, right - 1) << '\n';
        }
    }
}

int main() {
    _42
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}