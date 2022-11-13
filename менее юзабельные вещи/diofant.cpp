struct diofant{
    static int gcd (int a, int b, int & x, int & y) {
        if (a == 0) {
            x = 0; y = 1;
            return b;
        }
        int x1, y1;
        int d = gcd (b%a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
 
    static bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
        g = gcd (abs(a), abs(b), x0, y0);
        if (c % g != 0)
            return false;
        x0 *= c / g;
        y0 *= c / g;
        if (a < 0)   x0 *= -1;
        if (b < 0)   y0 *= -1;
        return true;
    }
};
