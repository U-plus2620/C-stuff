void *errorchecked_malloc(unsigned int); // Function prototype for errorchecked_malloc()
struct node *create_head(struct node *Llist_head, void *data, char *type);
void delete_node(struct node *Llist_head, int location);
struct node *delete_head(struct node *Llist_head);
void append_node(struct node *Llist_head,void *data,char *type);
void insert_node(struct node *Llist_head, int location, void *data, char *type);
struct node *preppend_node(struct node *Llist_head, void *data, char *type);
void modify_node(struct node *Llist_head, int location, void *data, char *type);
int evaluate(char *type);
void print(void *data, char *type);
void printList(struct node *Llist_head);
