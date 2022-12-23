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
struct node *merge(struct node *head1, struct node *head2)
{
    struct node*temp1=head1;
    struct node*temp2=head2;
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data = -1;
    newNode->next = NULL;
    struct node*ptr=newNode;
 
    while(temp1!=NULL&&temp2!=NULL){
		if(temp1->data<temp2->data){
          ptr->next=temp1;
            ptr=ptr->next;
            temp1=temp1->next;
        }
        else{
            ptr->next = temp2;
            ptr=ptr->next;
            temp2=temp2->next;
        }
    }
    if(temp1!=NULL){
        ptr->next=temp1;
    }
     if(temp2!=NULL){
        ptr->next=temp2;
    }
    
    return newNode->next;
}
int main()
{
    int d, n;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("enter the no of elements in linked list 1\n");
    scanf("%d", &n);
    printf("enter data for linked list 1\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        head1 = addNode(d, head1);
    }
    printf("enter the no of elements in linked list 2\n");
    scanf("%d", &n);
    printf("enter data for linked list 2\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        head2 = addNode(d, head2);
    }

    traverse(head1);
    traverse(head2);
    struct node *merged = merge(head1, head2);
    printf("The merged linked list :");
    traverse(merged);
    return 0;
}