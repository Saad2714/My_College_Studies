#include<stdio.h>
#include<stdlib.h>
int n=0;//n is the current size of heap
void print(int h[])
{
  printf("\n___________________________________________________________\n");
  for(int i=0;i<n;i++)
  printf("%d\t",h[i]);
}
void bot_up(int h[],int i)//[log n]
{
  int p=(i-1)/2,temp;
  while(p>=0)
  {
    if(h[i]<h[p])
    {
    temp=h[i];
    h[i]=h[p];
    h[p]=temp;
    i=p;
    p=(i-1)/2;
    }
    else
    break;
  }
}
void top_down(int h[], int i,int cap)//i is the node from where topdown should start, cap is till where it must go[log n]
{
  int m,temp;
  while(2*i+1<cap)
  {
    if(2*i+1==cap-1)
      m=2*i+1;
    else
    {
      if(h[2*i+1]<h[2*i+2])
      m=2*i+1;
      else
      m=2*i+2;
    }
    if(h[i]>h[m])
    {
      temp=h[i];
      h[i]=h[m];
      h[m]=temp;
      i=m;
    }
    else
    break;
  }
}
void add(int x,int h[])//to add elements at end of haep and call bottom up[log n]
{
  h[n++]=x;
  if(n!=1)
  bot_up(h,n-1);
}
void build_h1(int h[],int k)//the build heap which builds from top down using bttom up on each node[n log n]
{
  int x;
  for(int i=0;i<k;i++)
  {
    scanf("%d",&x);
    add(x,h);

  }
  print(h);
}
void eff_bldh(int h[])//Effective build heap which builds bottom up using top down on all internal nodes[n]
{
  for(int i=(n/2)+1;i>=0;i--)
  {
    top_down(h,i,n);;
  }
}
int delete_min(int h[])//The one in which the size is changing[log n]
{
  int temp=h[0];
  h[0]=h[n-1];
  h[n-1]=temp;
  top_down(h,0,n-1);
  n--;
  return temp;
}
void delete_min1(int h[],int i)//used for Heapsort...doesnt actually change capacity of the array, does deletemin on given capacity
{
  int temp=h[0];
  h[0]=h[i];
  h[i]=temp;
  top_down(h,0,i);
}
void heapsort(int h[])//continuosly puts the min and last element and calls topdown on the heap of size i-1 everytime[n log n]
{
  int i=n-1;
  while(i>=0)
{
  delete_min1(h,i);
  i--;
}
  print(h);
}
void update_key(int h[],int i,int key)//[log n]
{
  if(h[i]>key)
  {
    h[i]=key;
    bot_up(h,i);
  }
  else
  {
    h[i]=key;
    top_down(h,i,n);
  }
  print(h);
}

int main()
{
  int h[100];
  build_h1(h,10);
  printf("n=%d\n___________________________________________________________\n",n);
  heapsort(h);
  eff_bldh(h);
  print(h);
  printf("min=\t%d\n",delete_min(h));
  print(h);
  update_key(h,0,13);
  update_key(h,1,1);
  return 0;
}
