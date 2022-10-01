struct algebra{
    static const long long mas = 1e6 + 1; /// важно чекнуть mas
    static const long long mod = 998244353; /// важно чекнуть модуль
    long long n;

    algebra operator =(const algebra& other){
        this->n = other.n;
        return *this;
    }

    algebra operator =(const long long other){
        this->n = other;
        return *this;
    }

    algebra operator +(const algebra& other) const{
        algebra ans;
        ans.n = (this->n + other.n);
        if (ans.n >= mod){
            ans.n -= mod;
        }
        return ans;
    }

    algebra operator -(const algebra& other) const{
        algebra ans;
        ans.n = this->n - other.n;
        if (ans.n < 0){
            ans.n += mod;
        }
        return ans;
    }

    algebra operator *(const algebra& other) const{
        algebra ans;
        ans.n = (this->n * other.n) % mod;
        return ans;
    }

    static algebra binpow(const algebra n, long long k){
        algebra res;
        if (k == 0){
            res.n = 1;
            return res;
        }
        if (k % 2 == 1){
            res = (n * binpow(n, k - 1));

        }
        if (k % 2 == 0){
            res = binpow(n * n, k / 2);
        }
        return res;
    }

    algebra operator /(const algebra& other){
        algebra ans = *this;
        ans = (ans * binpow(other, mod-2));
        return ans;
    }

    friend ostream& operator<<(ostream& o, const algebra& cur)
    {
        return o << cur.n;
    }

    friend istream& operator>>(istream& o, algebra& cur)
    {
        o >> cur.n;
        return o;
    }

    static vector<algebra> calc_fac(){
        vector<algebra> fac;

        algebra cur = 1;
        fac.push_back(cur);

        for (long long i = 1; i <= mas; ++i){
            algebra next = i;

            cur = cur * next;
            fac.push_back(cur);
        }

        return fac;
    }

    static algebra fac(algebra n){
        static vector<algebra> fac = calc_fac();
        return fac[n.n];
    }

    static algebra C(algebra n, algebra k){
        return fac(n) / fac(k) / fac(n - k);
    }

    static algebra P(algebra n){
        return fac(n);
    }

    static algebra A(algebra n, algebra k){
        return fac(n) / fac(n - k);
    }

    algebra(long long n){
        this->n = n;
    }

    algebra(){
        this->n = 0;
    }
};
