namespace IO {
    const int SIZE = 1 << 23;
    char ibuf[SIZE], *iS, *iT;
    char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
    bool flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return true;
    }
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    #define pc(x) (*oS++ = x) 
    int read() {
        int x = 0, f = 0;
        char c = gc();
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = 10 * x + c - '0', c = gc();
        return f ? -x : x;
    }
    char qu[55]; int qlen;
    template <class T> void print(T x) {
        if (!x) pc('0');
        if (x < 0) pc('-'), x = -x;
        while (x) qu[++qlen] = x % 10 + '0', x /= 10;
        while (qlen) pc(qu[qlen--]);
    }
    template <class T> void print(T x, char charset) {
        print(x), pc(charset);
    }
    struct Flusher {
        ~Flusher() {
          flush();
        }
    } flusher;
}
using namespace IO;