#include <bits/stdc++.h>
using namespace std;

#define _42 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node {
    long long sum;
    long long pref;
    long long suff;
    long long ans;
};

Node make_node(int val, bool allow_empty = true) {
    int sum = val;
    val = (allow_empty == true) ? max(0, val) : val;
    return {
        sum,
        val,
        val,
        val
    };
}

Node combine(Node left, Node right) {
    Node res;

    res.sum = left.sum + right.sum;

    res.pref = max(
        left.pref,
        left.sum + right.pref
    );

    res.suff = max(
        right.suff,
        right.sum + left.suff
    );

    res.ans = max({
        left.ans,
        right.ans,
        left.suff + right.pref
    });

    return res;
}

class SegmentTree {
private:
    vector<Node> tree;
    vector<int> a;

    void build(int node, int left, int right) {

        if (left == right) { // leaf node
            tree[node] = make_node(a[left]);
            return;
        }

        int mid = (left + right) / 2;

        // construct the left node
        build(node * 2 + 1, left, mid);

        // construct the right node
        build(node * 2 + 2, mid + 1, right);

        // construct the current node
        Node leftNode = tree[node * 2 + 1];
        Node rightNode = tree[node * 2 + 2];
        tree[node] = combine(leftNode, rightNode);
    }

    Node query(int node, int left, int right, int qLeft, int qRight) {
        if (left == qLeft && right == qRight) {
            return tree[node];
        }

        int mid = (left + right) / 2;

        if (qRight <= mid) {
            return query(node * 2 + 1, left, mid, qLeft, qRight);
        }

        if (qLeft > mid) {
            return query(node * 2 + 2, mid + 1, right, qLeft, qRight);
        }

        Node leftNode = query(node * 2 + 1, left, mid, qLeft, mid);
        Node rightNode = query(node * 2 + 2, mid + 1, right, mid + 1, qRight);

        return combine(leftNode, rightNode);
    }

    void update(int node, int left, int right, int index, int value) {

        if (left == right) { // leaf node
            a[index] = value;
            tree[node] = make_node(value);
            return;
        }

        int mid = (left + right) / 2;
        if (index <= mid) {
            // update left
            update(node * 2 + 1, left, mid, index, value);
        } else {
            // update right
            update(node * 2 + 2, mid + 1, right, index, value);
        }

        // update current node
        Node leftNode = tree[node * 2 + 1];
        Node rightNode = tree[node * 2 + 2];
        tree[node] = combine(leftNode, rightNode);
    }

public:
    SegmentTree(vector<int> &a) {
        this->a = a;
        tree.resize(4 * a.size());
        build(0, 0, a.size() - 1);
    }

    long long query(int left, int right) {
        Node node = query(0, 0, a.size() - 1, left, right);
        return node.ans;
    }

    void update(int index, int value) {
        update(0, 0, a.size() - 1, index, value);
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree segmentTree = SegmentTree(a);

    // answer before operations
    cout << segmentTree.query(0, n - 1) << '\n';

    while (m--) {
        int i, v;
        cin >> i >> v;

        segmentTree.update(i, v);

        // answer after each update
        cout << segmentTree.query(0, n - 1) << '\n';
    }
}