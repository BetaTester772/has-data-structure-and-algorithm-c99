//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void selection(int a[], int n) {
    int k = 0;
    while (k < n - 1) {
        int j;
        int last = n - 1;
        for (j = n - 1; j > k; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        }
        k = last;
    }
}

int main() {
    int i;
    int *x;
    int nx;
    printf("버블 정렬\n요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    selection(x, nx);
    puts("completed");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}