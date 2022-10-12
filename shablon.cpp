#include <bits/stdc++.h>

using namespace std;

#ifdef MATVEY
#define dbg(x) do { cout << #x << "=" << x << endl;} while(0)
#else
#define dbg(x)
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
#define rep(x,to)  for(x = 0; x < (to); ++x)

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<long long>;

const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000 + 1;
const ll inf64 = ll(inf) * inf;
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

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin >> n;
    cout << n;
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
