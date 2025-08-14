/*
* Complete the 'anagram' function below.
*
* The function is expected to return an INTEGER.
* The function accepts STRING s as parameter.
*/


int anagram(char* s) {
 int n=strlen(s);
 if(n%2!=0){
 return -1;
 }
 int half_len=n/2;
 char s1[half_len+1];
 char s2[half_len+1];
 strncpy(s1,s,half_len);
 s1[half_len]='\0';
 strncpy(s2,s+half_len,half_len);
 s2[half_len]='\0';
 int freq1[26]={0};
 int freq2[26]={0};
 for(int i=0;i<half_len;i++){
 freq1[s1[i]-'a']++;
 }
 for(int i=0;i<half_len;i++){
 freq2[s2[i]-'a']++;
 }
int changes=0;
 for(int i=0;i<26;i++){
 if(freq1[i]>freq2[i]){
 changes+=freq1[i]-freq2[i];
 }
 }
 return changes;
}

