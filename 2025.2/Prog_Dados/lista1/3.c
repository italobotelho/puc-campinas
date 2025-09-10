# include <stdio.h>

int main()
{
    int A = 2, B = 8, C = 10, Y = 3;

    if((A * B) > (C + B))
    {
        Y+= ((C+1)/A);
        B=++Y;
        C=Y++ - A;
    }
    else
    {
        Y+= ((B*3)/(A+C+4));
        B=--Y;
        C=Y-- + A;
    }
    printf("\n\tA=%d B=%d C=%d Y=%d\n", A, B, C, Y);
    
    return 0;
}