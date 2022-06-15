#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10,9) + 7;

// https://qiita.com/e869120/items/518297c6816adb67f9a5#3-8-%E6%99%82%E9%96%93%E8%A8%88%E6%B8%AC-clock
int main() {
    
    // 例 1: 実行にかかる時間を計測する
    // 単純な処理であれば10^7 (=1000万)2秒に間に合う。10^8を超えると間に合わない。
    int ti = clock();
    ll a = 0;
    for (ll i = 1; i <= pow(10,7); i++) {a *= i; a %= MOD;}
    printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    
    return 0;
}