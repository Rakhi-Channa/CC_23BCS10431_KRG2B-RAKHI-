#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;

    // Store database strings
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    while(m--) {
        string query;
        cin >> query;

        bool found = false;

        for(int i = 0; i < query.size() && !found; i++) {
            char original = query[i];

            // try changing to other possible chars
            for(char ch = 'a'; ch <= 'c'; ch++) {
                if(ch == original) continue;

                query[i] = ch;

                if(st.count(query)) {
                    found = true;
                    break;
                }
            }

            query[i] = original; // restore
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}