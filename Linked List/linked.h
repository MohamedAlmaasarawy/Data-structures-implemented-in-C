#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

#define ZERO_INTI 0

struct Node{
    uint32 NodeData;
    struct Node *NodeLink;
};

void Insert_Node_At_Beginning(struct Node **List);
void Insert_Node_At_End(struct Node **List);
void Insert_Node_After(struct Node *List);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node(struct Node *List);
void Display_All_Nodes(struct Node *List);
uint32 Get_Length(struct Node *List);

#endif // LINKED_H

