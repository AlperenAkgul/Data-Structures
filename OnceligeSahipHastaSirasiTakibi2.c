#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct veri{
    char ad[15];
    char soyad[15];
    int oncelik;
    struct node *next;
};
typedef struct veri hasta;

struct node{
    hasta *veri;
    struct node *next;
};
typedef struct node siraEleman;

siraEleman *yeniHasta(char ad[], char soyad[], int oncelik){
    siraEleman *yeniHasta = (siraEleman *)malloc(sizeof(struct node));
    hasta *temp = (hasta *)malloc(sizeof(struct veri));
    strcpy(temp->ad, ad);
    strcpy(temp->soyad, soyad);
    temp->oncelik = oncelik;
    yeniHasta->veri = temp;
    return yeniHasta;
}


siraEleman *ekle(siraEleman *head, siraEleman *yeniHasta){
    if(head == NULL){
        head = yeniHasta;
        head->next = head;
    }
    else if(head->veri->oncelik < yeniHasta->veri->oncelik){
        siraEleman *p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = yeniHasta;
        yeniHasta->next = head;
        head = yeniHasta;
    }
    else{
        siraEleman *p = head;
        while(p->next != head && p->next->veri->oncelik > yeniHasta->veri->oncelik){
            p = p->next;
        }
        if(p != head && p->next->veri->oncelik < yeniHasta->veri->oncelik){
            p = p->next;
        }
        yeniHasta->next = p->next;
        p->next = yeniHasta;
    }
    return head;
}

siraEleman *siradaki(siraEleman *head){
    if(head == NULL)
        return NULL;
    else if(head->next == head){
        siraEleman *temp = head;
        free(head);
        head = NULL;
        return temp;
    }
    else{
        siraEleman *p = head;
        while(p->next != head)
            p = p->next;
        printf("Siradaki Hasta:\nIsim: %s\tSoyisim: %s\t Oncelik: %d\n", head->veri->ad, head->veri->soyad, head->veri->oncelik);
        p->next = head->next;
        p = head;
        head = head->next;
        free(p);
        return head;
    }
}

void bastir(siraEleman *head){
    siraEleman *p = head;
    while(p->next != head){
        printf("Isim: %s\tSoyisim: %s\t Oncelik: %d\n", p->veri->ad, p->veri->soyad, p->veri->oncelik);
        p = p->next;
    }
    printf("Isim: %s\tSoyisim: %s\t Oncelik: %d\n", p->veri->ad, p->veri->soyad, p->veri->oncelik);
}



int main(){
    siraEleman *head = NULL;
    siraEleman *h1 = yeniHasta("ali", "demir", 4);
    siraEleman *h2 = yeniHasta("veli", "yilmaz", 3);
    siraEleman *h3 = yeniHasta("sadi", "seker", 6);
    siraEleman *h4 = yeniHasta("cem", "yildiz", 5);
    siraEleman *h5 = yeniHasta("evren", "seker", 4);

    head = ekle(head, h1);
    head = ekle(head, h2);
    head = ekle(head, h3);
    head = ekle(head, h4);
    head = ekle(head, h5);
    bastir(head);

    head = siradaki(head);
    head = siradaki(head);
    head = siradaki(head);

    return 0;
}