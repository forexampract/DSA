#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int d;
    struct node *l,*r;
}N;

N* newN(int d){
    N* t=malloc(sizeof(N));
    t->d=d; t->l=t->r=NULL;
    return t;
}

N* insert(N* r,int d){
    if(!r) return newN(d);
    if(d<r->d) r->l=insert(r->l,d);
    else if(d>r->d) r->r=insert(r->r,d);
    return r;
}

void inorder(N* r){
    if(r){ inorder(r->l); printf("%d ",r->d); inorder(r->r); }
}
void preorder(N* r){
    if(r){ printf("%d ",r->d); preorder(r->l); preorder(r->r); }
}
void postorder(N* r){
    if(r){ postorder(r->l); postorder(r->r); printf("%d ",r->d); }
}

N* search(N* r,int k){
    if(!r||r->d==k) return r;
    return k<r->d ? search(r->l,k) : search(r->r,k);
}

int main(){
    N *root=NULL;
    int ch,k,a[]={6,9,5,2,8,15,24,14,7},n=9;
    for(int i=0;i<n;i++) root=insert(root,a[i]);

    do{
        printf("\n1.Inorder 2.Preorder 3.Postorder 4.Search 5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: inorder(root); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4:
                printf("Enter key: "); scanf("%d",&k);
                printf(search(root,k)?"Found\n":"Not Found\n");
        }
    }while(ch!=5);
}
