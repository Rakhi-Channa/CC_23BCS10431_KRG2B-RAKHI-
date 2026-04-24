#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<long long> tree, lazy;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void update(int l, int r, int val) {
        updateUtil(0, 0, n - 1, l, r, val);
    }

    void updateUtil(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);

        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateUtil(2 * node + 1, start, mid, l, r, val);
        updateUtil(2 * node + 2, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    long long queryUtil(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (r < start || end < l) return 0;

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long left = queryUtil(2 * node + 1, start, mid, l, r);
        long long right = queryUtil(2 * node + 2, mid + 1, end, l, r);

        return left + right;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << st.query(1, 3) << endl;  // 3+5+7 = 15

    st.update(1, 3, 5);              // add +5 to range [1,3]

    cout << st.query(1, 3) << endl;  // (3+5)+(5+5)+(7+5) = 30

    return 0;
}