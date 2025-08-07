/*
* Complete the 'flippingMatrix' function below.
* The function is expected to return an INTEGER.
* The function accepts 2D_INTEGER_ARRAY matrix as parameter.
*/
int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
 int sum=0;
 int n=matrix_rows/2;
 for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
 int val1=matrix[i][j];
 int val2=matrix[i][matrix_columns-1-j];
 int val3=matrix[matrix_rows-1-i][j];
 int val4=matrix[matrix_rows-1-i][matrix_columns-1-j];
 int max_val=val1;
 if(val2>max_val){
 max_val=val2;
 }
 if(val3>max_val){
 max_val=val3;
 }
 if(val4>max_val){
 max_val=val4;
 }
 sum+=max_val;
 }
 }
 return sum;
}
