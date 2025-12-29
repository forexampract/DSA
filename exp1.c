#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D 7

typedef struct{ char *n,*a; int d; } Day;

void create(Day *w){
    for(int i=0;i<D;i++)
        if(!(w[i].n=malloc(20))||!(w[i].a=malloc(100))){
            printf("Memory error\n"); exit(1);
        }
}

void read(Day *w){
    char b[20];
    for(int i=0;i<D;i++){
        do{
            printf("Day %d name: ",i+1);
            fgets(w[i].n,20,stdin);
            w[i].n[strcspn(w[i].n,"\n")]=0;
            if(!*w[i].n) puts("Error: Name empty");
        }while(!*w[i].n);

        do{
            printf("Date: "); fgets(b,20,stdin);
            if(sscanf(b,"%d",&w[i].d)!=1||w[i].d<=0)
                puts("Error: Invalid date");
        }while(w[i].d<=0);

        do{
            printf("Activity: ");
            fgets(w[i].a,100,stdin);
            w[i].a[strcspn(w[i].a,"\n")]=0;
            if(!*w[i].a) puts("Error: Activity empty");
        }while(!*w[i].a);
    }
}

void display(Day *w){
    for(int i=0;i<D;i++)
        printf("%s | %d | %s\n",w[i].n,w[i].d,w[i].a);
}

int main(){
    Day *w=malloc(D*sizeof(Day));
    if(!w){ puts("Memory error"); return 1; }
    create(w); read(w); display(w);
    for(int i=0;i<D;i++){ free(w[i].n); free(w[i].a); }
    free(w);
}
