#include<stdio.h>
int main(){	
	int arr[3][3] = {{1, 0, 1}, {0, 0, 0}, {0, 1, 0}}, rows = 3, cols = 3, row_arr[rows * cols], col_arr[rows * cols], k = 0;
	printf("Given matrix is...\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++)   
			printf("%d\t", arr[i][j]);
		printf("\n");	
	}
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)   
			if(arr[i][j] == 1)
				row_arr[k++] = i;
	row_arr[k] = -1;
	k = 0;
	for(int j = 0; j < cols; j++)
		for(int i = 0; i < rows; i++)   
			if(arr[i][j] == 1)
				col_arr[k++] = j;	   
	col_arr[k]= -1;
	int row_arr_len;
	for(row_arr_len = 0; row_arr[row_arr_len] != -1; row_arr_len++);	
	int col_arr_len;
	for(col_arr_len = 0; col_arr[col_arr_len] != -1; col_arr_len++);
	printf("Therefore, all the ones should meet at (%d, %d)!\n", row_arr[row_arr_len / 2], col_arr[col_arr_len / 2]); 	   
	return 0;
}
