#include <stdio.h>

int next[1000003];

void insertAfter(int x, int y) {
    next[y] = next[x];
    next[x]= y;
}

void removeAfter(int x) {
    next[x] = next[next[x]];
}

int main() {
    
}