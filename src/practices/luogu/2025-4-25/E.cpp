#include <bits/stdc++.h>

const int N = 105;
int n;

struct BigInt {
    int d[N], len;
    BigInt() {
        memset(d, 0, sizeof(d));
        len = 1;
    }
    BigInt(int num) { *this = num; }
    BigInt(char* num) { *this = num; }
    void clean() {
        while (len > 1 && !d[len - 1]) len--;
    }
    BigInt operator=(const char* num) {
        memset(d, 0, sizeof(d));
        len = strlen(num);
        for (int i = 0; i < len; i++) d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    BigInt operator=(int num) {
        char s[20];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    BigInt operator+(const BigInt& b) {
        BigInt c = *this;
        int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] += b.d[i];
            if (c.d[i] > 9) c.d[i] %= 10, c.d[i + 1]++;
        }
        while (c.d[i] > 9) c.d[i++] %= 10, c.d[i]++;
        c.len = std::max(len, b.len);
        if (c.d[i] && c.len <= i) c.len = i + 1;
        return c;
    }
    BigInt operator-(const BigInt& b) {
        BigInt c = *this;
        int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    BigInt operator*(const BigInt& b) const {
        int i, j;
        BigInt c;
        c.len = len + b.len;
        for (j = 0; j < b.len; j++)
            for (i = 0; i < len; i++)
                c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
            c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    BigInt operator/(const BigInt& b) {
        int i, j;
        BigInt c = *this, a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1))
                    break;
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    BigInt operator%(const BigInt& b) {
        int i, j;
        BigInt a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1)) break;
            a = a - b * j;
        }
        return a;
    }
    BigInt operator+=(const BigInt& b) {
        *this = *this + b;
        return *this;
    }
    bool operator<(const BigInt& b) const {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i])
                return d[i] < b.d[i];
        return false;
    }
    bool operator>(const BigInt& b) const { return b < *this; }
    bool operator<=(const BigInt& b) const { return !(b < *this); }

    bool operator>=(const BigInt& b) const { return !(*this < b); }
    bool operator!=(const BigInt& b) const { return b < *this || *this < b; }
    bool operator==(const BigInt& b) const { return !(b < *this) && !(b > *this); }

    std::string str() const {
        char s[N] = {};
        for (int i = 0; i < len; i++)
            s[len - 1 - i] = d[i] + '0';
        return s;
    }

    bool check() const {
        auto s = str();
        auto rev = s;
        std::reverse(rev.begin(), rev.end());
        return s == rev;
    }
};

std::istream& operator>>(std::istream& in, BigInt& x) {
    std::string s;
    in >> s;
    x = s.c_str();
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& x) {
    out << x.str();
    return out;
}

std::string add(std::string a) {
    std::string b = a;
    std::reverse(b.begin(), b.end());
    int x, y, t = 0, len = a.size();
    for (int i = len - 1; i >= 0; --i) {
        x = (a[i] >= 'A') ? (a[i] - 'A' + 10) : (a[i] - '0');
        y = (b[i] >= 'A') ? (b[i] - 'A' + 10) : (b[i] - '0');
        x += y + t;
        t = (x >= n) ? 1 : 0;
        if (t == 1)
            x -= n;
        a[i] = (x > 9) ? (x - 10 + 'A') : (x + '0');
    }
    if (t == 1)
        a = "1" + a;
    return a;
}

int main() {
    BigInt m;
    std::cin >> n >> m;
    int i;
    for (i = 0; i <= 30 && !m.check(); ++i) {
        m = BigInt(add(m.str()).data());
    }
    if (i > 30) {
        std::cout << "Impossible!\n";
    } else {
        std::cout << "STEP=" << i << std::endl;
    }
}