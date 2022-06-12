#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int t, max = -1, second_max = -2;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i] = t;
        vector<int> list = {max, second_max, t};
        sort(list.begin(), list.end());
        max = list[2];
        second_max = list[1];
    };

    for (int i: a) {
        if (i==max){
            cout << second_max << endl;
        } else {
            cout << max << endl;
        }
    }
}