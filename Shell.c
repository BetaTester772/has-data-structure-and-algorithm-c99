//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void shell(int a[], int n) {
    int i, j, h;
    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
}

void improved_shell(int a[], int n) {
    int i, j, h;
    for (h = 1; h < n / 9; h = h * 3 + 1);
    for (; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
}

int main() {
    int i;
    int *x;
    int nx;
    printf("셸 정렬\n요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
//    shell(x, nx);
    improved_shell(x, nx);
    puts("completed");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}