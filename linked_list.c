#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* TO DO */
//add error checking, fprintf, and an int return value from the void function so other 
//programs can us the return funtions as an error checking means.

//change int node.data from int to option of types (maybe use union)

/*prototype
union{
	int interger;	
	float fraction;
	char character;
	char *string;
}Data;
struct node{
	union Data data;
	struct node *next;
}Node;
*/
struct node{
	int data;
	struct node *next;
}Node;

/*prototypes*/
void *errorchecked_malloc(unsigned int); // Function prototype for errorchecked_malloc()
struct node *create_head(struct node *Llist_head, int data);//done
void delete_node(struct node *Llist_head, int location);//not done yesh kan bug
struct node *delete_head(struct node *Llist_head);//done
void append_node(struct node *Llist_head, int data);//done
void insert_node(struct node *Llist_head, int location, int data);//done
struct node *preppend_node(struct node *Llist_head, int data);//done
void modify_node(struct node *Llist_head, int location, int data);//done
void printList(struct node *Llist_head);//done



void *errorchecked_malloc(unsigned int size) { // An error-checked errorchecked_malloc() function
/*This function was copied from the book "Hacking the art of exploitation" 
by jon erickson published by "no starch press" */
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL) {
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}
	return ptr;
}

struct node *create_head(struct node *Llist_head, int data){
	Llist_head=(struct node *)errorchecked_malloc(sizeof(struct node));//give the node valid and unique memory space
		Llist_head->data=data;
		Llist_head->next=NULL;
		//puts("DEBUG:HEAD was created");
		return Llist_head;
	}



void append_node(struct node *Llist_head, int data){
	//puts("DEBUG:appending node");
			struct node *CURRENT=Llist_head;
			struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
                while(CURRENT->next!=NULL){
                        CURRENT=CURRENT->next;
                }
                CURRENT->next=new_node;
                //printf("DEBUG:next points to %p\n", CURRENT->next);
                CURRENT=new_node;
                CURRENT->data=data;
                CURRENT->next=NULL;
}

struct node *preppend_node(struct node *Llist_head, int data){
		struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
                new_node->data=data;
                new_node->next=Llist_head;
			return new_node;
}

void insert_node(struct node *Llist_head, int location, int data){
	puts("DEBUG:inserting");
		int counter=-1;
		struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
		struct node *prev_node=NULL;
		struct node *current_node=NULL;

		new_node->data=data;
                current_node=Llist_head;
		while(current_node->next!=NULL && location!=counter){//we check for COUNTER->next!=NULL because insertion doesnt come at the end of a list rather in the middle
			counter++;
			prev_node=current_node;
			current_node=current_node->next;
		}
			new_node->next=current_node;
			prev_node->next=new_node;
}

void modify_node(struct node *Llist_head, int location, int data){
	insert_node(Llist_head,location,data);
}



void delete_node(struct node *Llist_head, int location){
puts("DEBUG:removing node");
		int counter=-1;//in order to delete head?!?!?! which would need to return the head pointer
		struct node *prev_node=NULL;
		struct node *current_node=NULL;
        current_node=Llist_head;
		while(current_node && location!=counter){//we check for COUNTER->next!=NULL because insertion doesnt come at the end of a list rather in the middle
			counter++;
			prev_node=current_node;
			current_node=current_node->next;
		}
			struct node *remove=prev_node->next;
			prev_node->next=current_node->next;
			free(remove);/*freeing the memory in the end helped make 
							sure that i didnt lose the memory i wanted to keep i.e. the following node*/

}

struct node *delete_head(struct node *Llist_head){
		struct node *prev_node=NULL;
		struct node *current_node=NULL;
        prev_node=Llist_head;
		current_node=prev_node->next;
		free(prev_node);
		return current_node;
}

void printList(struct node *head){
	struct node *CURRENT=head;
                while(CURRENT!=NULL){
                        CURRENT->next ? printf("Data is %d next pointer points to %p\n",CURRENT->data, CURRENT->next) : printf("Data is %d YOU HAVE REACHED THE END OF THE LIST \n",CURRENT->data);
			CURRENT=CURRENT->next;
                }
}

void main(void){
	
	struct node *Linked_list_head;//declare node head
	struct node *Linked_list_head2;//declare node head
	
	puts("DEBUG:making first linked list");
	Linked_list_head=create_head(Linked_list_head,1);//Linked_list_head is the linked list head pointer
	append_node(Linked_list_head,2);
	append_node(Linked_list_head,3);
	append_node(Linked_list_head,4);
	printList(Linked_list_head);

	puts("DEBUG:making second linked list");
	Linked_list_head2=create_head(Linked_list_head2,10);//Linked_list_head is the linked list head pointer
	append_node(Linked_list_head2,20);
	append_node(Linked_list_head2,30);
	append_node(Linked_list_head2,40);
	printList(Linked_list_head2);

	puts("prepending node to second linked list");
	Linked_list_head2=preppend_node(Linked_list_head2,10101);
	printList(Linked_list_head2);

	puts("inserting node in second linked list");
	insert_node(Linked_list_head2,2,19293);
	printList(Linked_list_head2);

	puts("deleting node from second linked list");
	delete_node(Linked_list_head2, 2);
	printList(Linked_list_head2);

	puts("deleting head from second linked list");
	Linked_list_head2=delete_head(Linked_list_head2);
	printList(Linked_list_head2);
}

