// 反転。左端から反転するかどうかを決めていく
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N;
vector<int> dir, f;

int calc(int K){
    f.assign(N, 0);
    int res = 0, sum = 0;
    rep(i, 0, N-K+1){
        if ((dir[i] + sum) % 2 != 0){
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if (i - K + 1 >= 0) sum -= f[i-K+1];
    }

    rep(i, N-K+1, N){
        if ((dir[i] + sum) % 2 != 0) return -1;
        if (i - K + 1 >= 0) sum -= f[i-K+1];
    }

    return res;
}



int main() {
    cin >> N;

    string s;
    cin >> s;

    rep(i, 0, N){
        if (s[i] == 'B') dir.push_back(1);
        else dir.push_back(0);
    }

    int K = 1, M = N;
    rep(k, 1, N+1){
        int m = calc(k);
        if (m >= 0 and M > m){
            M = m;
            K = k;
        }
    }
    cout << K << " " << M << endl;
}

/*
7
BBFBFBB
*/