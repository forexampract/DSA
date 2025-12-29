#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D 7

typedef struct{ char *n,*a; int d; } Day;

void create(Day *c){
    for(int i=0;i<D;i++){
        c[i].n=malloc(20); c[i].a=malloc(100);
        if(!c[i].n||!c[i].a){ printf("Memory error\n"); exit(1); }
    }
}

void read(Day *c){
    char b[20];
    for(int i=0;i<D;i++){
        while(1){
            printf("Day %d name: ",i+1);
            fgets(c[i].n,20,stdin); c[i].n[strcspn(c[i].n,"\n")]=0;
            if(*c[i].n) break; printf("Error: Name empty\n");
        }
        while(1){
            printf("Date: "); fgets(b,20,stdin);
            if(sscanf(b,"%d",&c[i].d)==1 && c[i].d>0) break;
            printf("Error: Invalid date\n");
        }
        while(1){
            printf("Activity: ");
            fgets(c[i].a,100,stdin); c[i].a[strcspn(c[i].a,"\n")]=0;
            if(*c[i].a) break; printf("Error: Activity empty\n");
        }
    }
}

void display(Day *c){
    printf("\nWeekly Report:\n");
    for(int i=0;i<D;i++)
        printf("%s | %d | %s\n",c[i].n,c[i].d,c[i].a);
}

int main(){
    Day *c=malloc(D*sizeof(Day));
    if(!c){ printf("Memory error\n"); return 1; }
    create(c); read(c); display(c);
    for(int i=0;i<D;i++){ free(c[i].n); free(c[i].a); }
    free(c); return 0;
}
