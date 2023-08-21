#include "atcoder/convolution"

template <class T> class RelaxedConvolution {
    int n;
    std::vector<T> f, g, h;

  public:
    RelaxedConvolution() : n(0) {}

    T query(T a, T b) {
        f.emplace_back(a);
        g.emplace_back(b);
        h.emplace_back(0);
        if (n > 0) h.emplace_back(0);
        int p = __builtin_ctz(n + 2);
        for (int k = 0; k <= p; k++) {
            {
                std::vector<T> a1(f.begin() + (1 << k) - 1, f.begin() + (1 << (k + 1)) - 1);
                std::vector<T> b1(g.end() - (1 << k), g.end());
                auto c1 = atcoder::convolution(a1, b1);
                for (int i = 0; i < (1 << (k + 1)) - 1; i++) h[n + i] += c1[i];
            }
            if ((1 << p) == n + 2 and k == p - 1) break;
            {
                std::vector<T> a2(f.end() - (1 << k), f.end());
                std::vector<T> b2(g.begin() + (1 << k) - 1, g.begin() + (1 << (k + 1)) - 1);
                auto c2 = atcoder::convolution(a2, b2);
                for (int i = 0; i < (1 << (k + 1)) - 1; i++) h[n + i] += c2[i];
            }
        }
        return h[n++];
    }
};