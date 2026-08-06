#include <bits/stdc++.h>
using namespace std;

#define _42 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class SegmentTree {
private:
    vector<int> tree;

    vector<int> initialArray;
    vector<int> inversions;

    int n;

    int query(int node, int left, int right, int qLeft, int qRight) {

        // No overlap
        if (right < qLeft || left > qRight)
            return 0;
        // Complete overlap
        if (qLeft <= left && right <= qRight)
            return tree[node];

        // Partial overlap
        int mid = (left + right) / 2;

        return query(node * 2 + 1, left, mid, qLeft, qRight) +
               query(node * 2 + 2, mid + 1, right, qLeft, qRight);
    }

    void update(int node, int left, int right, int index, int value) {

        if (left == right) {
            tree[node] += value;
            return;
        }

        int mid = (left + right) / 2;

        if (index <= mid)
            update(node * 2 + 1, left, mid, index, value);
        else
            update(node * 2 + 2, mid + 1, right, index, value);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

public:
    SegmentTree(vector<int> &initialArray) {
        this->initialArray = initialArray;
        n = initialArray.size();

        inversions.assign(n, 0);
        tree.assign(4 * n, 0);
    }

    int query(int left, int right) {
        if (left > right)
            return 0;

        return query(0, 0, n - 1, left, right);
    }

    void update(int index, int value) {
        update(0, 0, n - 1, index, value);
    }

    vector<int> getInversions() {

        for (int i = 0; i < n; i++) {

            int value = initialArray[i] - 1;

            // Count previous values greater than current
            inversions[i] = query(value + 1, n - 1);

            // Mark current value as seen
            update(value, 1);
        }

        return inversions;
    }
};

int main() {
    _42;

    int n;
    cin >> n;

    vector<int> initialArray(n);

    for (int i = 0; i < n; i++)
        cin >> initialArray[i];

    SegmentTree segmentTree(initialArray);

    vector<int> inversions = segmentTree.getInversions();

    for (int x : inversions)
        cout << x << ' ';

    cout << '\n';

    return 0;
}