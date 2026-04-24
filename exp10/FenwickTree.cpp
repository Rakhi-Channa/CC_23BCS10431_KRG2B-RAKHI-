#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int i, long long delta) {
        while (i <= n) {
            tree[i] += delta;
            i += i & (-i);
        }
    }

    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    long long rangeQuery(int l, int r) {
        if (l > 1)
            return query(r) - query(l - 1);
        return query(r);
    }

    void build(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            update(i + 1, arr[i]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "=== Fenwick Tree Example ===" << endl;
    
    int n = 5;
    FenwickTree ft(n);
    
    vector<int> arr = {1, 2, 3, 4, 5};
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    ft.build(arr);
    
    cout << "\nPrefix Sums:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "query(" << i << ") = " << ft.query(i) << endl;
    }
    
    cout << "\nRange Sums:" << endl;
    cout << "Sum(1, 3) = " << ft.rangeQuery(1, 3) << endl;
    cout << "Sum(2, 4) = " << ft.rangeQuery(2, 4) << endl;
    cout << "Sum(3, 5) = " << ft.rangeQuery(3, 5) << endl;
    
    cout << "\nAfter update: add 5 to index 2" << endl;
    ft.update(2, 5);
    
    cout << "Query(1) = " << ft.query(1) << endl;
    cout << "Query(2) = " << ft.query(2) << endl;
    cout << "Query(3) = " << ft.query(3) << endl;
    cout << "Sum(1, 3) = " << ft.rangeQuery(1, 3) << endl;
    
    return 0;
}