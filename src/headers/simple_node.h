#ifndef _DATA_STRUCTS_SIMPLE_NODE
#define _DATA_STRUCTS_SIMPLE_NODE

typedef struct _simple_node SimpleNode;

struct _simple_node {
    int value;
    SimpleNode *next;
};

SimpleNode *new_simple_node(int, SimpleNode*);
void simple_node_print(SimpleNode*);
void simple_node_set_next(SimpleNode*, SimpleNode*);
void delete_simple_node(SimpleNode*);

#endif // _DATA_STRUCTS_SIMPLE_NODE