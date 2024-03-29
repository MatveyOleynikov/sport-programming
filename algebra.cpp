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

    algebra operator +=(const algebra& other){
        this->n += other.n;
        if (this->n >= mod){
            this->n -= mod;
        }
        return *this;
    }

    algebra operator -(const algebra& other) const{
        algebra ans;
        ans.n = this->n - other.n;
        if (ans.n < 0){
            ans.n += mod;
        }
        return ans;
    }

    algebra operator -=(const algebra& other){
        this->n -= other.n;
        if (this->n < 0){
            this->n += mod;
        }
        return *this;
    }

    algebra operator *(const algebra& other) const{
        algebra ans;
        ans.n = (this->n * other.n) % mod;
        return ans;
    }

    algebra operator *=(const algebra& other){
        this->n = (this->n * other.n) % mod;
        return *this;
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

    algebra operator /=(const algebra& other){
        *this = (*this * binpow(other, mod-2));
        return *this;
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

    static vector<algebra> calc_ifac(){
        vector<algebra> fac;

        algebra cur = 1;
        fac.push_back(cur);

        for (long long i = 1; i <= mas; ++i){
            algebra next = i;

            cur = cur * next;
            algebra one(1);
            fac.push_back(one / cur);
        }

        return fac;
    }

    static algebra ifac(algebra n){
        static vector<algebra> ifac = calc_ifac();
        return ifac[n.n];
    }

    static algebra C(algebra n, algebra k){
        return fac(n) * ifac(k) * ifac(n - k);
    }

    static algebra P(algebra n){
        return fac(n);
    }

    static algebra A(algebra n, algebra k){
        return fac(n) * ifac(n - k);
    }

    algebra(long long n){
        this->n = n % mod;
    }

    algebra(){
        this->n = 0;
    }
};
