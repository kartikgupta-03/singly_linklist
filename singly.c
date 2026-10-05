#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = 0 ;
struct node *createnode(){
    struct node *h;
    h = (struct node*)malloc(sizeof(struct node));
    printf("Enter data : \n");
    scanf("%d", &h->data);
    h->next = 0;
    return h;

}
void insertstart(){
    struct node *k1;
    k1 = createnode();
    if(start == 0){
        start = k1;
    }
    else{
        k1->next = start;
        start = k1;

    }
}
void insertend(){
    struct node *k , *g;
    k = createnode();
    if(start == 0 ){
        start = k;
    }
    else{
        g = start ;
        while(g->next != 0){
            g = g ->next;

        }
        g->next = k;
    }
}
void deletestart(){
    struct node *a ; 
    if(start == 0){
        printf("There is no element to delete");
    }
    else{
        a = start;
        start = start->next;
        a->next = 0;
        free(a);
    }
}
void deleteend(){
    struct node *j, *k ;
    if(start ==0 ){
        printf("There is no element to delete");
    }
    else{
        j = start;
        while(j->next->next!=0){
            j = j->next;
        }
        k = j->next;
        j->next = 0;
        free(k);
    }   
}
void insertmiddle(){
    struct node *k , *g , *h;
    k = createnode();
    if(start == 0){
        start = k;
    }
    else{
        int d ;
        printf("Enter a Data Where you want to insert : ");
        scanf("%d", &d);
        g = start;
        while(g->next->data != d){
            g = g->next;
        }
        h = g->next;
        g->next = k;
        k->next = h;
    }

}void deletemiddle()
{
    struct node *a, *c;
    int d;

    if(start == NULL) {
        printf("No element to delete");
        return;
    }

    printf("Enter element that you want to delete: ");
    scanf("%d", &d);

    // If the first node is the target
    if(start->data == d) {
        a = start;
        start = start->next;
        free(a);
        return;
    }
    a = start;

    while(a->next != NULL && a->next->data != d) {
        a = a->next;
    }

    if(a->next == NULL) {
        printf("Element not found");
        return;
    }

    c = a->next;
    a->next = c->next;
    free(c);
}
void display(){
    struct node *j;
    j = start;
    while(j!=0){
        printf("%d ", j->data);
        j = j->next;
    
    }
}
int main(){
    int n ; 
    printf("\n1. Insertion from start");
    printf("\n2. Deletion from start");
    printf("\n3. Insertion from end");
    printf("\n4. Delete from end");
    printf("\n5. Insertion from middle");
    printf("\n6. Deletion from middle");
    printf("\n7. Display");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d", &n);

        switch(n){
            case 1 : insertstart();
                    break;
            case 2 : deletestart();
                    break;
            case 3 : insertend();
                    break;
            case 4 : deleteend();
                    break;
            case 5 : insertmiddle();
                    break;
            case 6 : deletemiddle();
                    break;
            case 7 : display();
                    break;
            default : printf("Wrong input");

        }
    }
    return 0 ;
}