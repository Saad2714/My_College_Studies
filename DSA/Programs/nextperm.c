#include<stdio.h>
#include<string.h>
int main(){
	int found;
	char str[1000000];
	printf("...enter the permutation whose next permutation you want to find (enter -1 when you're done with your queries) :\n");
	scanf("%s", str);
	while(strcmp(str, "-1") != 0){
		int n = strlen(str);
		for(int i = n - 1; i > 0; i--){
			found = 0;
			if(str[i] > str[i - 1])
				for(int j = n - 1; j > i - 1; j--)
					if(str[j] > str[i - 1]){
						int temp = str[j];
						str[j] = str[i - 1];
						str[i - 1] = temp;			
						printf("...the next permutation is : ");			
						for(int k = 0; k < i; k++)
							printf("%c", str[k]);
						for(int k = n - 1; k > i - 1; k--)
							printf("%c", str[k]);					
						printf("\n");
						found = 1;
						break;
					}
			if(found == 1)
				break;
		}
		if(found == 0)
			printf("...this is the last permutation!\n");			
		scanf("%s", str);
	}
}
