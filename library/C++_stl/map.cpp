#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // https://qiita.com/_EnumHack/items/f462042ec99a31881a81
    // http://vivi.dyndns.org/tech/cpp/map.html
    
    map<string, int> mp;

    mp["hoge"] = 1;
    mp["fuga"] = 2;

    // 要素数
    cout << "mpの要素数: " << mp.size() << endl;

    // 走査
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second != 2){
            cout << "値が2であるkey: " << itr->first << endl;
        }
    }
    
    // こちらでも走査できる
    for (auto& [key, value]: mp) {
        cout << key << " => " << value << endl;
    }

    // countはkeyが存在すれば1、しなければ0を返す
    if (!mp.count("gaga")) {
        cout << "gagaは存在しません" << endl;
    }

    // findはイテレータを返す（keyが存在しなければ終端）
    if (auto iter = mp.find("hoge"); iter != mp.end()){
        cout << "gagaは存在しません" << endl;
    }

    // 最初の要素、最後の要素
    map<int, int> cnt;
    cnt[3] = 4;
    cnt[2] = 5;
    cnt[6] = 2;
    cnt[1] = 3;
    cout << "minimum key: " << cnt.begin()->first << endl;
    cout << "maximum key: " << (--cnt.end())->first << endl;
    cnt.erase(1);
    cout << "minimum element: " << cnt.begin()->first << "->" << cnt.begin()->second << endl;
}