#include <stdio.h>
#include <cs50.h>
int get1_8(string qwe);

int main(void)
{
    int height, k=1;
    height = get1_8("Height: ");
    int l = height-k;
    for (int i=0;i<height;i++)
    {
        for(int j=0;j<l;j++)
        {
            printf(" ");
        }
        for(int m=0;m<k;m++)
        {
            printf("#");
        }
        printf("  ");
        for(int m=0;m<k;m++)
        {
            printf("#");
        }
        k++;
        l--;
        printf("\n");
    }
}
int get1_8(string qwe)
{
    int n;
    do
    {
        n = get_int("%s", qwe);
    }
    while(n<1||n>8);
    return n;
}
