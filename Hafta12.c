#include <stdio.h>
#define QUEUE_SIZE 10

struct priorty_queue{
    int A[QUEUE_SIZE + 1];
    int cnt;
};
typedef struct priorty_queue pqueue;

void initialize(pqueue *p){
    p->cnt = 0;
}

void insert(pqueue *p, int key){
    if(p->cnt == QUEUE_SIZE){
        printf("Queue is Full");
    }
    else{
        p->cnt++;
        p->A[p->cnt] = key;
        int iter = p->cnt;
        while(iter != 1 && p->A[iter] < p->A[iter/2]){
            int temp = p->A[iter];
            p->A[iter] = p->A[iter/2];
            p->A[iter/2] = temp;
            iter /= 2;
        }
    }
}

void print(pqueue *p){
    if(p->cnt == 0){
        printf("Queue is empty");
    }
    else{
        int i;
        for(i = 1; i <= p->cnt; i++){
            printf("%5d", p->A[i]);
        }
        printf("\n");
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int delete(pqueue *p){
    if(p->cnt == 0){
        printf("Queue is Empty");
        return -100;
    }
    else{
        int key = p->A[1];
        p->A[1] = p->A[p->cnt];
        p->cnt--;
        int iter = 1;
        while(2*iter <= p->cnt && (p->A[iter] > p->A[2*iter] || p->A[iter] > p->A[2*iter + 1])){
            if(p->A[2*iter] < p->A[2*iter + 1]){
                swap(&p->A[iter], &p->A[2*iter]);
                iter = 2*iter;
            }
            else{
                swap(&p->A[iter], &p->A[2*iter + 1]);
                iter = 2*iter + 1;
            }
        }
        return key;
    }
}

int main(){
    pqueue p;
    initialize(&p);
    insert(&p, 5);
    insert(&p, 10);
    insert(&p, 11);
    insert(&p, 1);
    insert(&p, 5);
    insert(&p, 3);
    insert(&p, 12);
    print(&p);
    //printf("%d\n", delete(&p));
    delete(&p);
     print(&p);
    //printf("%d\n", delete(&p));
     delete(&p);
     print(&p);
     //printf("%d\n", delete(&p));
     delete(&p);
     print(&p);
     //printf("%d\n", delete(&p));
     delete(&p);
     print(&p);
     //printf("%d\n", delete(&p));
     delete(&p);
     print(&p);
     //printf("%d\n", delete(&p));
    //printf("%d\n", delete(&p));
     delete(&p);
     print(&p);
     //printf("%d\n", delete(&p));
    delete(&p);
    print(&p);
}  