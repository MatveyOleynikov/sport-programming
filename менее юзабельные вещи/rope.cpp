#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
 
signed main() {
 
    int n = 10;
    rope<int> rp;
 
    for(int i = 1; i <= n; ++i)
        rp.push_back(i);
 
    rp.erase(0, 5); //delete 5 elements begin from 0
    rp.insert(rp.mutable_begin(), rp.substr(0, rp.size())); //insert substr of rope
    reverse(rp.mutable_begin(), rp.mutable_end()); //reverse works
    sort(rp.mutable_begin(), rp.mutable_end()); //sort works
 
    rope<int> rp2;
    for(int i = 100; i <= 105; ++i)
        rp2.push_back(i);
 
    rp += rp2; //+ operator like string
 
    rp.replace(0, 3, rp2.substr(0, 3)); //log(n) replace
 
    for(int i = 0; i < rp.size(); ++i)
        cout << rp[i] << " "; //access by index
    cout << endl;
 
 
    return 0;
}
