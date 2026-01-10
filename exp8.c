#include <stdio.h>
#include <stdlib.h>

typedef struct E{
    char ssn[20], name[100], dept[50], desig[50], ph[15];
    double sal;
    struct E *prev,*next;
}E;

E* read(){
    E *n=malloc(sizeof(*n));
    printf("Enter SSN: "); scanf("%s",n->ssn);
    printf("Enter Name: "); scanf("%s",n->name);
    printf("Enter Department: "); scanf("%s",n->dept);
    printf("Enter Designation: "); scanf("%s",n->desig);
    printf("Enter Salary: "); scanf("%lf",&n->sal);
    printf("Enter Phone Number: "); scanf("%s",n->ph);
    n->prev=n->next=NULL;
    return n;
}

E* insertEnd(E* h){
    E *n=read(), *t=h;
    if(!h) return n;
    while(t->next) t=t->next;
    t->next=n; n->prev=t;
    return h;
}

E* insertFront(E* h){
    E *n=read();
    if(h){ n->next=h; h->prev=n; }
    return n;
}

E* deleteEnd(E* h){
    if(!h){ printf("List is already empty!\n"); return NULL; }
    if(!h->next){ free(h); return NULL; }
    E *t=h; while(t->next) t=t->next;
    t->prev->next=NULL; free(t);
    return h;
}

E* deleteFront(E* h){
    if(!h){ printf("List is already empty!\n"); return NULL; }
    E *t=h; h=h->next;
    if(h) h->prev=NULL;
    free(t);
    return h;
}

void display(E* h){
    if(!h){ printf("List is empty!\n"); return; }
    while(h){
        printf("SSN:%s Name:%s Dept:%s Designation:%s Salary:%.2f Phone:%s\n",
               h->ssn,h->name,h->dept,h->desig,h->sal,h->ph);
        h=h->next;
    }
}

int count(E* h){
    int c=0; while(h){ c++; h=h->next; } return c;
}

int main(){
    E *h=NULL; int ch;
    while(1){
        printf("\nMenu:\n");
        printf("1.Insert End\n2.Display\n3.Count\n4.Delete End\n");
        printf("5.Insert Front\n6.Delete Front\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: h=insertEnd(h); break;
            case 2: display(h); break;
            case 3: printf("Total number of employees: %d\n",count(h)); break;
            case 4: h=deleteEnd(h); break;
            case 5: h=insertFront(h); break;
            case 6: h=deleteFront(h); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
