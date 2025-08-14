
/*
* Complete the 'palindromeIndex' function below.
*
* The function is expected to return an INTEGER.
* The function accepts STRING s as parameter.
*/
int isPalindrome(char* str,int start,int end){
 while(start<end){
 if(str[start]!=str[end]){
 return 0;
 }
 start++;
 end--;
 }
 return 1;
}
int palindromeIndex(char* s) {
 int n=strlen(s);
 int start=0;
 int end=n-1;
 while(start<end){
 if(s[start]!=s[end]){
 if(isPalindrome(s, start+1 ,end)){
 return start;
 }
 if(isPalindrome(s,start,end-1)){
 return end;
 }
 }
 start++;
 end--;
 }
 return -1;
}
