#include <stdio.h>
// Company XYZ maintains its employee’s daily attendance
// (0 for Absent and 1 for Present) in a one dimensional array. 
// The HR manager of the company wants to sort this attendance
// data in linear time i.e. O(N). You are required to write the
// code using suitable data structure(s) to solve his problem.
void heapSort(int arr[], int n) {
  // heapify array

  int i = 1;
  while (i < n) {
    int ci = i;
    int pi = (ci - 1) / 2;
    while (ci > 0) {
      pi = (ci - 1) / 2;
      if (arr[pi] > arr[ci]) {
        int temp = arr[pi];
        arr[pi] = arr[ci];
        arr[ci] = temp;
        ci = pi;
      } else {
        break;
      }
    }
    i++;
  }
  // down heapify
  int fi = 0;
  int li = n - 1;

  while (li >= 0) {
    int temp = arr[li];
    arr[li] = arr[fi];
    arr[fi] = temp;

    li--;
    int pi = fi;
    int lci = (2 * fi) + 1;
    int rci = (2 * fi) + 2;

    while (lci <= li) {
      int mi = pi;
      if (arr[mi] > arr[lci]) {
        mi = lci;
      }
      if (rci <= li && arr[mi] > arr[rci]) {
        mi = rci;
      }
      if (mi == pi) {
        break;
      }
      int temp = arr[mi];
      arr[mi] = arr[pi];
      arr[pi] = temp;
      lci = (2 * pi) + 1;
      rci = (2 * pi) + 2;
    }
  }
}
int main()
{
    int arr[100];
    int n,d,p;
    printf("Enter the no of employees for which data is to be stored : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    
    printf("Enter the no of days for which data is to be stored : ");
    scanf("%d",&d);
    for (int i = 0; i < d; i++)
    {
        printf("\nDAY %d\n",i+1);
      for (int j = 0;j <n; j++)
      {
        printf("Enter the presence of employee %d : ",j+1);
        scanf("%d",&p);
        if (p==1)
        {
            arr[j]++;
        }
      }
    }
    printf("DATA BROFRE SORTING \n");
    for (int i = 0; i < n; i++)
    {
        printf("emp_%d = %d\n",i+1,arr[i]);
    }
    
    heapSort(arr,n);
    printf("\nDATA AFTER SORTING\n");

    

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}