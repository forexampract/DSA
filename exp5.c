#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int evalPostfix(char *e){
    int s[MAX], t=-1;
    for(int i=0;e[i];i++){
        if(isdigit(e[i])) s[++t]=e[i]-'0';
        else{
            int b=s[t--], a=s[t--];
            switch(e[i]){
                case '+': s[++t]=a+b; break;
                case '-': s[++t]=a-b; break;
                case '*': s[++t]=a*b; break;
                case '/': s[++t]=a/b; break;
                case '%': s[++t]=a%b; break;
                case '^': s[++t]=(int)pow(a,b); break;
            }
        }
    }
    return s[t];
}

void hanoi(int n,char f,char t,char a){
    if(n==1){
        printf("Move disk 1 from rod %c to rod %c\n",f,t);
        return;
    }
    hanoi(n-1,f,a,t);
    printf("Move disk %d from rod %c to rod %c\n",n,f,t);
    hanoi(n-1,a,t,f);
}

int main(){
    int ch,n;
    char exp[MAX];

    while(1){
        printf("\n--- Menu ---\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Solve Tower of Hanoi\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s",exp);
                printf("Postfix Evaluation: %s = %d\n",exp,evalPostfix(exp));
                break;
            case 2:
                printf("Enter the number of disks: ");
                scanf("%d",&n);
                printf("The sequence of moves involved in the Tower of Hanoi are:\n");
                hanoi(n,'A','C','B');
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
