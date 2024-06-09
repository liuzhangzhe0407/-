#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
// ����ͼ���ڽӱ�ڵ�
struct Node {
    int data;
    struct Node* next;
};
// ����ͼ
struct Graph {
    int numNodes;
    struct Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
};
// ��ʼ��ͼ
void initGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}
// ��ӱ�
void addEdge(struct Graph* graph, int src, int dest) {
    // �����ڽӱ�ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}
// ������ȱ���
void DFS(struct Graph* graph, int node) {
    // ��ǵ�ǰ�ڵ�Ϊ�ѷ���
    graph->visited[node] = 1;
    printf("%d ", node);
// ������ǰ�ڵ���ڽӽڵ�
    struct Node* current = graph->adjacencyList[node];
    while (current != NULL) {
        if (!graph->visited[current->data]) {
            // �ݹ����DFS
            DFS(graph, current->data);
        }
        current = current->next;
    }
}
int main() {
    // ����һ��ͼ����ʼ��
    struct Graph graph;
    initGraph(&graph, 6);
    // ���ͼ�ı�
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);
    // ִ��������ȱ���
    printf("Depth-First Traversal: ");
    DFS(&graph, 0);
    return 0;
}
