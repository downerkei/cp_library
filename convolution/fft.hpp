struct FFT{
    // k番目の1の原始n乗根
    complex<double> n_th_root(int n, int k) {
        double t = 2 * M_PI * k / n;
        return complex<double> (cos(t), sin(t));
    }

    // ビット反転列の生成
    vector<int> bit_reversal(int n) {
        vector<int> b(n, 0);
        int p = 1, d = n / 2;
        while(p < n) {
            for(int i = 0; i < p; i++) {
                b[i | p] = b[i] | d;
            }
            p *= 2;
            d /= 2;
        }

        return b;
    }

    // DFT，IDFTを行う
    // invによって切り替え
    vector<complex<double>> transform(vector<complex<double>>& c, bool inv=false) {
        int n = 1; while(n < c.size()) n *= 2;

        vector<int> br = bit_reversal(n);

        vector<complex<double>> t(n);

        for(int i = 0; i < n; i++) {
            t[br[i]] = c[i]; 
        }

        for(int h = 1; h < n; h *= 2) {
            for(int l = 0; l < n; l += (2 * h)) {
                for(int i = 0; i < h; i++) {
                    complex<double> v0 = t[l + i];
                    complex<double> v1 = t[l + h + i] * n_th_root(h * 2, i);
                    t[l + i] = v0 + v1;
                    t[l + h + i] = v0 - v1;
                }
            }
        }

        // DFTならそのまま返す
        if(!inv) return t;

        // IDFTなら逆順に並び替え，nで割る
        reverse(t.begin() + 1, t.end());
        for(int i = 0; i < n; i++) {
            t[i] /= n;
        }

        return t;
    }

    // a, bを畳み込む
    // 出力は2冪
    vector<complex<double>> convolution(vector<complex<double>>& a, vector<complex<double>>& b) {
        int n = 1; while(n < a.size() + b.size() - 1) n *= 2;

        a.resize(n);
        b.resize(n);

        auto fa = transform(a);
        auto fb = transform(b);

        for(int i = 0; i < n; i++) {
            fa[i] *= fb[i];
        }

        return transform(fa, true);
    }
};