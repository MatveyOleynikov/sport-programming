#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define int long long
using vi = vector<int>;
#define INT(X) static_cast<int>(X)

struct big_integer{
    const int glob_sz = 5;
    const int osn = 1e9;
 
	int sz;
	vi vals;
 
	big_integer(){sz=0; vals.resize(glob_sz);}
 
	big_integer(int n){
	    if (n > 1e9) exit(1);
	    sz=1; vals.resize(glob_sz);
	    vals[0] = n;
    }
 
	friend ostream& operator<<(ostream& o, const big_integer& cur){
		if(!cur.sz){
            o << 0;
            return o;
        }
        o << cur.vals[cur.sz - 1];
        for (int i = cur.sz - 2; i >= 0; --i){
            int kol = 0;
            int cpy = cur.vals[i];
            while (cpy){
                cpy /= 10;
                kol++;
            }
 
            for (int dig = kol; dig < 9; ++dig){
                o << 0;
            }
            o << cur.vals[i];
        }
        return o;
	}
 
    big_integer operator +(const big_integer& other) const{
        int mx = max(this->sz, other.sz);
 
        big_integer res;
        for(int i = 0; i < mx; i++){
            res.vals[i] += this->vals[i] + other.vals[i];
            while (res.vals[i] >= osn){
                res.vals[i + 1] += 1;
                res.vals[i] -= osn;
            }
        }
 
        res.sz = mx;
        if (res.vals[mx]){
            res.sz = mx + 1;
        }
 
        return res;
    }
 
    big_integer operator *(const int& b){
        big_integer cpy;
        cpy.sz = this->sz;
        cpy.vals = this->vals;
        int carry = 0;
        for (size_t i = 0; i < cpy.vals.size() || carry; ++i) {
            long long cur = carry + cpy.vals[i] * 1ll * b;
            cpy.vals[i] = INT (cur % osn);
            carry = INT (cur / osn);
        }
 
        if (cpy.vals[cpy.sz]){
            cpy.sz++;
        }
        return cpy;
    }
 
    big_integer operator *(const big_integer& b){
        big_integer c;
        for (size_t i=0; i<= this->sz; ++i)
            for (int j=0, carry=0; j<=(int)b.sz || carry; ++j) {
                long long cur = c.vals[i+j] + this->vals[i] * 1ll * (j < (int)b.sz ? b.vals[j] : 0) + carry;
                c.vals[i+j] =  (cur % osn);
                carry =  (cur / osn);
            }
        c.sz = glob_sz - 1;
        while (c.sz > 1 && c.vals[c.sz -1] == 0)
            c.sz--;
        return c;
    }
 
    big_integer operator /(const int& b){
        big_integer cpy;
        cpy.sz = this->sz;
        cpy.vals = this->vals;
        int carry = 0;
        for (int i=(int)cpy.vals.size()-1; i>=0; --i) {
            long long cur = cpy.vals[i] + carry * 1ll * osn;
            cpy.vals[i] = INT (cur / b);
            carry = INT (cur % b);
        }
 
        cpy.sz--;
 
        if (cpy.vals[cpy.sz]){
            cpy.sz++;
        }
        return cpy;
    }
 
    big_integer* operator =(const big_integer other){
        this->sz = other.sz;
        this->vals = other.vals;
        return this;
    }
 
    big_integer* operator =(const int other){
        if (other > 1e9){
            exit(1);
        }
        this->sz = 1;
        this->vals[0] = other;
        return this;
    }
    
    static big_integer make_big_integer(string s){
        big_integer result(0);
        for (int i = 0; i < s.size(); ++i){
            result = result * 10;
            result = result + (s[i] - '0');
        }
        return result;
    }
};

signed main() {
    big_integer bg = big_integer::make_big_integer("1234567432145678643467435425675435");
    cout << bg;
    return 0;
}
/*
*/
