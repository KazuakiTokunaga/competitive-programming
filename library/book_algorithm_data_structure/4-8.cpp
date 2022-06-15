// メモ化再帰

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fibo(int N, vector<ll> &memo){
    if (N==0) return 0;
    else if (N == 1) return 1;

    if (memo[N] != -1) return memo[N];

    return memo[N] = fibo(N-1, memo) + fibo(N-2, memo);
}

int main() {
    vector<ll> memo;
    memo.assign(100, -1);

    fibo(99, memo);

    for (int i = 2; i < 50; i++) {
        cout << fibo(i, memo) << endl;
    }
}