#include "linked.h"

void Insert_Node_At_Beginning(struct Node **List)
{
    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node ));
    if(NULL != TempNode)
    {
        printf("Enter the data to insert in at the begin : ");
        scanf("%i", &TempNode->NodeData);

        if(NULL == *List)
        {
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }
        else
        {
            TempNode->NodeLink = *List;
            *List = TempNode;
        }
    }
    else {/* No thing */}
}

void Insert_Node_At_End(struct Node **List)
{
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        printf("Enter the data to insert in at the End : ");
        scanf("%i", &TempNode->NodeData);
        TempNode->NodeLink = NULL;
        /* Check if *List equal NULL that mean that is no node in this list */
        if(NULL == *List)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while(LastNode->NodeLink != NULL)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }
    else {/* No thing */}
}

void Insert_Node_After(struct Node *List)
{
    struct Node *TempNode = NULL;
    struct Node *NextNode = NULL;
    uint32 Position = ZERO_INTI;
    uint32 ListLength = ZERO_INTI;
    uint32 Counter = 1;

    printf("Enter the data to insert in a position (after 1)  : ");
    scanf("%i", &Position);

    ListLength = Get_Length(List);
    if(Position > ListLength)
    {
        printf("Invalid position -> list has (%i) length \n", ListLength);
    }
    else
    {
        NextNode = List;
        while(Counter < Position)
        {
            Counter++;
            NextNode = NextNode->NodeLink;
        }
        /* TempNode points to the node where we have to insert after it */
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if(NULL != TempNode)
        {
            printf("Enter the data to insert it : ");
            scanf("%i", &TempNode->NodeData);
            /* Connect the right side connection */
            TempNode->NodeLink = NextNode->NodeLink;
            /* Connect the Left side connection */
            NextNode->NodeLink = TempNode;
        }
        else{/* No thing */}
    }
}

void Delete_Node_At_Beginning(struct Node **List)
{
    struct Node *TempNode = *List;
    if(0 == Get_Length(List))
    {
        printf("The Linked list is empty!! \n");
    }
    else
    {
        *List = TempNode->NodeLink;
        TempNode->NodeLink = NULL;
        free(TempNode);
    }

}

void Delete_Node(struct Node *List)
{
    struct Node *NextNode = List;
    struct Node *LinkdNode = List;
    uint32 LengthNode = ZERO_INTI;
    uint32 Position = ZERO_INTI;
    uint32 CounterNode = 1;

    LengthNode = Get_Length(List);
    if(0 == LengthNode)
    {
        printf("The Linked list is empty!! \n");
    }
    else
    {
        printf("Enter the position after (1) : ");
        scanf("%i", &Position);
        if((Position > LengthNode) || (1 == Position))
        {
            printf("Use function Delete_Node_At_Beginning \n");
        }
        else
        {
            while(CounterNode < (Position - 1))
            {
                CounterNode++;
                LinkdNode = LinkdNode->NodeLink;
            }
            NextNode = LinkdNode->NodeLink;
            LinkdNode->NodeLink = NextNode->NodeLink;
            free(NextNode);
        }
    }
}
void Display_All_Nodes(struct Node *List)
{
    struct Node *TempNode = List;

    printf("Data of Linked list : ");
    if(NULL == TempNode)
    {
        printf("Linked List is empty !!");
    }
    else
    {
        while(TempNode != NULL)
        {
            printf("%i =>", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }
        if(NULL == TempNode)
        {
            printf("NULL \n");
        }
    }
}

uint32 Get_Length(struct Node *List)
{
    struct Node *TempNode = List;
    uint32 Counter = ZERO_INTI;
    while(TempNode != NULL)
    {
        Counter++;
        TempNode = TempNode->NodeLink;
    }
    return Counter;
}
