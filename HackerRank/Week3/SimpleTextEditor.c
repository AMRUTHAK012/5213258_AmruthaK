#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct{ int type;int k;char *data;} Op;
int main(){
    int Q;
    scanf("%d",&Q);
    size_t cap=1 << 20;
    char *S=(char *)malloc(cap);
    int len =0;
    S[0]='\0';
    Op *stk=(Op*)malloc(Q * sizeof(Op));
    int top=-1;
    char *buf=(char*)malloc(1000005);
    for(int i=0;i<Q;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            scanf("%s",buf);
            int wlen=(int)strlen(buf);
            stk[++top]=(Op){1,wlen,NULL};
            if((size_t)(len+wlen+1)>cap){
                while((size_t)(len+wlen+1)>cap)cap<<=1;
                S=(char*)realloc(S,cap);
                }
                memcpy(S+len,buf,wlen);
                len+=wlen;
                S[len]='\0';
                }else if(t==2){
                    int k;
                    scanf("%d",&k);
                    if(k>len) k=len;
                    char *deleted=(char*)malloc(k+1);
                    memcpy(deleted,S+len-k,k);
                    deleted[k]='\0';
                    stk[++top]=(Op){2,k,deleted};
                    len-=k;
                    S[len]='\0';
                }
                else if(t==3){
                    int k;
                    scanf("%d",&k);
                    if(k>=1 && k<=len){
                        putchar(S[k-1]);
                        putchar('\n');
                    }
                }
                else if(t==4){
                    if(top>=0){
                        Op op=stk[top--];
                        if(op.type==1){
                            len-=op.k;
                            if(len<0) len=0;
                            S[len]='\0';
                        }else{
                            int wlen=op.k;
                            if((size_t)(len+wlen+1)>cap){
                                while((size_t)(len+wlen+1)>cap) cap<<=1;
                                S=(char*)realloc(S,cap);
                            }
                            memcpy(S+len,op.data,wlen);
                            len+=wlen;
                            S[len]='\0';
                            free(op.data);
                        }
                    }
                }
        }
        while(top>=0){
            if(stk[top].type==2)
            free(stk[top].data);
            top--;
        }
        free(stk);
        free(buf);
        free(S);
        return 0;
            }
   
