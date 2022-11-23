// 二分探索
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int n, k;
vector<int> W, V;
vector<double> y;

bool check(double x){
    rep(i, 0, n){
        y[i] = V[i] - x * W[i];
    }
    sort(all(y));

    double sum = 0;
    rep(i, 0, k){
        sum += y[n-i-1];
    }
    return sum >= 0;
}

int main() {
    cin >> n >> k;

    rep(i, 0, n){
        int w, v;
        cin >> w >> v;
        W.push_back(w);
        V.push_back(v);
    }

    y.assign(n, 0);
    double left = 0, right = INF;
    rep(i, 0, 100){
        double mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    
    cout << left << endl;
}

/*
3 2
2 2
5 3
2 1
*/