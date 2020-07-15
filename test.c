#include<stdio.h>
#include<string.h>
#include"linked_list.h"

void main(void){
	
	struct node *Linked_list_head;//declare node head
	struct node *Linked_list_head2;//declare node head
	int a=1;
	float b=3.1415926;
	char c='W';
	char d[STRING_SIZE];
	strcpy(d,"we did it!!!");
	puts("DEBUG:making first linked list");
	Linked_list_head=create_head(Linked_list_head,&a,"int");//Linked_list_head is the linked list head pointer
	append_node(Linked_list_head,&b,"float");
	append_node(Linked_list_head,&c,"char");
	append_node(Linked_list_head,&d,"string");
	printList(Linked_list_head);

	int e=50038;
	float f=5.786;
	char g='P';
	char h[STRING_SIZE];
	strcpy(d,"we did it yet again!!!");
	puts("DEBUG:making second linked list");
	Linked_list_head2=create_head(Linked_list_head2,&g,"char");//Linked_list_head is the linked list head pointer
	append_node(Linked_list_head2,&f,"float");
	append_node(Linked_list_head2,&h,"string");
	append_node(Linked_list_head2,&e,"int");
	printList(Linked_list_head2);

	char i[STRING_SIZE];
	strcpy(i,"PREPENDED NODE!");
	puts("prepending node to second linked list");
	Linked_list_head2=preppend_node(Linked_list_head2,&i,"string");
	printList(Linked_list_head2);
	
	int j=99999;
	puts("inserting node in second linked list");
	insert_node(Linked_list_head2,2,&j,"int");
	printList(Linked_list_head2);

	puts("deleting node from second linked list");
	delete_node(Linked_list_head2, 2);
	printList(Linked_list_head2);

	puts("deleting head from second linked list");
	Linked_list_head2=delete_head(Linked_list_head2);
	printList(Linked_list_head2);

}
