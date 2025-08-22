/*
* Complete the 'pairs' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
* 1. INTEGER k
* 2. INTEGER_ARRAY arr
*/
int compare(const void *a,const void *b){
 return(*(int *)a-*(int *)b);
}
int pairs(int k, int arr_count, int* arr) {
 int count=0;
 qsort(arr,arr_count,sizeof(int),compare);
 int left=0;
 int right=1;
 while(right<arr_count){
 int diff=arr[right]-arr[left];
 if(diff==k){
 count++;
 left++;
 right++;
 }else if(diff<k){
 right++;
 }else{
 left++;
 }
 }
 return count;
}