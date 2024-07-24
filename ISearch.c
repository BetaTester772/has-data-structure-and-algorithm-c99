//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

int quick(int a[], int left, int right) {
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

int search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (arr[high] != arr[low] && x >= arr[low] && x <= arr[high]) {
        mid = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low]));
        if (arr[mid] < x)
            low = mid + 1;
        else if (x < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    if (x == arr[low])
        return low;
    else
        return -1;
}

int main() {
    int i;
    int *x;
    int nx;
    printf("보간 검색\n요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    quick(x, 0, nx - 1);
    puts("completed");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    int ky;
    printf("검색값: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
    free(x);
    return 0;
}