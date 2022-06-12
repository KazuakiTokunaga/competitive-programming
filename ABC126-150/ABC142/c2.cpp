#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i+1;
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        cout << p[i].second << ' ';
    }
    cout << endl;
    return 0;
}