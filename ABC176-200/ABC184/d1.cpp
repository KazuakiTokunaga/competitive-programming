#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ld get_prob(int t, int a, int b, int c){
    return (ld)t / (a+b+c);
}

vector<vector<vector<ld>>> memo(101, vector<vector<ld>>(101, vector<ld>(101, 0)));
ld calculate(int a, int b, int c){
    if (a == 100 or b == 100 or c == 100) return 0;
    if (memo[a][b][c] > 0) return memo[a][b][c];
    memo[a][b][c] = get_prob(a, a, b, c) * (1 + calculate(a+1, b, c))
        + get_prob(b, a, b, c) * (1 + calculate(a, b+1, c))
        + get_prob(c, a, b, c) * (1 + calculate(a, b, c+1));
    
    return memo[a][b][c];
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    memo[99][99][99] = 1;
    cout << fixed << setprecision(15);
    cout << calculate(A, B, C) << endl;

}