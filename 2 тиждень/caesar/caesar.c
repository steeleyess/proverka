#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int a, string b[])
{
    int key = 0;
    if (a!=2)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    for(int i=0, n=strlen(b[1]);i<n;i++)
    {
        if(b[1][i]<'0'||b[1][i]>'9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    key =  atoi ( b[1]);
    if (key>=26)
    {
        key%=26;
    }
    string vvid = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i=0, n=strlen(vvid);i<n;i++)
    {
        int chislo = vvid[i];
        if(chislo>=97&&chislo<=122)
        {
            chislo+=key;
            if (chislo>122)
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
        else if(chislo>=65&&chislo<=90)
        {
            chislo+=key;
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
        else 
        {
            printf("%c", vvid[i]);
        }
    }
    printf("\n");
}
