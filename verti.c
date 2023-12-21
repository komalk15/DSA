Q1...............
#include <stdio.h>
#include <stdlib.h>

    typedef struct node
{
    struct node *next;
    char Product_Id;
    char Product_Name[20];
    int Total_Sale;
    char Product_Grade;
} node;

typedef struct queue
{
    node *front;
    node *rear;
} queue;

void display(queue *q)
{
    if (!q->front)
    {
        printf("Queue is empty\n");
        return;
    }
    node *it = q->front;
    while (it)
    {
        printf("Product_Name: %s\n", it->Product_Name);
        printf("Product_Id: %c\n", it->Product_Id);
        printf("Product_Grade: %c\n", it->Product_Grade);
        printf("Total_Sales: %d\n", it->Total_Sale);
        printf("\n\n");
        it = it->next;
    }
}

void push(queue *q)
{
    node *newN = (node *)malloc(sizeof(node));
    if (!newN)
    {
        printf("Overflow\n");
        return;
    }
    newN->next = NULL;
    printf("Enter product name: ");
    scanf("%s", newN->Product_Name);
    printf("Enter product grade: ");
    scanf(" %c", &newN->Product_Grade);
    printf("Enter product id: ");
    scanf(" %c", &newN->Product_Id);
    printf("Enter total sales: ");
    scanf("%d", &newN->Total_Sale);

    if (!q->rear)
    {
        q->front = q->rear = newN;
        return;
    }

    q->rear->next = newN;
    q->rear = q->rear->next;
}

queue *create()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void pop(queue *q)
{
    if (q->front == NULL)
    {
        printf("Underflow\n");
        return;
    }
    if (q->front == q->rear)
    {
        free(q->front);
        q->front = q->rear = NULL;
        return;
    }
    node *dump = q->front;
    q->front = q->front->next;
    free(dump);
}

int main()
{
    printf("      MAIN MENU          \n");
    char n = '1';
    queue *q = create();
    while (n != '0')
    {
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to view\nEnter 0 to exit\n");

        scanf(" %c", &n);

        switch (n)
        {
        case '1':
            push(q);
            printf("\n\n");
            break;

        case '2':
            pop(q);
            printf("\n\n");
            break;

        case '3':
            display(q);
            break;

        case '0':
            break;

        default:
            printf("Input error!!\n\n");
            break;
        }
    }

    free(q);
    return 0;
}
Q2.......................
#include <stdio.h>
#include <stdlib.h>

    struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *createListS(struct Node *A, struct Node *B)
{
    struct Node *S = NULL;
    struct Node *tempA = A;
    struct Node *tempB = B;

    while (tempA != NULL || tempB != NULL)
    {
        if (tempA != NULL)
        {
            insertAtEnd(&S, tempA->data);
            tempA = tempA->next;
        }

        if (tempB != NULL)
        {
            insertAtEnd(&S, tempB->data);
            tempB = tempB->next;
        }
    }

    return S;
}
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *listA = NULL;
    struct Node *listB = NULL;
    struct Node *listS = NULL;

    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Element into List A\n");
        printf("2. Insert Element into List B\n");
        printf("3. Create List S\n");
        printf("4. Display List A\n");
        printf("5. Display List B\n");
        printf("6. Display List S\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert into List A: ");
            scanf("%d", &value);
            insertAtEnd(&listA, value);
            break;

        case 2:
            printf("Enter the value to insert into List B: ");
            scanf("%d", &value);
            insertAtEnd(&listB, value);
            break;

        case 3:
            listS = createListS(listA, listB);
            printf("List S created successfully.\n");
            break;

        case 4:
            printf("List A: ");
            displayList(listA);
            break;

        case 5:
            printf("List B: ");
            displayList(listB);
            break;

        case 6:
            printf("List S: ");
            displayList(listS);
            break;

        case 7:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);

    struct Node *temp;
    while (listA != NULL)
    {
        temp = listA;
        listA = listA->next;
        free(temp);
    }

    while (listB != NULL)
    {
        temp = listB;
        listB = listB->next;
        free(temp);
    }

    while (listS != NULL)
    {
        temp = listS;
        listS = listS->next;
        free(temp);
    }

    return 0;
}

Q3................
#include <stdio.h>
#include <stdlib.h>

    struct node
{
    int data;
    struct node *next;
};

struct node *createNode(struct node *head, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory cannt allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->next = 0;
    return newnode;
}

