#include <stdio.h>
#include <stdbool.h>

#define MAX 10

char q[MAX];
int f = -1, r = -1;

bool isFull(){ return (r + 1) % MAX == f; }
bool isEmpty(){ return f == -1; }

void enqueue(char x){
    if(isFull()){ printf("Queue Overflow\n"); return; }
    if(f == -1) f = 0;
    r = (r + 1) % MAX;
    q[r] = x;
    printf("Inserted '%c'\n", x);
}

void dequeue(){
    if(isEmpty()){ printf("Queue Underflow\n"); return; }
    printf("Deleted '%c'\n", q[f]);
    if(f == r) f = r = -1;
    else f = (f + 1) % MAX;
}

void display(){
    if(isEmpty()){ printf("Queue is empty\n"); return; }
    printf("Queue elements: ");
    for(int i = f; i != r; i = (i + 1) % MAX)
        printf("%c ", q[i]);
    printf("%c\n", q[r]);
}

int main(){
    int ch; char x;
    while(1){
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter a character to insert: ");
                    scanf(" %c",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
