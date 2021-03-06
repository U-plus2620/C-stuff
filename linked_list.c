#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_list.h"


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

struct node *create_head(struct node *Llist_head, void *data, char *type){
	Llist_head=(struct node *)errorchecked_malloc(sizeof(struct node));//give the node valid and unique memory space	
	Llist_head->type=type;
	Llist_head->data=data;
	Llist_head->next=NULL;
	return Llist_head;
}



void append_node(struct node *Llist_head, void *data, char *type){
	struct node *CURRENT=Llist_head;
	struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
                while(CURRENT->next!=NULL){
                        CURRENT=CURRENT->next;
                }
                CURRENT->next=new_node;
                CURRENT=new_node;
                CURRENT->type=type;
                CURRENT->data=data;
                CURRENT->next=NULL;
}

struct node *preppend_node(struct node *Llist_head, void *data, char *type){
		struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
		new_node->type=type;
                new_node->data=data;
                new_node->next=Llist_head;
			return new_node;
}

void insert_node(struct node *Llist_head, int location, void *data, char *type){
		int counter=-1;
		struct node *new_node=(struct node *)errorchecked_malloc(sizeof(struct node));
		struct node *prev_node=NULL;
		struct node *current_node=NULL;
		
		new_node->type=type;
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

void modify_node(struct node *Llist_head, int location, void *data, char *type){
	insert_node(Llist_head,location,data,type);
}



void delete_node(struct node *Llist_head, int location){
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

int evaluate(char *type){
    char* types[]={"int","float","char","string"};
    for(int i=0;i<sizeof(types);i++){
        if(strcmp(types[i],type)==0){
            printf("evaluate function returned %d\n",i);
	      return i;
        }
    }
}

void print(void *data, char *type){
    enum Types {
        interger,
        floater,
        character,
        string
    };
    switch (evaluate(type)){
        case interger:
            printf("type is %s and data is %d\n",type,*(int*)data);
            break;
        case floater: 
            printf("type is %s and data is %f\n",type,*(float*)data);
            break;
        case character:
            printf("type is %s and data is %c\n",type,*(char*)data);
            break;
        case string:
            printf("type is %s and data is %s\n",type,(char *)data);
            break;
        default:
            fprintf(stderr,"invalid argument data type %s\n",type);
            break;
    }
    
} 
void printList(struct node *head){
	struct node *CURRENT=head;
                while(CURRENT!=NULL){
			print(CURRENT->data, CURRENT->type);
			CURRENT=CURRENT->next;
        	      }
      puts("END OF LIST REACHED");
}


