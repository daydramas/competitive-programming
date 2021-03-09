void ckmin(int *a, int b) {
    if (*a > b)
        *a = b;
}
int minSwap(int* A, int n, int* B, int m){
    int d0 = 0, d1 = 1, n0, n1;
    for (int i = 1; i < n; ++i) {
        n0 = n1 = n;
        if (A[i] > A[i - 1] && B[i] > B[i - 1])
            ckmin(&n0, d0), ckmin(&n1, d1 + 1);
        if (A[i] > B[i - 1] && B[i] > A[i - 1])
            ckmin(&n0, d1), ckmin(&n1, d0 + 1);
        d0 = n0, d1 = n1;
    }
    return (d0 < d1 ? d0 : d1);
}