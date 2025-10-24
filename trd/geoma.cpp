namespace geom
{
    const double eps = 1e-10;

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

    struct line{
        double a, b, c;
        line() { a = b = c = 0; }
        line(const double &a, const double &b, const double &c) : a(a), b(b), c(c) {}
        friend ostream& operator << (ostream& o, const line &l)
        { return o << l.a << " " << l.b << " " << l.c << "\n"; }
        friend istream& operator >> (istream& o, line &l)
        { return o >> l.a >> l.b >> l.c; }
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

    line median(point x, point y, point z){
        point v1 = y - x;
        point v2 = z - x;

        point b = v1 + v2;

        double A = b.y;
        double B = -b.x;
        double C = b.cross(x);

        line ans(A, B, C);

        return ans;
    }

    line bisector(point x, point y, point z){
        point v1 = y - x;
        point v2 = z - x;

        v1 = v1.norm();
        v2 = v2.norm();

        point b = v1 + v2;

        double A = b.y;
        double B = -b.x;
        double C = b.cross(x);

        line ans(A, B, C);

        return ans;
    }

    double dist(line l, point p){
        line norm;
        norm.a = l.b;
        norm.b = -l.a;
        norm.c = -(norm.a * p.x + norm.b * p.y);
        //cout << c << endl;

        double x, y;
        if (norm.a == 0){
            y = -norm.c / norm.b;
        }   else{
            double k = l.a / norm.a;
            l.a -= norm.a * k;
            l.b -= norm.b * k;
            l.c -= norm.c * k;
            y = -l.c / l.b;
        }
        if (norm.a){
            x = (-norm.c - y * norm.b) / norm.a;
        }
        else if (l.a){
            x = (-l.c - y * l.b) / l.a;
        }

        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
}
