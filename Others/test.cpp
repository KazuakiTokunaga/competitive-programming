#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    map<vector<int>, int> M;
    vector<int> a = {1,2,3};
    vector<int> b = {2,3,4};
    vector<int> c = {1,2,3};
    M[a]++;
    M[b]++;
    M[c]++;
    cout << M[a] << endl;
    cout << M[b] << endl;
    
}