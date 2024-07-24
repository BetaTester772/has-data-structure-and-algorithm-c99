//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void quick(int a[], int left, int right) {
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    if (left < pr) quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
}

int BSearch(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if (a[pc] == key) {
            return pc;
        } else if (a[pc] < key) {
            pl = pc + 1;
        } else {
            pr = pc - 1;
        }
    } while (pl <= pr);
    return -1;
}

int main() {
    int i, nx, ky, idx;
    int *x;
    puts("이진 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    quick(x, 0, nx - 1);
    printf("sorted\n");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    idx = BSearch(x, nx, ky);
    if (idx == -1) {
        puts("검색에 실패했습니다.");
    } else {
        printf("%d는 x[%d]에 있습니다.\n", ky, idx);
    }
    free(x);
    return 0;
}