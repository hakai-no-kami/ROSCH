#ifndef __RESCH_SCHED_ROS__
#define __RESCH_SCHED_ROS__

<<<<<<< HEAD
typedef struct rtx_node {
=======
typedef struct ros_node {
>>>>>>> 0f66135a65aa8658f39ac1dc0c874862a576aa1b
    char* name;
    int index;
    int pid;
    int depth;
    int is_exist;
    float wcet;
    float laxity;
    float global_wcet;
<<<<<<< HEAD
    struct rtx_node* parent;
    struct rtx_node* child;
    struct rtx_node* next;
=======
    struct ros_node* parent;
    struct ros_node* child;
    struct ros_node* next;
>>>>>>> 0f66135a65aa8658f39ac1dc0c874862a576aa1b
    /* struct node* parent_next; */
} node_t;

extern void node_init(node_t* node);
extern void insert_child_node(node_t* parent_node, node_t* child_node);
extern node_t* make_node(int node_index);
extern node_t* search_node(node_t* node, int node_index);
extern node_t** search_leaf_node(node_t* node);
extern void show_tree_dfs(node_t* node);
extern void free_tree(node_t* node);
extern int free_node(node_t* node);

#endif
