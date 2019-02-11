#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

void isSameBSTFunc(int a, int b, int n, int *i, int *j) {



}

bool isSameBST(int *a, int *b, int n) {

    int i = 0, j = 0;

    isSameBSTFunc(a, b, n, &i, &j);


}

int main()
{
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n)? "BSTs are same":"BSTs not same");
   return 0;
}
