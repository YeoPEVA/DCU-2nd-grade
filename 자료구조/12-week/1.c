#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int list[], int n)
{
    int i,j,temp;
    for(i=n-1; i>0; i--)
    {
        for(j=0;j<i;j++){
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
        }

    }
}

int main(void)
{
    int arraySizeInput = 0;
    int selectInput = 0;
    int tmp = 0;

    scanf("%d %d", &arraySizeInput, &selectInput);

    int arrayValue[arraySizeInput];

    for(int i = 0; i<arraySizeInput; i++)
    {
        scanf("%d", &tmp);
        arrayValue[i] = tmp;
    }

    bubble_sort(arrayValue, arraySizeInput);

    printf("%d", arrayValue[selectInput-1]);

    return 0;
}