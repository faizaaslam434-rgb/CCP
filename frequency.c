#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *a, const void *b) {
    const int lhs = *(const int *)a;
    const int rhs = *(const int *)b;
    return (lhs > rhs) - (lhs < rhs);
}

int main(void) {
    int n;

    if (printf("Enter number of elements: ") < 0) {
        return 1;
    }

    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size input.\n");
        return 1;
    }

    int *values = malloc((size_t)n * sizeof(*values));
    if (!values) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Invalid element input.\n");
            free(values);
            return 1;
        }
    }

    qsort(values, (size_t)n, sizeof(*values), compare_ints);

    printf("\nElement frequencies:\n");
    for (int i = 0; i < n;) {
        int current = values[i];
        int count = 1;
        while (i + count < n && values[i + count] == current) {
            ++count;
        }

        printf("%d occurs %d time%s\n", current, count, count == 1 ? "" : "s");
        i += count;
    }

    free(values);
    return 0;
}
