#include <stdio.h>
// Company ABC maintains its daily sale amount
// in a one-dimensional array.  The sales manager
// of the company wants to find a pair with the
// given total sale amount from the stored sales 
// data if any. You are required to write the code 
// using suitable data structure(s) to solve his problem.
int main()
{
    int flag = 0;
    int n, d;
    int arr[100];
    printf("Enter the no. of days for which data is to be analysed : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data of day-%d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the data you want sum in a pair : ");
    scanf("%d", &d);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == d && i != j)
            {
                printf("The sales on day %d --> (%d) and day %d --> (%d) sum up to (%d)\n", i+1, arr[i], j+1, arr[j], d);
                flag = 1;
                break;
            }
            if(flag==1){
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("No such pair found");
    }
    return 0;
}