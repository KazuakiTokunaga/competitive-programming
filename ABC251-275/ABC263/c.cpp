#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N, M;
vector<int> memo;
void dfs(int cur, int cnt) {
    if (cur == M and cnt != N) {return;}
    if (cur == M and cnt == N) {for (auto i: memo) {cout << i << ' ';} cout << endl; return;}
    if (cur <= M and cnt == N) {for (auto i: memo) {cout << i << ' ';} cout << endl; return;}

    rep(i, cur+1, M+1){
        memo.push_back(i);
        dfs(i, cnt+1);
        memo.pop_back();
    }
}

int main() {
    cin >> N >> M;
    
    rep(i, 1, M+1){
        memo.push_back(i);
        dfs(i, 1);
        memo.pop_back();
    }
}