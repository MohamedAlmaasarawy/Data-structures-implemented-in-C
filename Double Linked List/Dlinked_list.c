#include "Dlinked_list.h"

void Insert_Node_At_Beginning(struct Node **List, uint32 Data)
{
    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));

    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if the list is empty */
        if(NULL == *List)
        {
            TempNode->RightNodeLink = NULL;
            TempNode->LeftNodeLink = NULL;
            *List = TempNode;
        }
        /* List is not empty */
        else
        {
            TempNode->RightNodeLink = (*List); /* Make the new node to be the head */
            TempNode->LeftNodeLink = NULL;     /* Initialize the new node from the left to NULL */
            (*List)->LeftNodeLink = TempNode;  /* Initialize the primary node from the left to new node address */
            (*List) = TempNode;                /* Make the address of new node to be the head of the list  */
        }
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_At_End(struct Node *List, uint32 Data)
{
    struct Node *TempNode = NULL;
    struct Node *ListNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        TempNode->RightNodeLink = NULL;
        ListNode = List;
        while(NULL != ListNode->RightNodeLink)
        {
            ListNode = ListNode->RightNodeLink;
        }
        TempNode->LeftNodeLink = ListNode;
        ListNode->RightNodeLink = TempNode;
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_After(struct Node *List, uint32 Data, uint32 position)
{
    struct Node *TempNode = NULL;
    struct Node *ListNodeOne = NULL;
    struct Node *ListNodeTwo = NULL;

    ListNodeOne = List;
    while(position != 1)
    {
        ListNodeOne = ListNodeOne->RightNodeLink;
        position--;
    }

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if the position the user choose it is the end of the list */
        if(NULL == ListNodeOne->RightNodeLink)
        {
            ListNodeOne->RightNodeLink = TempNode;
            TempNode->LeftNodeLink = ListNodeOne;
            TempNode->RightNodeLink = NULL;
        }
        else
        {
            ListNodeTwo = ListNodeOne->RightNodeLink;
            ListNodeOne->RightNodeLink = TempNode;
            ListNodeTwo->LeftNodeLink = TempNode;
            TempNode->LeftNodeLink = ListNodeOne;
            TempNode->RightNodeLink = ListNodeTwo;
        }
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position)
{
    struct Node *TempNode = NULL;
    struct Node *ListNodeOne = NULL;
    struct Node *ListNodeTwo = NULL;
    uint32 Nodeposition = position;

    ListNodeOne = *List;
    while(Nodeposition > (position - 1))
    {
        ListNodeOne = ListNodeOne->RightNodeLink;
        Nodeposition--;
    }

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if the user want to */
        if(1 == position)
        {
            TempNode->LeftNodeLink = NULL;
            TempNode->RightNodeLink = (*List);
            (*List)->LeftNodeLink = TempNode;
            (*List) = TempNode;
        }
        else
        {
            ListNodeTwo = ListNodeOne->RightNodeLink;
            ListNodeOne->RightNodeLink = TempNode;
            ListNodeTwo->LeftNodeLink = TempNode;
            TempNode->RightNodeLink = ListNodeTwo;
            TempNode->LeftNodeLink = ListNodeOne;
        }
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}

void Delete_Node_At_Beginning(struct Node **List)
{
    struct Node *TempNode = *List;
    if(NULL == *List)
    {
        printf("The list is empty !! \n");
    }
    else
    {
        (*List) = (*List)->RightNodeLink;
        (*List)->LeftNodeLink = NULL;
        free(TempNode);
        TempNode = NULL;
        /*
        Another solution
        *List = (*List)->RightNodeLink;
        free((*List)->LeftNodeLink);
        (*List)->LeftNodeLink = NULL;
        */
    }
}

void Delete_Node_At_End(struct Node *List)
{
    struct Node *TempNodeOne = List;
    struct Node *TempNodeTwo = NULL;

    while(NULL != TempNodeOne->RightNodeLink)
    {
        TempNodeOne = TempNodeOne->RightNodeLink;
    }
    TempNodeTwo = TempNodeOne->LeftNodeLink;
    TempNodeTwo->RightNodeLink = NULL;
    free(TempNodeOne);
    TempNodeOne = NULL;
}

void Delete_Node_At_Intermediate(struct Node *List, uint32 position)
{
    struct Node *TempNodeOne = List;
    struct Node *TempNodeTwo = NULL;
    if(1 == position)
    {
        printf("use function Delete_Node_At_Beginning \n");
    }
    else
    {
        while(position != 1)
        {
            TempNodeOne = TempNodeOne->RightNodeLink;
            position--;
        }
        TempNodeTwo = TempNodeOne->LeftNodeLink;
        TempNodeTwo->RightNodeLink = TempNodeOne->RightNodeLink;
        TempNodeOne->RightNodeLink->LeftNodeLink = TempNodeTwo;
        free(TempNodeOne);
        TempNodeOne = NULL;
    }

}

void Display_All_Nodes_Forward(struct Node *List)
{
    struct Node *TempNode = List;
    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%i => ", TempNode->NodeData);
    while(NULL != TempNode->RightNodeLink)
    {
        TempNode = TempNode->RightNodeLink;
        printf("%i => ", TempNode->NodeData);
    }
    if(NULL == TempNode->RightNodeLink)
    {
        printf("NULL \n");
    }
}

void Display_All_Nodes_Reverse(struct Node *List)
{
    struct Node *TempNode = List;
    printf("\nTraversal in reverse direction ==> ");
    printf("Data : ");
    /* To access last node in linked list */
    while(NULL != TempNode->RightNodeLink)
    {
        TempNode = TempNode->RightNodeLink;
    }
    printf("%i => ", TempNode->NodeData);
    while(NULL != TempNode->LeftNodeLink)
    {
        TempNode = TempNode->LeftNodeLink;
        printf("%i => ", TempNode->NodeData);
    }
    if(NULL == TempNode->LeftNodeLink)
    {
        printf("NULL \n");
    }
}
