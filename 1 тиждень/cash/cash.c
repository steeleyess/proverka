#include <cs50.h>
#include <stdio.h>
#include <math.h>
float normfloat(string lol);
int main(void)
{
    int count=0; 
    float cash = normfloat("Change: ");
    int coins = round(cash*100);
    if(coins>=25)
    {
        int k = coins/25;
        count+=k;
        int m = coins%25;
        if(m==0)
        {
            printf("%i\n", count);
            return 0;
        }
        coins=m;
    }
    if(coins>=10)
    {
      int k = coins/10;
        count+=k;
        int m = coins%10;
        if(m==0)
        {
            printf("%i\n", count);
            return 0;
        }
        coins=m;  
    }
    if(coins>=5)
    {
      int k = coins/5;
        count+=k;
        int m = coins%5;
        if(m==0)
        {
            printf("%i\n", count);
            return 0;
        }
        coins=m;  
    }
    count+=coins;
    printf("%i\n", count);
    return 0;
}
float normfloat(string lol)
{
    float k;
    do 
    {
        k = get_float("%s", lol);
    }
    while(k<0);
    return k;
}


