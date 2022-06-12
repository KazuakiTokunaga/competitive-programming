#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int k;
vector<ll> lunlun;
bool dfs(int digit, ll n, int c){
    if (c < 0 or c > 9) return true;

    if (digit == 0) {
        lunlun.push_back(n+c);
    } else {
        dfs(digit-1, (n+c) * 10, c-1);
        dfs(digit-1, (n+c) * 10, c);
        dfs(digit-1, (n+c) * 10, c+1);
    }
    return true;
}

int main() {
    cin >> k;
    rep(i, 1, 10){
        lunlun.push_back(i);
    }
    
    int j = 1;
    while (lunlun.size() < k){
        rep(i, 1, 10){
            dfs(j, 0, i);      
        }
        j++;
    }
    
    cout << lunlun[k-1] << endl;

}