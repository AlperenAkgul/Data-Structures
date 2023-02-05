#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char ad[15];
    char soyad[15];
    int oncelik;
    struct node *next;
};
typedef struct node hasta;

hasta *ekle(hasta *head, char isim[], char soyisim[], int sira){
    hasta *temp = (hasta *)malloc(sizeof(struct node));
    strcpy(temp->ad, isim);
    strcpy(temp->soyad, soyisim);
    temp->oncelik = sira;

    if(head == NULL){
        head = temp;
        head->next = head;
    }
    else if(head->oncelik < temp->oncelik){
        hasta *p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
        head = temp;
    }
    else{
        hasta *p = head;
        while(p->next != head && p->next->oncelik > temp->oncelik){
            p = p->next;
        }
        if(p != head && p->next->oncelik < temp->oncelik){
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

hasta *siradaki(hasta *head){
    if(head == NULL)
        return NULL;
    else if(head->next == head){
        hasta *temp = head;
        free(head);
        head = NULL;
        return temp;
    }
    else{
        hasta *p = head;
        while(p->next != head)
            p = p->next;
        printf("Isim: %s\tSoyisim: %s\t Oncelik: %d\n", head->ad, head->soyad, head->oncelik);
        p->next = head->next;
        p = head;
        head = head->next;
        free(p);
        return head;
    }
}

void bastir(hasta *head){
    hasta *p = head;
    while(p->next != head){
        printf("Isim: %s\tSoyisim: %s\t Oncelik: %d\n", p->ad, p->soyad, p->oncelik);
        p = p->next;
    }
    printf("Isim: %s\tSoyisim: %s\t Oncelik: %d\n", p->ad, p->soyad, p->oncelik);
}



int main(){
    hasta *head = NULL;
    hasta *sirada;
    head = ekle(head, "ali", "demir", 4);
    head = ekle(head, "veli", "yilmaz", 3);
    head = ekle(head, "sadi", "seker", 6);
    head = ekle(head, "cem", "yildiz", 5);
    head = ekle(head, "evren", "seker", 4);
    bastir(head);
    printf("\n");
    head = siradaki(head);
    head = siradaki(head);
    head = siradaki(head);
    return 0;
}