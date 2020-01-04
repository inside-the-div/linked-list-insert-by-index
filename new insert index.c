#include<stdio.h>
#include<stdlib.h> // for memory allocation

struct node{
    int data;
    struct node *next;
}*head;

//print full link list

void printList(struct node *temp){

    printf("Your full link list is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){

    //first create a static (hard coding) link list

    struct node *node_1,*node_2,*node_3,*node_4,*temp;
    head   = (struct node *)malloc(sizeof(struct node)); // define memory
    node_1 = (struct node *)malloc(sizeof(struct node)); // define memory
    node_2 = (struct node *)malloc(sizeof(struct node)); // define memory
    node_3 = (struct node *)malloc(sizeof(struct node)); // define memory
    node_4 = (struct node *)malloc(sizeof(struct node)); // define memory

    // define value

    head->data   = 10;
    node_1->data = 20;
    node_2->data = 30;
    node_3->data = 40;
    node_4->data = 50;

    //make link
    head->next   = node_1;
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = NULL;

    //print full link list (create a function)
    temp = head;
    printList(temp);

    //now insert based on index number

    int index,i,num;
    struct node *new_node;
    printf("Enter the index number: ");
    scanf("%d",&index);
    printf("\nEnter the value of index: ");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    i = 0;

    temp = head;
    while(temp != NULL){

        i++;
        if(index == 0){
            //insert first
            new_node->data = num;
            new_node->next = head;
            head = new_node;
            break;

        }else if(i == index){

            new_node->data = num;
            new_node->next = temp->next;
            temp->next = new_node;
        }
        temp = temp->next;
    }
    if(temp == NULL && i < index){
        printf("%d index not found\n",index);
    }

    temp = head;
    printList(temp);

    return 0;

}
