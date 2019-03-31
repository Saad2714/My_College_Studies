#include<stdio.h>
int main(){
	int arr[1000000] = {0}, querie;
	arr[0] = 1;
	arr[1] = 1;	
	for(int i = 2; i < 1000000; i++)
		  if(arr[i] == 0)
			for(int j = 2 * i; j < 1000000; j += i)
				arr[j] = 1;
	printf("Enter the number whose primality you wish to know (enter -1 if you're done with your queries) :\n");	
	scanf("%d", &querie);	
	while(querie != -1){
		if(arr[querie] == 0)
			printf("PRIME!\n");
		else	
			printf("NOT PRIME!\n");
		scanf("%d", &querie);
	}
	return 0;
}
