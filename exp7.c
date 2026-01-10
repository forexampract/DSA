#include <stdio.h>
#include <stdlib.h>

typedef struct S{
    char usn[15], name[50], prog[50], ph[15];
    int sem;
    struct S *next;
}S;

S* read(){
    S *n=malloc(sizeof(*n));
    printf("Enter USN: "); scanf("%s",n->usn);
    printf("Enter Name: "); scanf("%s",n->name);
    printf("Enter Programme: "); scanf("%s",n->prog);
    printf("Enter Semester: "); scanf("%d",&n->sem);
    printf("Enter Phone Number: "); scanf("%s",n->ph);
    n->next=NULL; return n;
}

void insertFront(S **h){
    S *n=read(); n->next=*h; *h=n;
    printf("Student added at front.\n");
}

void insertEnd(S **h){
    S *n=read(), *t=*h;
    if(!*h) *h=n;
    else{ while(t->next) t=t->next; t->next=n; }
    printf("Student added at end.\n");
}

void deleteFront(S **h){
    if(!*h){ printf("List is empty, nothing to delete.\n"); return; }
    S *t=*h; *h=t->next; free(t);
    printf("Student deleted from front.\n");
}

void deleteEnd(S **h){
    if(!*h){ printf("List is empty, nothing to delete.\n"); return; }
    if(!(*h)->next){ free(*h); *h=NULL; }
    else{
        S *t=*h;
        while(t->next->next) t=t->next;
        free(t->next); t->next=NULL;
    }
    printf("Student deleted from end.\n");
}

void display(S *h){
    int c=0;
    printf("\nStudent List:\n");
    while(h){
        printf("USN:%s Name:%s Prog:%s Sem:%d Phone:%s\n",
               h->usn,h->name,h->prog,h->sem,h->ph);
        h=h->next; c++;
    }
    printf("Total Students: %d\n",c);
}

int main(){
    S *h=NULL,*t; int ch;
    while(1){
        printf("\n1.Insert Front 2.Display\n3.Insert End 4.Delete Front\n5.Delete End 6.Exit\n");
        printf("Enter your choice: "); scanf("%d",&ch);

        if(ch==1) insertFront(&h);
        else if(ch==2) display(h);
        else if(ch==3) insertEnd(&h);
        else if(ch==4) deleteFront(&h);
        else if(ch==5) deleteEnd(&h);
        else if(ch==6){
            printf("Exiting...\n");
            while(h){ t=h; h=h->next; free(t); }
            return 0;
        }
        else printf("Invalid choice. Please try again.\n");
    }
}
