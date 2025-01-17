const int maxn = 400005;
const int g = 3, bigp = 479 * (1 << 21) + 1, x = 21;

// LA, LB are length of a[] and b[] (including a[0] and
// b[0])
size_t LA, LB;
int a[maxn], b[maxn], w[maxn];
size_t C, N, L;

int powc(int a, int b) {
  if(b == 0)
    return 1;

  int d = powc(a, b / 2);
  d = ((long long)d * d) % bigp;
  if(b & 1)
    d = ((long long)d * a) % bigp;
  return d;
}

// K is the length of x[]
void FFT(int x[], int K, bool inverse = false) {
  w[0] = 1;
  int G = powc(g, (bigp - 1) / K);

  for(int i = 1; i <= K; ++i) {
    w[i] = ((long long)w[i - 1] * G) % bigp;
  }
  for(int i = 0, j = 0; i < K; ++i) {
    if(i > j)
      swap(x[i], x[j]);
    for(int l = K >> 1; (j ^= l) < l; l >>= 1)
      ;
  }

  for(int i = 2; i <= K; i <<= 1) {
    for(int j = 0; j < K; j += i) {
      for(int l = 0; l < (i >> 1); ++l) {
        int t = ((long long)x[j + l + (i >> 1)] *
                 w[inverse ? (K - (K / i) * l)
                           : (K / i) * l]) %
                bigp;
        x[j + l + (i >> 1)] =
            ((long long)x[j + l] - t + bigp) % bigp;
        x[j + l] += t;
        x[j + l] %= bigp;
      }
    }
  }

  if(inverse) {
    int r = powc(N, bigp - 2);
    for(size_t i = 0; i < N; ++i) {
      a[i] = ((long long)a[i] * r) % bigp;
    }
  }
}

void calculate() {
  N = 1;
  C = LA + LB;
  L = 0;

  while(N <= C) {
    N *= 2;
    ++L;
  }

  for(size_t i = LA; i < N; ++i)
    a[i] = 0;
  for(size_t i = LB; i < N; ++i)
    b[i] = 0;

  FFT(a, N);
  FFT(b, N);

  for(size_t i = 0; i < N; ++i) {
    a[i] = ((long long)a[i] * b[i]) % bigp;
  }

  FFT(a, N, true);
}
