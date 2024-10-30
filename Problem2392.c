/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.
*/

#define MAX_K 400

struct node {
    int val;
    struct node* next;
};

struct graph {
    struct node* head[MAX_K + 1];
    int inDegree[MAX_K + 1];
};

void addEdge(struct graph* graph, int from, int to) {
    struct node* new = malloc(sizeof(struct node));
    new->val = to;
    new->next = graph->head[from];
    graph->head[from] = new;
    graph->inDegree[to]++;
}

bool topologicalSort(int k, struct graph* graph, int* order) {
    int queue[MAX_K + 1];
    int front = 0, rear = 0;
    int orderIdx = 0;
    
    for(int i = 1; i <= k; i++) {
        if(graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    } 
    while(front < rear) {
        int node = queue[front++];
        order[orderIdx++] = node;
        
        struct node* current = graph->head[node];
        while (current) {
            graph->inDegree[current->val]--;
            if (graph->inDegree[current->val] == 0) {
                queue[rear++] = current->val;
            }
            current = current->next;
        }
    }
    
    return orderIdx == k;
}

int** buildMatrix(int k, int** rowConditions, int rowConditionsSize, int* rowConditionsColSize, int** colConditions, int colConditionsSize, int* colConditionsColSize, int* returnSize, int** returnColumnSizes) {
    struct graph rowGraph = {.head = {NULL}, .inDegree = {0}};
    struct graph colGraph = {.head = {NULL}, .inDegree = {0}};
    int rowOrder[MAX_K + 1];
    int colOrder[MAX_K + 1];
    
    for(int i = 0; i < rowConditionsSize; i++) {
        addEdge(&rowGraph, rowConditions[i][0], rowConditions[i][1]);
    }
    
    for(int i = 0; i < colConditionsSize; i++) {
        addEdge(&colGraph, colConditions[i][0], colConditions[i][1]);
    }   
    if(!topologicalSort(k, &rowGraph, rowOrder) || !topologicalSort(k, &colGraph, colOrder)) {
        *returnSize = 0;
        return rowConditions;
    }

    int** ret = malloc(k * sizeof(int*));
    *returnColumnSizes = malloc(k * sizeof(int));
    *returnSize = k;

    for(int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = k;
        ret[i] = calloc(k, sizeof(int));
    }
    
    int rowPos[MAX_K + 1];
    int colPos[MAX_K + 1];
    
    for (int i = 0; i < k; i++) {
        rowPos[rowOrder[i]] = colPos[colOrder[i]] = i;
    }
    for (int num = 1; num <= k; num++) {
        ret[rowPos[num]][colPos[num]] = num;
    }
    
    return ret;
}

int main()
{

    return 0;
}