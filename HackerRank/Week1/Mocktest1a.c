/*
* Complete the 'findMedian' function below.
*
* The function is expected to return an INTEGER.
* The function accepts INTEGER_ARRAY arr as parameter.
*/
int compare_ints(const void* a,const void* b){
 int arg1=*(const*)a;
 int arg2=*(const*)b;
 if(arg1<arg2) return -1;
 if(arg1>arg2) return 1;
 return 0;
}
int findMedian(int arr_count, int* arr) {
 qsort(arr,arr_count,sizeof(int),compare_ints);
 int median_index=arr_count/2;
 return arr[median_index];
}
