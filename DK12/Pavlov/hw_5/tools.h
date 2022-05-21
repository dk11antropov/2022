#ifndef tools_h
#define tools_h

typedef struct tag_data
{
    int data;
} Data, *DataPtr;

typedef struct tag_node
{
    DataPtr toData;
    struct tag_node *leftChild;
    struct tag_node *rightChild;
} Node, *NodePtr;

typedef struct tag_tree
{
    NodePtr root;
} Tree, *TreePtr;

TreePtr createTree();
void deleteTree(TreePtr tree);

int countTree(TreePtr tree);
void displayTree(TreePtr tree);

NodePtr findNode(TreePtr tree, int data);
void insertNode(TreePtr tree, int data);
int deleteNode(TreePtr tree, int data);

void destroyNode(NodePtr node);
void destroyTree(TreePtr tree);

void printTree(TreePtr tree);
void printNode(NodePtr node);

#endif