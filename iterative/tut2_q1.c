#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int add_ndig(int n, int x1, int x2)
{
    int result = 0;
    int carry = 0;
    int place = 1; 
    for (int i = 0; i < n; i++)
    {
        int res = ((x1 / place % 10) + (x2 / place % 10)) + carry;
        carry = res / 10;
        result += (res % 10) * place; 
        place *= 10;
    }
    result += carry * pow(10, n);

    return result;
}

int mul_ndig(int n, int x1, int x2)
{
   int result[2 * n];
   memset(result, 0, 2 * n * sizeof(int));

   int placex1 = 1;
   for (int i = 0; i < n; i++)
   {
       int placex2 = 1;
       for (int j = 0; j < n; j++)
       {
           int mul = (x1 / placex1 % 10) * (x2 / placex2 % 10);
           result[i + j] += mul % 10;
           result[i + j + 1] += mul / 10;

           placex2 *= 10;
           if (result[i + j] >= 10) {
               result[i + j + 1] += result[i + j] / 10;
               result[i + j] %= 10;
           }
       }
        placex1 *= 10;
    } 
    int ret = 0;
    for (int i = 0; i < 2 * n; i++)
        ret += result[i] * pow(10, i);

    return ret;
}

int main(int argc, char** argv)
{
    int x1 = 3579, x2 = 8642;
    const int n = 4;
    
    int add_res = add_ndig(n, x1, x2);
    printf("%d + %d = %d\n", x1, x2, add_res);

    int mul_res = mul_ndig(n, x1, x2);
    printf("%d * %d = %d\n", x1, x2, mul_res);
    return 0;
}
