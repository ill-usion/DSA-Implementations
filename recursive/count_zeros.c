#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_zeros_recur(int x, int count)
{
    if (x == 0)
        return count + 1;
    if (x < 10 && x > -10)
        return count;
    else {
        if (x % 10 == 0)
            return count_zeros_recur(x / 10, count + 1);
        return count_zeros_recur(x / 10, count);
    }
}

int count_zeros_better(int n)
{
    if(n == 0)
        return 1;
    else if(n < 10 && n > -10)
        return 0;
    else
        return count_zeros_better(n/10) + count_zeros_better(n%10);
}


int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s x\n", argv[0]);
        return 1;
    }

    int count = count_zeros_recur(atoi(argv[1]), 0);
    printf("%d\n", count);
    return 0;
}
