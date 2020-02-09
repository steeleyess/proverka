#include <stdio.h>
#include <cs50.h>
long normlong(string abc);
int main(void)
{
    int s, p, count = 0;
    long t, ten=100000000000000, ten1=1000000000000000, ten2=1000000000000;
    long number = normlong("Namber: ");
    if((number>=340000000000000&&number<=349999999999999)||(number>=370000000000000&&number<=379999999999999))
    {
        for(int i=0;i<15;i++)
        {
            if(i%2==0)
            {
                s = number/ten;
                count+=s;
                t = number%ten;
                number = t;
                ten/=10;
            }
            else
            {
                s = number/ten;
                if(s<5)
                {
                    s*=2;
                    count+=s;
                    t = number%ten;
                    number = t;
                    ten/=10;
                }
                else
                {
                    s*=2;
                    p = s/10+s%10;
                    s = p;
                    count+=s;
                    t = number%ten;
                    number = t;
                    ten/=10;
                }   
            }        
        }
        if(count%10==0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number>=5100000000000000&&number<=5599999999999999)
    {
        for(int i=0;i<16;i++)
        {
            if(i%2==1)
            {
                s = number/ten1;
                count+=s;
                t = number%ten1;
                number = t;
                ten1/=10;
            }
            else
            {
                s = number/ten1;
                if(s<5)
                {
                    s*=2;
                    count+=s;
                    t = number%ten1;
                    number = t;
                    ten1/=10;
                }
                else
                {
                    s*=2;
                    p = s/10+s%10;
                    s = p;
                    count+=s;
                    t = number%ten1;
                    number = t;
                    ten1/=10;
                }   
            }        
        }
        if(count%10==0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number>=4000000000000000&&number<=4999999999999999)
    {
        for(int i=0;i<16;i++)
        {
            if(i%2==1)
            {
                s = number/ten1;
                count+=s;
                t = number%ten1;
                number = t;
                ten1/=10;
            }
            else
            {
                s = number/ten1;
                if(s<5)
                {
                    s*=2;
                    count+=s;
                    t = number%ten1;
                    number = t;
                    ten1/=10;
                }
                else
                {
                    s*=2;
                    p = s/10+s%10;
                    s = p;
                    count+=s;
                    t = number%ten1;
                    number = t;
                    ten1/=10;
                }   
            }        
        }
        if(count%10==0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number>=4000000000000&&number<=4999999999999)
    {
        for(int i=0;i<13;i++)
        {
            if(i%2==0)
            {
                s = number/ten2;
                count+=s;
                t = number%ten2;
                number = t;
                ten2/=10;
            }
            else
            {
                s = number/ten2;
                if(s<5)
                {
                    s*=2;
                    count+=s;
                    t = number%ten2;
                    number = t;
                    ten2/=10;
                }
                else
                {
                    s*=2;
                    p = s/10+s%10;
                    s = p;
                    count+=s;
                    t = number%ten2;
                    number = t;
                    ten2/=10;
                }   
            }        
        }
        if(count%10==0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
long normlong(string abc)
{
    long m;
    do
    {
        m = get_long("%s", abc);
    }
    while(m<0);
    return m;
}
