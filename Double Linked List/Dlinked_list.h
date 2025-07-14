#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <stdlib.h>
#include "Platform_Types.h"

#define ZERO_INTI 0

struct Node{
    uint32 NodeData;
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
};

void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);

#endif // DLINKED_LIST_H