struct node *impleList(struct node *head, int data)
{
    struct node *newnode, *temp;
    newnode = createNode(head, data);
    temp = head;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf(" -> ");
        }
        printf("%d", temp->data);
    }
}
struct node *partitionList(struct node *head, int V)
{
    struct node *temp = head, *lessList = 0, *largeList = 0, *prev;
    while (temp != 0)
    {
        if (temp->data <= V)
        {
            lessList = impleList(lessList, temp->data);
        }
        else
            largeList = impleList(largeList, temp->data);
        temp = temp->next;
    }
    prev = lessList;
    while (prev->next != 0)
    {
        prev = prev->next;
    }
    prev->next = largeList;
    return lessList;
}

int main()
{
    struct node *head = 0;
    int n, data, V, i = 1, count = 0;
    printf("Enter the total no of elements you want to insert :\n");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("Enter %d element -> ", i);
        scanf("%d", &data);
        head = impleList(head, data);
        i++;
        count++;
    }
    printf("\nTotal elements: %d\n", count);
    printf("\nElements in the list are : ");
    display(head);

    printf("\n\nEnter the value V for partitioning: ");
    scanf("%d", &V);
    printf("\nPartitioned Linked List : ");
    head = partitionList(head, V);
    display(head);
    return 0;
}

Q4......................
#include <stdio.h>
#include <stdlib.h>

    struct node
{
    int data;
    struct node *next;
};

struct node *createNode(struct node *head, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory cannt allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->next = 0;
    return newnode;
}

struct node *impleList(struct node *head, int data)
{
    struct node *newnode, *temp;
    newnode = createNode(head, data);
    temp = head;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
struct node *rev(struct node *head)
{
    struct node *temp, *prev, *nextnode;
    temp = nextnode = head;
    prev = 0;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    head = prev;
    return head;
}
void display(struct node *head)
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf(" -> ");
        }
        printf("%d", temp->data);
    }
}
struct node *subtractList(struct node *head, struct node *top)
{
    struct node *temp, *prev, *newList = 0;
    temp = head;
    prev = top;
    int a, b, c;
    while (temp != 0 && prev != 0)
    {
        if (temp->data < prev->data)
        {
            b = temp->data + 10;
            c = b - prev->data;
            temp->next->data = temp->next->data - 1;
        }
        else
            c = temp->data - prev->data;
        newList = impleList(newList, c);
        temp = temp->next;
        prev = prev->next;
    }
    return newList;
}
int main()
{
    struct node *head = 0, *top, *listL;
    int n, a, b, m, i = 1, j = 1;

    printf("Enter first number -> ");
    scanf("%d", &n);
    while (n > 0)
    {
        a = n % 10;
        head = impleList(head, a);
        n = n / 10;
        i++;
    }

    printf("Enter second number -> ");
    scanf("%d", &m);
    while (m > 0)
    {
        b = m % 10;
        top = impleList(top, b);
        m = m / 10;
        j++;
    }
    listL = subtractList(head, top);
    printf("\nList 1 : ");
    head = rev(head);
    display(head);

    printf("\n\nList 2 : ");
    top = rev(top);
    display(top);

    printf("\n\nSubtraction of numbers is : ");
    listL = rev(listL);
    display(listL);
    return 0;
}
Q5.........................
#include <stdio.h>
#include <stdlib.h>

    struct Node
{
    int data;
    struct Node *next;
};

