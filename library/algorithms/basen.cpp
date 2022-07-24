#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// https://blog.hamayanhamayan.com/entry/2021/02/20/233715
// nをbase進数で表記したときの各桁の値のベクトル
vector<ll> convert(ll n, int base){
    vector<ll> Y;

    while (n > 0){
        Y.push_back(n % base); 
        n /= base;
    }
    reverse(Y.begin(), Y.end());

    return Y;
}

// base進数での比較(return true iff a <= b)
bool compare(vector<ll> a, vector<ll> b){
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;

    rep(i, 0, a.size()){
        ll x = a[i], y = b[i];
        if (x == y) continue;
        else if (x < y)  return true;
        else return false;
    }

    // このときa == b
    return true;
}


int main() {
    vector<ll> Y = convert(180, 13);
    
    for (auto i: Y) {cout << i << ' ';} cout << endl;
    
    vector<ll> a = convert(23235, 23);
    vector<ll> b = convert(44233, 23);
    if (compare(a, b)) cout << "b is bigger!" << endl;
}