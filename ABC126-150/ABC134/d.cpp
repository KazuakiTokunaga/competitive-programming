#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> res(n+1);
    int count = 0;
    rrep(i, n, 1){ 
        if (a[i-1] % 2 == 1){
            res[i] = 1;
            count++;
        } else {
            res[i] = 0;
        }

        vector<ll> divisors = enum_divisors(i);
        for (int j: divisors) {
            a[j-1] += res[i];
        }
    }

    
    cout << count << endl;
    rep(i, 1, n+1){
        if (res[i] == 1) cout << i << " ";
    }
    cout << endl;
    
}