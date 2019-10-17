#include<stdio.h>
#include<stdlib.h>

int min(int a[]);
void swap(int *, int *);
void bupheapify(int a[],int n, int i);
void tdownheapify(int a[], int n, int i);
void add(int a[], int *n, int x);
void update_key(int a[], int n, int i,int x);
void build_heap(int a[] , int n);
void print_heap(int a[], int n);
int delete_min(int a[], int *n);
void heapsort(int a[], int n);

int main()
{
    int n;
    //int a[n];
    scanf("%d",&n);
    int a[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    build_heap(a,n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    delete_min(a,&n);
    print_heap(a,n);
    add(a,&n,20);
    print_heap(a,n);
    add(a,&n,2);
    print_heap(a,n);
    add(a,&n,45);
    print_heap(a,n);
    add(a,&n,39);
    print_heap(a,n);
    add(a,&n,56);
    print_heap(a,n);
    add(a,&n,900);
    print_heap(a,n);
    add(a,&n,390);
    print_heap(a,n);
    add(a,&n,561);
    print_heap(a,n);
    add(a,&n,986);
    print_heap(a,n);
    heapsort(a,n);
    print_heap(a,n);

}

void heapsort(int a[], int n)
{
    int arr[n];
    int m=n;
    for(int i=0;i<n;i++)
    {
        arr[i] = delete_min(a,&m);
    }
    for(int i=0;i<n;i++)
    {
        a[i] = arr[i];
    }
}
void print_heap(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void add(int a[], int *n, int x)
{
    a[*n] = x;
    *n += 1;
    int l = *n;
    bupheapify(a,l,l-1);
}

void bupheapify(int a[], int n, int i)
{
    while(i>=0)
    {
        if(a[i] < a[(i-1)/2])
        {
            swap(&a[i],&a[(i-1)/2]);
            i = (i-1)/2;
        }
        else
            break;
    }
}

void tdownheapify(int a[], int n, int i)
{
 /*   if((2*i+1 == n-1) && a[i] > a[2*i+1])
    {
        swap(&a[i], &a[2*i+1]);
    }*/
    while(2*i+2<n)
    {
        int l;
        if(a[2*i+1]<=a[2*i+2])
            l = 2*i+1;
        else
            l = 2*i+2;
        if(a[i]>a[l])
        {
            swap(&a[i],&a[l]);
            i = l;
        }
        else
            break;
    }
          if((2*i+1 == n-1) && a[i] > a[2*i+1])
     {
          swap(&a[i], &a[2*i+1]);
      }
}

int delete_min(int a[], int *n)
{
    int r = a[0];
    a[0] = a[--*n];
    tdownheapify(a,*n,0);
    return r;
}

void update_key(int a[], int n, int i,int x)
{
    if(a[i]< x)
    {
        a[i] = x;
        tdownheapify(a,n,i);
    }
    else
    {
        a[i] = x;
        bupheapify(a,n,i);
    }
}
int min(int a[])
{
    return a[0];
}
void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}  

void build_heap(int a[] , int n)
{
    for(int i=(n/2)+1;i>=0;i--)
    {
        tdownheapify(a,n,i);
    }
}
