int l = 0, r = n, EPS = 1; // входные данные
while (r - l > EPS) {
   int m1 = l + (r - l) / 3,
      m2 = r - (r - l) / 3;
   if (f(m1, a, n, q) < f(m2, a, n, q))
      l = m1;
   else
      r = m2;
}
