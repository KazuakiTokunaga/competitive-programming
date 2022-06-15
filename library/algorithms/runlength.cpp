#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

int main(){
    string s = "LLLRRRLRLRLRLLLLRRR";
    auto ret = runlength(s);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i].first << " " << ret[i].second << endl;
    }
}