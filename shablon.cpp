#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <bitset>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <numeric>
#include <math.h>
#include <cassert>
#include <climits>
#include <chrono>
#include <random>
#pragma warning(disable:4996)

using namespace std;

#ifdef MATVEY
#define _dbg(x) do { cout << #x << "=" << x << "; "; } while (0)
#define _name(name, _1, _2, _3, _4, N, ...) name ## N
#define _dbg1(x) _dbg(x)
#define _dbg2(x, ...) _dbg(x); _dbg1(__VA_ARGS__)
#define _dbg3(x, ...) _dbg(x); _dbg2(__VA_ARGS__)
#define _dbg4(x, ...) _dbg(x); _dbg3(__VA_ARGS__)
#define dbg(...) do { cout << __LINE__ << ": "; _name(_dbg, __VA_ARGS__, 4, 3, 2, 1, 0)(__VA_ARGS__); cout << endl;} while (0)
#else
#define dbg(...)
#endif

#define X first
#define Y second
#define int long long
#define INT static_cast<long long>
#define be		begin()
#define en		end()

#define all(a)     a.begin(), a.end()
#define sum(a)     ( accumulate (all(a), 0ll))
#define mine(a)    (*min_element(all(a)))
#define maxe(a)    (*max_element(all(a)))
#define mini(a)    ( min_element(all(a)) - (a).begin())
#define maxi(a)    ( max_element(all(a)) - (a).begin())
#define rep(x, from, to)  for(int x = from; x < (to); ++x)
#define yes        cout << "YES\n"; return
#define no         cout << "NO\n"; return

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;

const ld eps = 1e-9;
const ld pi = acos(-1.0);
const ll inf = INT(1000 * 1000 * 1000 + 1) * INT(1000 * 1000 * 1000 + 1);
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
const ll alphabet = 26;

//вывод пары
template<typename X, typename Y>
ostream& operator<<(ostream& o, const pair<X, Y>& p)
{
    return o << "<" << p.first << ", " << p.second << ">" << "\n";
}

//ввод вектора
template<typename T>
istream& operator>>(istream& o, vector<T> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        o >> a[i];
    }
    return o;
}

//вывод вектора
template<typename T>
ostream& operator<<(ostream& o, const vector<T> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        o << a[i] << " ";
    }
    o << '\n';
    return o;
}

//вывод вектора векторов
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T>> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        for (size_t j = 0; j < a[i].size(); ++j){
            o << a[i][j] << " ";
        }
        o << "\n";
    }
    o << '\n';
    return o;
}

//вывод вектора векторов векторов
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<vector<T>>> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        for (size_t j = 0; j < a[i].size(); ++j){
            for (size_t k = 0; k < a[i][j].size(); ++k){
                o << a[i][j][k] << " ";
            }
            o << "\n";
        }
        o << "\n";
    }
    o << '\n';
    return o;
}

//вывод map
template<typename X, typename Y>
ostream& operator<<(ostream& o, const map<X, Y> & mp)
{
    for (auto i : mp){
        o << i;
    }
    o << '\n';
    return o;
}

//вывод set
template<typename T>
ostream& operator<<(ostream& o, const set<T> & st)
{
    for (auto elem: st){
        o << elem << " ";
    }
    o << '\n';
    return o;
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){

    return;
}

signed main(){
    #ifdef MATVEY
    freopen ("file.txt","r",stdin);
    #endif
    fast();
    ll k = 1;
    cin >> k;

    for (ll i = 1; i <= k; ++i){
        solve();
    }
    return 0;
}
/*
*/
