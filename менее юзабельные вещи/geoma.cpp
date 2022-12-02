namespace geom
{
    // tested: uva10002
    template<class T>
    struct vec_t {
        T x, y;
        vec_t() { x = y = T(0); }
        vec_t(const T &x, const T &y) : x(x), y(y) {}
        T& operator[](int idx)
        { return idx ? y : x; }
        const T& operator[](int idx) const
        { return idx ? y : x; }
        vec_t operator + (const vec_t &b) const
        { return vec_t(x + b.x, y + b.y); }
        vec_t operator - (const vec_t &b) const
        { return vec_t(x - b.x, y - b.y); }
        vec_t operator - () const
        { return vec_t(-x, -y); }
        vec_t operator + () const
        { return *this; }
        vec_t operator * (const T &b) const
        { return vec_t(x * b, y * b); }
        vec_t operator / (const T &b) const
        { return vec_t(x / b, y / b); }
        vec_t& operator += (const vec_t &b)
        { return *this = *this + b; }
        vec_t& operator -= (const vec_t &b)
        { return *this = *this - b; }
        vec_t& operator *= (const T &b)
        { return *this = *this * b; }
        vec_t& operator /= (const T &b)
        { return *this = *this / b; }
        T dot(const vec_t &b) const
        { return x * b.x + y * b.y; }
        T cross(const vec_t &b) const
        { return x * b.y - y * b.x; }
        vec_t normal() const
        { return vec_t(-y, x); }
        vec_t norm() const
        { return *this / len(); }
        T len2() const
        { return x * x + y * y; }
        double len() const
        { return sqrt((double)len2()); }
        pair<T, T> to_pair() const
        { return pair<T, T>(x, y); }
        bool operator < (const vec_t &b) const
        { return to_pair() < b.to_pair(); }
        bool operator > (const vec_t &b) const
        { return to_pair() > b.to_pair(); }
        bool operator <= (const vec_t &b) const
        { return to_pair() <= b.to_pair(); }
        bool operator >= (const vec_t &b) const
        { return to_pair() >= b.to_pair(); }
        bool operator == (const vec_t &b) const
        { return to_pair() == b.to_pair(); }
        bool operator != (const vec_t &b) const
        { return to_pair() != b.to_pair(); }
        friend ostream& operator << (ostream& o, const vec_t &a)
        { return o << a.x << " " << a.y << "\n"; }
        friend istream& operator >> (istream& o, vec_t &a)
        { return o >> a.x >> a.y; }
    };


    using point = vec_t<double>;

    // CONVEX HULL: last point == first point
    vector<point> convex_hull(vector<point> a) {
        int n = a.size(), k = 0;
        vector<point> p(n * 2);
        sort(a.begin(), a.end());

        for(int i = 0; i < n; p[k++] = a[i++])
            while(k > 1 && (p[k - 1] - p[k - 2]).cross(p[k - 1] - a[i]) >= 0) --k;
        for(int i = n - 2, w = k; i >= 0; p[k++] = a[i--])
            while(k > w && (p[k - 1] - p[k - 2]).cross(p[k - 1] - a[i]) >= 0) --k;
        p.resize(k);
        return p;
    }

    double angle(point a, point b){
        long double cosa = a.dot(b) / (a.len() * b.len());

        long double sina = a.cross(b) / (a.len() * b.len());

        long double ans = atan2(sina, cosa);

        if (ans < 0)
           ans += 2 * pi;

        return ans;
    }

    double square(vector<point> a){
        double ans = 0;
        for (int i = 0; i < a.size(); ++i){
            point f = a[i], s = a[(i + 1) % a.size()];
            ans += f.cross(s);
        }
        return abs(ans / 2);
    }
}
