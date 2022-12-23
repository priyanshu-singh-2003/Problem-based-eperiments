
// Earlier, Apeksha created a linked list of the given data items. 
// Today, her manager asked to present the alternate elements in two 
// different linked lists.  You are required to write the code using 
// suitable data structure(s) to help her to split the original linked
// list into above required two lists.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("\ncurrent status of linked list\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node *addNode(int data, struct node *head)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Checks if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    // if is not empty add a node to the end
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
int main()
{
    int d, n;
    struct node *head = NULL;
    printf("enter the no of elements in linked list \n");
    scanf("%d", &n);
    printf("enter data for linked list \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        head = addNode(d, head);
    }
    traverse(head);
    struct node *temp = head;
    struct node *a = NULL;
    struct node *b = NULL;
    struct node *tempa = NULL;
    struct node *tempb = NULL;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            if (a == NULL)
            {
                a = temp;
                tempa = a;
                temp = temp->next;
                continue;
            }
            tempa->next = temp;
            temp = temp->next;
            tempa = tempa->next;
        }
        else
        {
            if (b == NULL)
            {
                b = temp;
                tempb = b;
                temp = temp->next;
                continue;
            }
            tempb->next = temp;
            temp = temp->next;
            tempb = tempb->next;
        }
    }
    tempa->next=NULL;
    tempb->next=NULL;

    printf("\nAfter splitting \nlinked list  : ");
    traverse(a);
    printf("linked list 2 : ");
    traverse(b);

    return 0;
}