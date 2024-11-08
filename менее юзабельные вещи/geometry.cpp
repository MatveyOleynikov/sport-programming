//ГЕОМА
//!важно при работе с векторами и пересечением окружностей
//!не забывать приводить во многих случаях к нулевой координате

//atan2, acos, asin -> [-pi; pi], при < 0 надо + 2pi для [0; 2pi]
//из рад в градусы -> val * 180.0 / pi
//из градусов в рад -> val * pi / 180.0
//вектор нормали прямой = {A, B}
//получить прямую через точку и вектор нормали -> A; B; C = -x * A - y * B;
//A * x + B * y + C < eps -> под прямой
//A * x + B * y + C = 0 -> на прямой
//A * x + B * y + C > eps -> над прямой
#define ld long double
ld pi = acos(-1);
ld eps = 1e-9;

bool isEq(ld v1, ld v2) {
    return fabsl(v1 - v2) < eps;
}

bool isLow(ld v1, ld v2) {
    return v1 - eps < v2;
}

bool isGret(ld v1, ld v2) {
    return v1 > v2 - eps;
}

struct Point {
    ld x, y;

    bool operator<(const Point p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    //Нормализовать вектор
    void normalizeVector() {
        ld dist = sqrtl(x * x + y * y);
        x /= dist;
        y /= dist;
    }
};

//Пифагор
ld pif(Point p1, Point p2) {
    ld x = p1.x - p2.x;
    ld y = p1.y - p2.y;
    return sqrtl(x * x + y * y);
}

//Скалярное п.
//< eps -> угол между векторами тупой
//>= eps -> угол острый или прямой
ld scalar(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

//Векторное п.
// < 0 -> угол между векторами > 180
// >= 0 -> угол <= 180
ld vectorn(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

//Угол между векторами
ld angleVectors(Point p1, Point p2) {
    ld dist1 = pif(Point({ 0, 0 }), p1);
    ld dist2 = pif(Point({ 0, 0 }), p2);
    ld scal = scalar(p1, p2);
    ld vect = vectorn(p1, p2);
    ld ang = acos(scal / (dist1 * dist2));
    if (vect < 0) ang = 2 * pi - ang;
    return ang;
}

struct Cycle {
    Point p; ld r;
    Cycle(Point p, ld r) {
        this->p = p;
        this->r = r;
    }
};

struct Line {
    ld a, b, c;
    Line(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.y * p2.x - p1.x * p2.y;
    }

    //Получить линию пересечения 2 окружностей
    //!1. приветси с 0 координате
    //!2. чекнуть радиусы окружностей
    //!3. не забыть вернуть к начальным координатам
    Line(Cycle c1, Cycle c2) {
        a = -2 * c2.p.x;
        b = -2 * c2.p.y;
        c = c2.p.x * c2.p.x + c2.p.y * c2.p.y + c1.r * c1.r - c2.r * c2.r;
    }

    //Расстояние от точки до прямой
    ld distFromPoint(Point p) {
        return fabsl(a * p.x + b * p.y + c) / sqrtl(a * a + b * b);
    }

    ld func(Point p) {
        return a * p.x + b * p.y + c;
    }
};

//Пересечение прямых
bool intersectLines(Line o1, Line o2, Point& p) {
    ld zn = o1.a * o2.b - o2.a * o1.b;

    if (isEq(zn, 0)) {
        return false;
    }

    ld x = (o1.b * o2.c - o2.b * o1.c) / zn;
    ld y = (o2.a * o1.c - o2.c * o1.a) / zn;
    p = { x, y };
    return true;
}

//Пересечение окружности и прямой
//Окржность должна быть в нулевой координате!!!
int intersectCycleWithLine(Line line, Cycle cycle, Point& p1, Point& p2) {
    ld a = line.a; ld b = line.b; ld c = line.c; ld r = cycle.r;
    ld x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + eps) {
        return 0;
    }
    else if (abs(c * c - r * r * (a * a + b * b)) < eps) {
        p1 = { x0, y0 };
        return 1;
    }
    else {
        ld d = r * r - c * c / (a * a + b * b);
        ld mult = sqrtl(d / (a * a + b * b));
        ld ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        p1 = { ax, ay };
        p2 = { bx, by };
        return 2;
    }
}

//Многоульник должен быть не замкнутым!
struct Polygon {
    vector<Point> poly;

    ld area() {
	poly.push_back(poly.front());
        ld ans = 0.0;
        for (int i = 1; i < poly.size(); ++i) {
            ans += vectorn(poly[i - 1], poly[i]);
        }
	poly.pop_back();
        return fabsl(ans) / 2.0;
    }
    
    bool inside(Point p) {
        int l = 1;
        int r = (int)poly.size() - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            Line line(poly[0], poly[m]);
            if (line.func(p) > 0) r = m;
            else l = m;
        }
 
        Polygon polTot; polTot.poly = { poly[0], poly[l], poly[r] };
        Polygon pol1; pol1.poly = { poly[0], poly[l], p };
        Polygon pol2; pol2.poly = { poly[0], p, poly[r] };
        Polygon pol3; pol3.poly = { p, poly[l], poly[r] };
        return (isEq(polTot.area(), pol1.area() + pol2.area() + pol3.area()));
    }

    bool insideNoneConvex(Point p) {
        int cnt = 0;
        for (int i = 0; i < poly.size(); ++i) {
            Point l = poly[i];
            Point r = poly[(i + 1) % poly.size()];
            if (l.y == r.y) continue;
            if (p.y == max(l.y, r.y) && p.x < min(l.x, r.x)) {
                cnt++;
                continue;
            }
            if (p.y == min(l.y, r.y)) continue;
            if (l.y > r.y) swap(l, r);
            ld le = (r.x - l.x) * (p.y - l.y);
            ld re = (r.y - l.y) * (p.x - l.x);
            ld res = le - re;
            if (fabsl(res) < eps) return true;
            if (res > eps && min(l.y, r.y) <= p.y && p.y <= max(l.y, r.y)) cnt++;
        }
        return (cnt & 1);
    }

    //Алгоритм поиска выпуклой оболочки (Грэхема)
    //плохо работает если точки не int
    bool isUp(Point& o1, Point& o2, Point& o3) {
        Line line(o1, o2);
        return (line.func(o3) > 0);
    }

    bool isDown(Point& o1, Point& o2, Point& o3) {
        Line line(o1, o2);
        return (line.func(o3) < 0);
    }

    Polygon scanGraham() {
        vector<Point> a = poly;
        int n = a.size();
        sort(a.begin(), a.end());
        vector<Point> one, two;
        one.push_back(a[0]);
        two.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (i == n - 1 || isUp(a[0], a[n - 1], a[i])) {
                while (one.size() >= 2 && isUp(one[one.size() - 2], one[one.size() - 1], a[i])) one.pop_back();
                one.push_back(a[i]);
            }
            if (i == n - 1 || isDown(a[0], a[n - 1], a[i])) {
                while (two.size() >= 2 && isDown(two[two.size() - 2], two[two.size() - 1], a[i])) two.pop_back();
                two.push_back(a[i]);
            }
        }

        vector<Point> res;
        for (int i = 0; i < (int)one.size(); ++i) {
            res.push_back(one[i]);
        }
        for (int i = (int)two.size() - 2; i > 0; --i) {
            res.push_back(two[i]);
        }

        Polygon convex; convex.poly = res;
	return convex;
    }
};
