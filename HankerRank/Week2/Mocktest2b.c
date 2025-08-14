/*
* Complete the 'getTotalX' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
* 1. INTEGER_ARRAY a
* 2. INTEGER_ARRAY b
*/

getTotalX(int a_count, int* a, int b_count, int* b) {
 int count=0;
 int x;
 int max_a=0;
 for(int i=0;i<a_count;i++)
 {
 if(a[i]>max_a){
 max_a=a[i];
 }
 }
 int min_b=101;
 for(int i=0;i<b_count;i++){
 if(b[i]<min_b){
 min_b=b[i];
 }
 }
 for(x=max_a;x<=min_b;x++)
 {
 int isFactorOfAllB=1;
 for(int i=0;i<b_count;i++){
 if(b[i]%x!=0){
 isFactorOfAllB=0;
 break;
 }
 }
 if(isFactorOfAllB){
 int isMultipleOfAllA=1;
 for(int i=0;i<a_count;i++){
 if(x%a[i]!=0){
 isMultipleOfAllA=0;
 break;
 }
 }
 if(isMultipleOfAllA){
 count++;
 }
 }
 }
 return count;
}


