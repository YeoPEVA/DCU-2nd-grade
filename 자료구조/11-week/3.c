#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct {
    int num_vertices;
    GraphNode* adj_list[MAX_VERTICES];
    int indegree[MAX_VERTICES];
} Graph;

typedef struct {
    int stack[MAX_VERTICES];
    int top;
} Stack;

void graph_init(Graph* g) {
    g->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
        g->indegree[i] = 0;
    }
}

void insert_vertex(Graph* g) {
    if (g->num_vertices >= MAX_VERTICES) {
        printf("정점의 개수가 최대를 초과했습니다.\n");
        return;
    }
    g->num_vertices++;
}

void insert_edge(Graph* g, int u, int v) {
    GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
    new_node->vertex = v;
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;
    g->indegree[v]++;
}

void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX_VERTICES - 1) {
        s->stack[++(s->top)] = value;
    }
}

int pop(Stack* s) {
    if (!is_empty(s)) {
        return s->stack[(s->top)--];
    }
    return -1;
}

void top_sort(Graph* g) {
    int result[MAX_VERTICES];
    int result_index = 0;
    Stack s;
    init_stack(&s);

    for (int i = 0; i < g->num_vertices; i++) {
        if (g->indegree[i] == 0) {
            push(&s, i);
        }
    }

    while (!is_empty(&s)) {
        int u = pop(&s);
        result[result_index++] = u;

        for (GraphNode* node = g->adj_list[u]; node != NULL; node = node->next) {
            int v = node->vertex;
            g->indegree[v]--;
            if (g->indegree[v] == 0) {
                push(&s, v);
            }
        }
    }

    for (int i = 0; i < result_index; i++) {
        printf("정점 %d", result[i]);
        printf(" ->");
        //if (i < result_index - 1) {
        //    printf(" ->");
        //}
    }
    printf("\n");
}

int main() {
    Graph g;
    graph_init(&g);

    for (int i = 0; i < 6; i++) {
        insert_vertex(&g);
    }

    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 1, 0);
    insert_edge(&g, 4, 0);
    insert_edge(&g, 4, 2);
    insert_edge(&g, 4, 3);
    insert_edge(&g, 3, 5);

    top_sort(&g);

    return 0;
}
