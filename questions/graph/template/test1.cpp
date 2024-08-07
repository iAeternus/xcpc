// g++ test1.cpp graph.cpp -o test1
#include <bits/stdc++.h>

#include "graph.h"

int n, m;

void set_up() {
    init();
    n = 6, m = 11;
    
    add_edge(1, 2, 24);
    add_edge(2, 1, 54);
    add_edge(5, 2, 34);
    add_edge(6, 3, 87);
    add_edge(2, 3, 124);
    add_edge(1, 4, 675);
    add_edge(2, 4, 345);
    add_edge(4, 1, 321);
    add_edge(2, 5, 587);
    add_edge(4, 5, 87);
    add_edge(5, 6, 956);
}

void test() {
    for (int i = 0; i <= n; ++i) {
        printf("h[%d] = %d, ", i, head[i]);
    }
    putchar('\n');

    for (int i = 0; i < m; ++i) {
        printf("e[%d].to = %d, ", i, edge[i].to);
    }
    putchar('\n');

    for (int i = 0; i < m; ++i) {
        printf("e[%d].nex = %d, ", i, edge[i].next);
    }
    putchar('\n');

    for_each(2, [](int i) {
        printf("%d ", edge[i].to);
    });
    putchar('\n');
}

void test_dfs() {
    dfs(1, [](int i) {
        printf("%d ", i);
    });
    putchar('\n');
}

void test_bfs() {
    bfs(1, [](int i) {
        printf("%d ", i);
    });
    putchar('\n');
}

void test_dijkstra() {
    printf("%d\n", dijkstra(1, 6));
}

void test_SPFA() {
    printf("%d\n", SPFA(1, 6));
}

void test_SPFA_SLF() {
    printf("%d\n", SPFA_SLF(1, 6));
}

void test_SPFA_LLL() {
    printf("%d\n", SPFA_LLL(1, 6));
}

int main() {
    set_up();

    test();
    test_dfs();
    test_bfs();
    test_dijkstra();
    test_SPFA();
    test_SPFA_SLF();
    test_SPFA_LLL();
}