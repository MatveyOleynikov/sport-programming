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
#define dbg(x) do { cout << __LINE__ << ": " << #x << "=" << x << "; " << endl; } while (0)
#else
#define dbg(...)
#endif

#define int long long
#define INT static_cast<int>

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define nl "\n"
#define all(a)     a.begin(), a.end()
#define sum(a)     ( accumulate (all(a), 0ll))
#define mine(a)    (*min_element(all(a)))
#define maxe(a)    (*max_element(all(a)))
#define mini(a)    ( min_element(all(a)) - (a).begin())
#define maxi(a)    ( max_element(all(a)) - (a).begin())
#define yes        cout << "YES\n"; return
#define no         cout << "NO\n"; return

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int inf = INT(1000 * 1000 * 1000 + 1) * INT(1000 * 1000 * 1000 + 1);
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

//вывод пары
template<typename X, typename Y>
ostream& operator<<(ostream& o, const pair<X, Y>& p)
{
    return o << "<" << p.first << ", " << p.second << ">" << "\n";
}

//ввод вектора
template<typename T>
istream& operator>>(istream& o, vector<T>& a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        o >> a[i];
    }
    return o;
}

//вывод вектора
template<typename T>
ostream& operator<<(ostream& o, const vector<T>& a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        o << a[i] << " ";
    }
    o << '\n';
    return o;
}

//вывод вектора векторов
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T>>& a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            o << a[i][j] << " ";
        }
        o << "\n";
    }
    o << '\n';
    return o;
}

//вывод map
template<typename X, typename Y>
ostream& operator<<(ostream& o, const map<X, Y>& mp)
{
    for (auto i : mp) {
        o << i;
    }
    o << '\n';
    return o;
}

//вывод set
template<typename T>
ostream& operator<<(ostream& o, const set<T>& st)
{
    for (auto elem : st) {
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

struct SOLVE {
    void input_data();
    void output_data();
    void brute();
    void generate_data();
    void solve();
};

void SOLVE::solve() {
    dbg("0p0");

    return;
}

signed main() {
#ifdef MATVEY
    freopen("input.txt", "r", stdin);
#endif
    fast();
    int k = 1;
    cin >> k;

    for (int i = 1; i <= k; ++i) {
        SOLVE slv;
        slv.solve();
    }

    return 0;
}
/*
*/
