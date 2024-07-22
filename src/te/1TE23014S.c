#include <stdio.h>
int first=0;
int top=0;
struct cell{
    int data;
    int next;
    int prev;
} celldata[1000];
void ins(int n, int x){
    int newdata;
    newdata=top;
    top++;
    celldata[newdata].data=x;
    celldata[newdata].next=celldata[n].next;
    int next = celldata[newdata].next;
    if(next != -1)
    {
        celldata[next].prev = newdata;
    }

    celldata[n].next=newdata;
}

void del(int n){
    int nn=celldata[n].next;
    int nnn=celldata[nn].next;
    celldata[n].next=nnn;
}

void printall(){
    int now=first;
    while(now!=-1){
        printf("%d ",celldata[now].data);
        now=celldata[now].next;
    }
    printf("\n");
}
void printall_rev(){
    int last=1;
    while(last!=-1){
        printf("%d ",celldata[last].data);
        last=celldata[last].prev;
    }
    printf("\n");
}

void print_last(){
    int now=first;
    while(celldata[now].next!=-1){
        now=celldata[now].next;
    }
    printf("%d \n", celldata[now].data);
}
void list_init(){
    first=0;
    top=1;
    celldata[first].next=-1;
    celldata[first].prev=-1;
    celldata[first].data=999;
}
int main(){
    list_init();
    int i, j, k;
    for(;;){
        scanf("%d",&j);
        if(j>0){
            ins(0,j);
        } else if(j==0) {
            printall();
        } else if(j==-1){
            printall_rev(top);
        } else if(j==-2){
            print_last();
        }
    }
    return 0;
}