#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N, A, B;
void paint(vector<string> &X, int a, int b){
    rep(i, a, a+A){
        rep(j, b, b+B){
            X[i][j] = '#';
        }
    }
}

int main() {

    cin >> N >> A >> B;
    
    vector<string> X;
    rep(i, 0, N*A){
        string s(N*B, '.');
        X.push_back(s);
    }

    rep(i, 0, N){
        rep(j, 0, N){
            if (j % 2 == 0) if (i % 2) paint(X, A*i, B*j);
            if (j % 2) if (i % 2 == 0) paint(X, A*i, B*j);     
        }
    }

    rep(i, 0, N*A){
        cout << X[i] << endl;
    }
}