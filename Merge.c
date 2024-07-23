//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>

static int *buff;

static void __mergesort (int a[], int left, int right) {
    if (left < right) {
        int i;
        int center = (left + right) / 2;
        int p = 0;
        int j = 0;
        int k = left;
        __mergesort(a, left, center);
        __mergesort(a, center + 1, right);
        for (i = left; i <= center; i++) {
            buff[p++] = a[i];
        }
        while (i <= right && j < p) {
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        }
        while (j < p) {
            a[k++] = buff[j++];
        }
    }
}

int mergesort(int a[], int n) {
    if ((buff = calloc(n, sizeof(int))) == NULL) {
        return -1;
    }
    __mergesort(a, 0, n - 1);
    free(buff);
    return 0;
}


int main() {
    int i;
    int *x;
    int nx;
    printf("병합 정렬\n요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    mergesort(x, nx);
    puts("completed");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}