void insertNode(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void rearrangeNodes(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct Node *slow = *head;
    struct Node *fast = *head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *prev = NULL;
    struct Node *current = slow->next;
    struct Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    slow->next = NULL; // Break the list into two halves

    struct Node *first = *head;
    struct Node *second = prev;
    while (second != NULL)
    {
        struct Node *firstNext = first->next;
        struct Node *secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    struct Node *head = NULL;
    int choice, data;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Rearrange Nodes\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data for the new node: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            rearrangeNodes(&head);
            printf("Nodes rearranged successfully.\n");
            break;
        case 3:
            printf("Linked List: ");
            displayList(head);
            break;
        case 4:
            freeList(head); // Free allocated memory before exiting
            printf("Program terminated.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

Q6........................
#include <stdio.h>
#include <stdlib.h>

    struct node
{
    int data;
    struct node *next;
};

struct node *createNode(struct node *head, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory cannt allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->next = 0;
    return newnode;
}

struct node *impleList(struct node *head, int data)
{
    struct node *newnode, *temp;
    newnode = createNode(head, data);
    temp = head;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf(" -> ");
        }
        printf("%d", temp->data);
    }
}
void splitList(struct node *head, struct node **positiveL, struct node **negativeL)
{
    struct node *temp = head;
    while (temp != 0)
    {
        if (temp->data >= 0)
        {
            *positiveL = impleList(*positiveL, temp->data);
        }
        else
            *negativeL = impleList(*negativeL, temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head = 0, *positiveL = 0, *negativeL = 0;
    int n, data, V, i = 1, count = 0;
    printf("Enter the total no of elements you want to insert :\n");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("Enter %d element -> ", i);
        scanf("%d", &data);
        head = impleList(head, data);
        i++;
        count++;
    }
    printf("\nTotal elements: %d\n", count);

    printf("\nOriginal Linked List: ");
    display(head);

    splitList(head, &positiveL, &negativeL);

    printf("\nPositive Linked List: ");
    display(positiveL);

    printf("\nNegative Linked List: ");
    display(negativeL);

    return 0;
}
Q7......................
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

    struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countNodesFromRight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodesFromRight(root->right);
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Insert a key\n");
    printf("2. Search for a key\n");
    printf("3. Delete a node\n");
    printf("4. Count total number of leaf nodes\n");
    printf("5. Find height of the binary search tree\n");
    printf("6. Count total numbers of nodes from right hand side of the root node\n");
    printf("7. Inorder Traversal\n");
    printf("8. Exit\n");
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
            {
                printf("Key %d found in the tree.\n", key);
            }
            else
            {
                printf("Key %d not found in the tree.\n", key);
            }
            break;

        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("Node with key %d deleted from the tree.\n", key);
            break;

        case 4:
            printf("Total number of leaf nodes: %d\n", countLeafNodes(root));
            break;

        case 5:
            printf("Height of the binary search tree: %d\n", height(root));
            break;

        case 6:
            printf("Total number of nodes from right side of the root: %d\n", countNodesFromRight(root));
            break;

        case 7:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 8:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}

Q8...................
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct node
{
    int data;
    int power;
    struct node *next;
};

struct node *createNode(int data, int power)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Invalid");
        exit(1);
    }
    newnode->data = data;
    newnode->power = power;
    newnode->next = 0;
    return newnode;
}

struct node *impleList(struct node *start, int data, int power)
{
    struct node *temp, *newnode;
    newnode = createNode(data, power);
    temp = start;
    if (start == 0)
    {
        start = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return start;
}
void display(struct node *start)
{
    struct node *temp = start;
    if (start == 0)
    {
        printf("List is empty");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%dx^%d", temp->data, temp->power);
            temp = temp->next;
            printf(" + ");
        }
        printf("%dx^%d", temp->data, temp->power);
    }
}

struct node *addP(struct node *head, struct node *top, int m, int n)
{
    struct node *temp, *prev;
    if (n >= m)
    {
        temp = head;
        prev = top;
        while (temp != 0)
        {
            while (prev != 0)
            {
                if (temp->power == prev->power)
                {
                    temp->data = (temp->data) + (prev->data);
                }
                prev = prev->next;
            }
            temp = temp->next;
            prev = top;
        }
        return head;
    }
    else
    {
        prev = head;
        temp = top;
        while (temp != 0)
        {
            while (prev != 0)
            {
                if (temp->power == prev->power)
                {
                    temp->data = (temp->data) + (prev->data);
                }
                prev = prev->next;
            }
            temp = temp->next;
            prev = head;
        }
        return top;
    }
}
int main()
{
    struct node *head, *top = 0;
    head = 0;
    char exp1[20], exp2[20];
    int i, j = 1, n, m, data1;
    printf("Enter the exp in the form -> 3x2 + 2x4+ 9x0 \n");
    printf("\nEnter exp 1 -> ");
    gets(exp1);
    n = strlen(exp1);
    for (i = 0; i <= n; i++)
    {
        if (exp1[i] == 'x')
        {
            int data = exp1[i - 1] - '0';
            int power = exp1[i + 1] - '0';
            head = impleList(head, data, power);
        }
    }
    printf("Enter exp 2 -> ");
    gets(exp2);
    m = strlen(exp2);
    for (j = 0; j <= m; j++)
    {
        if (exp2[j] == 'x')
        {
            int data = exp2[j - 1] - '0';
            int power = exp2[j + 1] - '0';
            top = impleList(top, data, power);
        }
    }
    printf("\nExpression 1 is -> ");
    display(head);
    printf("\nExpression 2 is -> ");
    display(top);

    head = addP(head, top, m, n);
    printf("\nSum -> ");
    display(head);
    return 0;
}