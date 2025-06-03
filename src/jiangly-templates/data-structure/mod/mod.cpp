#include <bits/stdc++.h>

using i64 = int64_t;
using i128 = __int128_t;

// a^b
template <typename T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b >>= 1, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

// (a * b) % p
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template <i64 P>
struct MLong {
    i64 x;
    constexpr MLong() :
            x() {}
    constexpr MLong(i64 x) :
            x(norm(x % getMod())) {}

    static i64 mod;

    constexpr static i64 getMod() {
        return P > 0 ? P : mod;
    }

    constexpr static void setMod(i64 mod_) {
        mod = mod_;
    }

    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr i64 val() const {
        return x;
    }

    explicit constexpr operator i64() const {
        return x;
    }

    constexpr MLong operator-() const {
        MLong res{};
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MLong& operator*=(MLong rhs) & {
        x = mul(x, rhs, getMod());
        return *this;
    }

    constexpr MLong& operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MLong& operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MLong& operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr istream& operator>>(istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }

    friend constexpr ostream& operator<<(ostream& os, const MLong& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
i64 MLong<0LL>::mod = i64(1E18) + 9;

template <int P>
struct MInt {
    int x;

    constexpr MInt() :
            x{} {}

    constexpr MInt(i64 x) :
            x{norm(x % getMod())} {}

    static int mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return mod;
        }
    }

    constexpr static void setMod(int mod_) {
        mod = mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt& operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt& operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt& operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt& operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr istream& operator>>(istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr ostream& operator<<(ostream& os, const MInt& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
int MInt<0>::mod = 998244353;

template <int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;