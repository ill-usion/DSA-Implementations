#include "common.h"

typedef struct
{
    int *tab;
    size_t len;
} lookup_t;

lookup_t create_lookup(int *arr, size_t len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
        if (arr[i] > max)
            max = arr[i];

    size_t tab_len = max + 1;
    int *tab = (int *)malloc(sizeof(int) * tab_len);
    memset(tab, 0, tab_len);

    for (int i = 0; i < len; i++)
    {
        tab[arr[i]]++;
    }

    return (lookup_t){tab, tab_len};
}

int key_indexed_search(int val, lookup_t *lookup)
{
    if (lookup->len <= val)
        return -1;

    return lookup->tab[val];
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("%d x1, x2, x3, ..., xn\n", argv[0]);
    }

    size_t len = argc - 1;
    int *arr = parse_numbers(argc, argv);
    lookup_t lookup = create_lookup(arr, len);

    int idx = key_indexed_search(13, &lookup);
    printf("key_indexed_search(13) = %d\n", idx);

    free(lookup.tab);
    return 0;
}