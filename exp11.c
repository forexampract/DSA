#include <stdio.h>
#define MAX 100

int g[MAX][MAX], vis[MAX], n;

// Create graph
void create() {
    int e,u,v;
    printf("Enter number of cities: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=0;

    printf("Enter number of roads: ");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        printf("Enter origin and destination: ");
        scanf("%d%d",&u,&v);
        g[u][v]=1;
    }
}

// DFS
void DFS(int v){
    printf("%d ",v);
    vis[v]=1;
    for(int i=0;i<n;i++)
        if(g[v][i] && !vis[i])
            DFS(i);
}

// BFS
void BFS(int s){
    int q[MAX],f=0,r=0;
    q[r]=s; vis[s]=1;

    while(f<=r){
        int v=q[f++];
        printf("%d ",v);
        for(int i=0;i<n;i++)
            if(g[v][i] && !vis[i]){
                q[++r]=i;
                vis[i]=1;
            }
    }
}

int main(){
    int ch,start;
    create();

    printf("Enter starting city: ");
    scanf("%d",&start);

    for(int i=0;i<n;i++) vis[i]=0;

    printf("1.DFS  2.BFS\n");
    scanf("%d",&ch);

    if(ch==1){
        printf("DFS traversal:\n");
        DFS(start);
    }
    else if(ch==2){
        printf("BFS traversal:\n");
        BFS(start);
    }
    else
        printf("Invalid choice\n");

    return 0;
}
