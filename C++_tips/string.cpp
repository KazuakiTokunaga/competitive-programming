#include <bits/stdc++.h>
using namespace std;

int main() {

    // 数値と文字列の変換
    // https://qiita.com/seal_qiita/items/d62192f8d0b1e4ca8de2
    // 整数を文字列に変換して桁数を取得
    int n = 23423523;
    cout << "digit: " << to_string(n).size() << endl;

    // 文字列を整数に変換
    string s0 = "12312";
    cout << stoi(s0) << endl;

    // 文字列を1字ずつ走査して積をとる
    string s = "345";
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        res *= int(s[i]-'0'); //文字コードを引き算する
    }
    cout << res << endl;

    // -----------------------------------------------------------------------------
    // charをstringに変換
    string t = "hogehoge";
    string a = string() + t[1]; // 空文字を使ってstringに変換
    string b = {t[1]}; // 初期化によってcharをstringに変換

    // -----------------------------------------------------------------------------
    // substring
    string s1 = "fugafuga";
    cout << s1.substr(5) << endl;
    cout << s1.substr(2,3) << endl;

    // -----------------------------------------------------------------------------
    // transform
    // https://qiita.com/color_box/items/a7a0bf25bc9858e7b2ad
    string s11 = "abcde";
    transform(s11.begin() + 1, s11.begin() + 3, s11.begin() + 1, ::toupper); // 3番目の引数は書き込み先
    cout << s11 << endl;
}