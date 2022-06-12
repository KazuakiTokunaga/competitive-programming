#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a{2,5,2,4,3,8,3,1};

    auto m = *max_element(a.begin(), a.end()); //イテレータの要素にアクセス
    cout << m << endl; // 最大値

    auto it = max_element(a.begin(), a.end());
    cout << *it << " : " << distance(a.begin(), it) << endl; // 最大値とそのインデックス

}