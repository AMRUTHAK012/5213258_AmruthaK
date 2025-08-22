#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX_SIZE 100000
int s1[MAX_SIZE];
int s2[MAX_SIZE];
int top1=-1;
int top2=-1;
void push1(int val){
    s1[++top1]=val;
}
int pop1(){
    return s1[top1--];
}
int top1_val(){
    return s1[top1];
}
void push2(int val){
    s2[++top2]=val;
}
int pop2(){
    return s2[top2--];
}
int top2_val(){
    return s2[top2];
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            push1(x);
        } else if (type == 2) {
            if (top2 == -1) {
                while (top1 != -1) {
                    push2(pop1());
                }
            }
            if (top2 != -1) {
                pop2();
            }
        } else if (type == 3) {
            if (top2 == -1) {
                while (top1 != -1) {
                    push2(pop1());
                }
            }
            if (top2 != -1) {
                printf("%d\n", top2_val());
            }
        }
    }
    return 0;
}
