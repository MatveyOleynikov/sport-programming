struct big_integer{
    const int glob_sz = 30;

	int sz;
	vi vals;

	big_integer(){sz=0; vals.resize(glob_sz);}

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

        dbg(mx);

        big_integer res;
        for(int i = 0; i < mx; i++){
            res.vals[i] += this->vals[i] + other.vals[i];
            while (res.vals[i] >= 1000000000){
                res.vals[i + 1] += 1;
                res.vals[i] -= 1000000000;
            }
        }

        res.sz = mx;
        if (res.vals[mx]){
            res.sz = mx + 1;
        }

        return res;
    }

    big_integer* operator =(const big_integer other){
        this->sz = other.sz;
        this->vals = other.vals;
        return this;
    }
};
