#include <bits/stdc++.h>
using namespace std;
// // 可以处理负数版
// string cA(string a,string b){
// 	int as = a.size(), bs = b.size(), d = as > bs ? as - bs : bs - as;
// 	string s = "0", t = "0";
// 	for (int i = 0;i < d;i++) as > bs ? t += "0" : s += "0";
// 	s += a,t += b;
// 	for ( int i = s.size() - 1; i >= 1; i-- ) {
// 		s[i] += t[i] - '0';
// 		if (s[i] > '9') s[i] -= 10,s[i - 1]++;
// 	}
// 	bool j = true;
// 	for (int i = 0;i < s.size();i++)
// 		if (s[i] != '0') j = false;
// 	if (j) return "0";
// 	return s[0] == '0' ? s.substr( 1, s.size() ) : s;
// }

string cS(string a, string b) {
    int as = a.size(), bs = b.size(), d = as - bs;
    string s = "", t = "";
    for (int i = 0; i < d; i++)
        t += "0";
    s += a, t += b;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] < t[i]) {
            s[i] += 10;
            if (s[i - 1] >= '1')
                s[i - 1]--;
            else {
                int j = i - 1;
                while (s[j] == '0')
                    s[j--] += 9;
                s[j]--;
            }
        }
        s[i] -= (t[i] - '0');
    }
    if (s.size() == 1)
        return s;
    for (int i = 0; i < s.size(); i++) {
        if ('1' <= s[i] && s[i] <= '9')
            return s.substr(i, s.size());
    }
    return "0";
}

// 应用部分
int main() {
    string a, b, c;
    cin >> a >> b;
    c = b;
    int as = a.size(), bs = b.size(), cs, d = as - bs;
    for (int i = 0; i < d - 1; i++)
        c += "0";
    cs = c.size();
    while (c != b) {
        while (as > cs || as == cs && a >= c)
            a = cS(a, c), as = a.size();
        c = c.substr(0, c.size() - 1), cs = c.size();
    }
    while (as > bs || as == bs && a >= b)
        a = cS(a, b), as = a.size();
    cout << a << endl;
    return 0;
}