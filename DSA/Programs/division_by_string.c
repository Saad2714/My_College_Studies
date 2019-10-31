#include <stdio.h>  
#include <string.h>
#include <stdlib.h> 
char* longDivision(char* number, int divisor) 
{ 
    char *ans=(char*)malloc((sizeof(number))); 
    
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
     
    int p=0; 
    while (strlen(number) > idx) 
    { 
        ans[p++] = (temp / divisor) + '0'; 
          
      
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    ans[p]='\0';
     
    if (strlen(ans) == 0) 
        return "0"; 
      
     
    return ans; 
} 
  
// Driver program to test longDivison() 
int main() 
{ 
    char number[] = "1248163264128256512"; 
    int divisor = 125;     
    printf("%s",longDivision(number, divisor));     
    return 0; 
} 
