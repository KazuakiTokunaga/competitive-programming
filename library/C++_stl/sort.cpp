#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 配列 a の 1～4 番目を大きい順に並び替えます。{8, 7, 4, 3, 1, 6, 2, 5} に変化。
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    sort(a + 1, a + 5, greater<int>());
    for (auto i: a) {cout << i << ' ';} cout << endl;
    
    // 例 2: {b[0], b[1], ..., b[N-1]} を入力し、小さい順に並び替えて出力します。
    int b[3] = {20,4,8};
    sort(b, b + 3);
    for (auto i: b) {cout << i << ' ';} cout << endl;
    
    // 配列の2番目の要素が小さい順にソート
    vector<vector<int>> c = {{0,20}, {1,3}, {2,30}, {3,8}, {4,0},{5,5}};
    auto smaller = [](auto a, auto b){return a[1] < b[1];}; // lambda式
    sort(c.begin(), c.end(), smaller);
    for (auto i: c) {cout << i[0] << ' ';} cout << endl;
}