#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = 0, cur = 1, next = 0;
    vector<int> city(n+1, 0);
    vector<int> cnt(n+1, 0);
    city[1] = 0;
    cnt[0] = 1;
    while (true){
        next = a[cur-1];
        count++;
        if (city[next] != 0){
            break;
        }
        city[next] = count;
        cnt[count] = next;
        cur = next;
    }

    // for (auto i: city) {cout << i << ' ';} cout << endl;
    // for (auto i: cnt) {cout << i << ' ';} cout << endl;
    
    int cycle = count - city[next];
    // cout << cycle << endl;
    if (k >= count){
        k -= city[next];
        k = k % cycle;
        k += city[next];
    }
    
    cout << cnt[k] << endl;
}