/*
* Complete the 'bigSorting' function below.
*
* The function is expected to return a STRING_ARRAY.
* The function accepts STRING_ARRAY unsorted as parameter.
*/
/*
* To return the string array from the function, you should:
* - Store the size of the array to be returned in the result_count
variable
* - Allocate the array statically or dynamically
*
* For example,
* char** return_string_array_using_static_allocation(int* result_count) {
* *result_count = 5;
*
* static char* a[5] = {"static", "allocation", "of", "string", "array"};
*
* return a;
* }
*
* char** return_string_array_using_dynamic_allocation(int* result_count) {
* *result_count = 5;
*
* char** a = malloc(5 * sizeof(char*));
*
* for (int i = 0; i < 5; i++) {
* *(a + i) = malloc(20 * sizeof(char));
* }
*
* *(a + 0) = "dynamic";
* *(a + 1) = "allocation";
* *(a + 2) = "of";
* *(a + 3) = "string";
* *(a + 4) = "array";
*
* return a;
* }
*
*/
int compare_numeric_strings(const void *a,const void *b){
 const char *s1=*(const char**)a;
 const char *s2=*(const char**)b;
 size_t len1=strlen(s1);
 size_t len2=strlen(s2);
 if(len1!=len2){
 return(len1>len2)-(len1<len2);
 }
 return strcmp(s1,s2);
}
char** bigSorting(int unsorted_count, char** unsorted, int* result_count) {
 *result_count=unsorted_count;
 qsort(unsorted,unsorted_count,sizeof(char*),compare_numeric_strings);
 return unsorted;
}
