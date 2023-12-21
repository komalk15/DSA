/* Name: Komal Karki
     Section: B2	
     Roll No: 35
     Student Id: 22012399


Q9. Write a C program to implement linked representation of a graph in memory using array of pointers.*/

//PROGRAM CODE:-

#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int vertex;
    int weight;
    struct node *next;
} graph;

void display_graph(int n, graph *arr[n])
{
    graph *it;
    for (int i = 0; i < n; i++)
    {
        it = arr[i];
        while (it)
        {
            printf("%d---->%d (%d)\n", i, it->vertex, it->weight);
            it = it->next;
        }
    }
}

void create_graph(int n, graph *arr[n])
{
    graph *it;
    for (int i = 0; i < n; i++)
    {
        it = arr[i];
        while (1)
        {
            int edge, weight;
            printf("Enter the %d vertex edge vertex and weight else enter -1\n", i);
            scanf("%d", &edge);
            if (edge == -1)
            {
                if (it)
                    it->next = NULL;
                break;
            }
            else
            {
                scanf("%d", &weight);
                graph *new_vertex = (graph *)malloc(sizeof(graph));
                if(new_vertex==NULL)
                {
                    printf("Memory can not be allocated\n");
                    return;
                }
                new_vertex->vertex = edge;
                new_vertex->weight = weight;
                new_vertex->next = NULL;
                if (arr[i] == NULL)
                    arr[i] = new_vertex;
                else
                    it->next = new_vertex;
                it = new_vertex;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    graph *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
    }
    create_graph(n,arr);
    display_graph(n, arr);
}









 
Q10.Write a C program to implement DFS.*/

//PROGRAM CODE:-

#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int vertex;
    int weight;
    struct node *next;
} graph;

void display_graph(int n, graph *adj_list[n])
{
    graph *it;
    for (int i = 0; i < n; i++)
    {
        it = adj_list[i];
        while (it)
        {
            printf("%d---->%d (%d)\n", i, it->vertex, it->weight);
            it = it->next;
        }
    }
}

void create_graph(int n,graph *adj_list[n])
{
    graph *it;
    for (int i = 0; i < n; i++)
    {
        it = adj_list[i];
        while (1)
        {
            int edge, weight;
            printf("Enter the %d vertex edge vertex and weight else enter -1\n", i);
            scanf("%d", &edge);
            if (edge == -1)
            {
                if (it)
                    it->next = NULL;
                break;
            }
            else
            {
                scanf("%d", &weight);
                graph *new_vertex = (graph *)malloc(sizeof(graph));
                if(new_vertex==NULL)
                {
                    printf("Memory can not be allocated\n");
                    return;
                }
                new_vertex->vertex = edge;
                new_vertex->weight = weight;
                new_vertex->next = NULL;
                if (adj_list[i] == NULL)
                    adj_list[i] = new_vertex;
                else
                    it->next = new_vertex;
                it = new_vertex;}}}}

void DFS(int visited[], graph *adj_list[],  int node){
    visited[node] = 1;
    printf("%d ", node);
    graph *temp=  adj_list[node];
    while(temp != NULL)
    {
        if( !visited[temp -> vertex] )
            DFS(visited,adj_list,temp->vertex);
        temp = temp -> next;
    }
}
int main(){

    int n;

    printf("Enter the number of nodes: \n");
    scanf("%d", &n);

    graph *adj_list[n];

    for (int i = 0; i < n; i++)
    {
        adj_list[i] = NULL;
    }

    create_graph(n,adj_list);

    display_graph(n, adj_list);

    int visited[n];
    for(int i = 0 ; i < n ; i++)
        visited[i] = 0 ;

    printf("DFS\n");

    for(int i = 0 ; i < n ; i++){
        if(!visited[i] )
            DFS(visited,adj_list,i);
    }
    return 0;
}
 
OUTPUT:-
/* Name: Komal Karki
     Section: B2	
     Roll No: 35
     Student Id: 22012399


Q11.Write a C program to implement Kurskal’s Algorithm.*/

//PROGRAM CODE:

#include <stdio.h>
#include <malloc.h>

typedef struct n
{
    int vertex;
    int weight;
    struct n *next;
} Node;

typedef struct m
{
    int node, node_neigh, w;
    struct m *next;
} linkNode;

void insert(linkNode **head, Node *Adj[], int n)
{
    Node *temp1 = NULL;
    for (int i = 0; i < n; i++)
    {
        temp1 = Adj[i];
        while (temp1 != NULL)
        {
            linkNode *new_node = (linkNode *)malloc(sizeof(linkNode));
            new_node->node = i;
            new_node->node_neigh = temp1->vertex;
            new_node->w = temp1->weight;
            new_node->next = NULL;
            if ((*head) == NULL)
            {
                (*head) = new_node;
            }

            else
            {
                linkNode *prev = NULL;
                linkNode *curr = (*head);
                while (curr && curr->w < new_node->w)
                {
                    prev = curr;
                    curr = curr->next;
                }
                if (prev == NULL)
                {
                    new_node->next = (*head);
                    (*head) = new_node;
                }
                else
                {
                    new_node->next = curr;
                    prev->next = new_node;
                }
            }
            temp1 = temp1->next;
        }
    }
}

void createGraph(Node *Adj[], int n)
{
    Node *new_node, *last;
    int neighbours;
    int val;
    int weight;
    for (int i = 0; i < n; i++)
    {
        last = NULL;
        printf("Enter the total no of neighbours of %d: ", i);
        scanf("%d", &neighbours);
        for (int j = 1; j <= neighbours; j++)
        {
            printf("Enter the neigbour %d of %d: ", j, i);
            scanf("%d", &val);
            printf("Enter the weight: ");
            scanf("%d", &weight);
            new_node = (Node *)malloc(sizeof(Node));
            if (new_node == NULL)
            {
                printf("\nNot enough memory\n");
                return;
            }
            new_node->vertex = val;
            new_node->weight = weight;
            new_node->next = NULL;
            if (Adj[i] == NULL)
            {
                Adj[i] = new_node;
            }
            else
            {
                last->next = new_node;
            }
            last = new_node;
        }
    }
}

int find_parent(int parent[], int a)
{
    return (parent[a]);
}

void applyUnion(int parent[], int a, int b, int n)
{
    for (int i = 0; i < n; i++)
        if (parent[i] == b)
            parent[i] = a;
}

int Kruskal(int parent[], linkNode *head, linkNode **result, int n)
{
    linkNode *temp = head;
    linkNode *h = NULL;
    linkNode *tail = (*result);
    while (temp)
    {
        int n1, n2;
        n1 = find_parent(parent, temp->node);
        n2 = find_parent(parent, temp->node_neigh);
        if (n1 != n2)
        {
            h = (linkNode *)malloc(sizeof(linkNode));
            h->node = temp->node;
            h->node_neigh = temp->node_neigh;
            h->w = temp->w;
            h->next = NULL;
            if (*result == NULL)
            {
               (*result)= tail = h;
            }
            else
            {
                tail->next = h;
                tail = h;
            }
            applyUnion(parent, n1, n2, n);
        }
        temp = temp->next;
    }
}

void print_Result(linkNode *head)
{
    while (head)
    {
        printf("parent(%d)->child(%d)  (%d)\n", head->node, head->node_neigh, head->w);
        head = head->next;
    }
}

int main()
{
    int n;
    printf("Enter the no of nodes in the graph: \n");
    scanf("%d", &n);
    Node *Adj[n];
    for (int i = 0; i < n; i++)
        Adj[i] = NULL;
    createGraph(Adj, n);
    linkNode *head = NULL;
    insert(&head, Adj, n);
    int parent[n];
    linkNode *result = NULL;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    Kruskal(parent, head, &result, n);
    printf("\nMinimum Spanning Tree\n");
    print_Result(result);

    return 0;
}
 
OUTPUT:-

Enter the no of nodes in the graph: 
5
Enter the total no of neighbours of 0: 3 
Enter the neigbour 1 of 0: 1 
Enter the weight: 10
Enter the neigbour 2 of 0: 2
Enter the weight: 60
Enter the neigbour 3 of 0: 4
Enter the weight: 5
Enter the total no of neighbours of 1: 2
Enter the neigbour 1 of 1: 2
Enter the weight: 40
Enter the neigbour 2 of 1: 3
Enter the weight: 14
Enter the total no of neighbours of 2: 0
Enter the total no of neighbours of 3: 3
Enter the neigbour 1 of 3: 0
Enter the weight: 4
Enter the neigbour 2 of 3: 4
Enter the weight: 10
Enter the neigbour 3 of 3: 2
Enter the weight: 10
Enter the total no of neighbours of 4: 1
Enter the neigbour 1 of 4: 2
Enter the weight: 45

Minimum Spanning Tree
parent(3)->child(0)  (4)
parent(0)->child(4)  (5)
parent(3)->child(2)  (10)
parent(0)->chil
