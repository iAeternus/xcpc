#include <bits/stdc++.h>

const int N = 1e8;
int prime[6000000]; //保存素数
bool vis[N + 4];    //记录是否被筛

void euler_sieve(int n) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= n; i++) //检查每个数，筛去合数
    {
        if (!vis[i])
            prime[cnt++] = i;         //如果没有被筛过，是素数，记录下来。
        for (int j = 0; j < cnt; j++) //用已经得到的素数去筛后面的数。
        {
            if (prime[j] > n / i) //只筛小于或等于n的数，大于直接退出
                break;
            vis[i * prime[j]] = 1; //用最小质因数筛去x
            if (i % prime[j] == 0) //如果i能整除它，表明i肯定不是x的最小质因数，
                break;
        }
    }
    //return cnt;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    euler_sieve(n);
    while (q--) {
        int k;
        //cin>>k;
        scanf("%d", &k);
        printf("%d\n", prime[k - 1]);
        //cout<<prime[k-1]<<"\n";
    }
}