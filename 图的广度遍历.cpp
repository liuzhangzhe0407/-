#include <stdio.h>
#include <malloc.h>
#define INFINITY -1
#define VERTEXNUM 10

int visited[VERTEXNUM];

typedef struct {
    char vertex[VERTEXNUM];
    int edge[VERTEXNUM][VERTEXNUM];
    int n,e;
} MGraph;

void BFS(MGraph G, int v) {
    int Q[VERTEXNUM];//队列，存放顶点
    int front=-1,rear=-1,p=-1;
    Q[++rear] = v;
    visited[v] = 1;
    while(front < rear) {
        p = Q[++front];//出队
        printf("%c\t",G.vertex[p]);
        for(int i=0; i<G.n; i++) {//将满足条件的顶点都加入队列中
            if(!visited[i] && G.edge[p][i] !=0 && G.edge[p][i] != INFINITY) {
                Q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}


int main(int argc, char const *argv[]) {
    MGraph G; //初始化
    G.n = 5, G.e = 5;
    G.vertex[0] = 'A';
    G.vertex[1] = 'B';
    G.vertex[2] = 'C';
    G.vertex[3] = 'D';
    G.vertex[4] = 'E';
    G.edge[0][0] = 0;
    G.edge[0][1] = G.edge[1][0] = 5;
    G.edge[0][2] = G.edge[2][0] = 2;
    G.edge[0][3] = G.edge[3][0] = INFINITY;
    G.edge[0][4] = G.edge[4][0] = INFINITY;
    G.edge[1][1] = 0;
    G.edge[1][2] = G.edge[2][1] = INFINITY;
    G.edge[1][3] = G.edge[3][1] = 1;
    G.edge[1][4] = G.edge[4][1] = 4;
    G.edge[2][2] = 0;
    G.edge[2][3] = G.edge[3][2] = INFINITY;
    G.edge[2][4] = G.edge[4][2] = 4;
    G.edge[3][3] = 0;
    G.edge[3][4] = G.edge[4][3] = INFINITY;
    G.edge[4][4] = 0;
    for(int i=0; i<G.n; i++) {
        visited[i] = 0;
    }
    printf("邻接矩阵为：\n");
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            printf("%d\t", G.edge[i][j]);
        }
        printf("\n");
    }
    printf("广度优先遍历为：\n");
    BFS(G,4);
    return 0;
}


