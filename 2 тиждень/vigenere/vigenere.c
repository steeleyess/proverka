#include <cs50.h>
#include <stdio.h>
#include <string.h>
int keys(char a);

int main(int a, string b[])
{
    int zero = 0;
    if (a!=2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    for(int i=0, n=strlen(b[1]);i<n;i++)
    {
        if(b[1][i]<'A' || (b[1][i]>'Z' && b[1][i]<'a') || b[1][i]>'z')
        {
            printf("invalid keyword\n");
            return 1;
        }
    }
    int n=strlen(b[1]);
    int keyss[n];
    for(int i=0;i<n;i++)
    {
        keyss[i] = keys(b[1][i]);
    }
    string vvid = get_string("plaintext:  ");
    printf("ciphertext: ");
    int m = strlen(vvid);
    for(int i = 0;i<m;i++)
    {
        int chislo = vvid[i];
        if((chislo>=97&&chislo<=122)||(chislo>=65&&chislo<=90))
        {
            int ost1 = (i-zero)%n;
            if(chislo>=97&&chislo<=122)
            {
                chislo+=keyss[ost1];
                if(chislo>122)
                {
                    int ost = chislo-122;
                    chislo = 97+ost-1;
                    printf("%c",chislo);
                }
                else
                {
                    printf("%c",chislo);
                }
            }
            else 
            {
                chislo+=keyss[ost1];
                if(chislo>90)
                {
                    int ost = chislo-90;
                    chislo=65+ost-1;
                    printf("%c",chislo);
                }
                else
                {
                    printf("%c",chislo);

                }
            }
        }
        else
        {
            printf("%c",chislo);
            zero++;
        }
        
    }
    printf("\n");
}
int keys(char a)
{
    int b = a;
    if(b>=97&&b<=122)
    {     
        int c = b-97;
        return c;
    }
    else
    {
        int c = b-65;
        return c;
    }
}
