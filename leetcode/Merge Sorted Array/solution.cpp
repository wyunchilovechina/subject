void merge(int A[], int m, int B[], int n) {
    int ptr_a = m - 1;
    int ptr_b = n - 1;
    int ptr_merge = m + n - 1;

    while (ptr_a >= 0 && ptr_b >= 0) {
        if (B[ptr_b] > A[ptr_a]) {
            A[ptr_merge] = B[ptr_b];
            --ptr_b;
        } else {
            A[ptr_merge] = A[ptr_a];
            --ptr_a;
        }
        --ptr_merge;
    }
    
    if (ptr_b >= 0) {
        while (ptr_merge >= 0) {
            A[ptr_merge] = B[ptr_b];
            --ptr_b;
            --ptr_merge;
        }
    }
}