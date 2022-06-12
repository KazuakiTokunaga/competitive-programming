#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int k;
    cin >> k;

    int cur = 7 % k;
    int count = 1;
    vector<int> r(k);
    while (true){
        if (cur == 0) break;
        if (r[cur]) {count = 0; break;};
        r[cur]++;
        count++;
        cur = (10 * cur + 7) % k;
    }

    if (count > 0){
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }
}