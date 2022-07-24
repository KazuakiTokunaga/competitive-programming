#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

vector<pair<char, int>> runlength(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

int main() {
    string S, T;
    cin >> S >> T;
    
    auto S1 = runlength(S);
    auto T1 = runlength(T);
    if (S1.size() != T1.size()){
        cout << "No" << endl;
    } else {
        string check = "Yes";
        rep(i, 0, S1.size()){
            if (S1[i].first != T1[i].first) check = "No";
            if (S1[i].second > T1[i].second) check = "No";
            if (S1[i].second == 1) if (T1[i].second != 1) check = "No";
        }
        cout << check << endl;
    }
}