//Practice of building a linked list
//Include the functions of add, delete, sort, and search

#include <stdio.h>
#include <stdlib.h>

struct node { 
	int data;
	struct node *next; 
};

typedef struct node Node;

void PrintList(Node *head);
Node* AddNode(Node *head, int, int);
Node* DeleteNode(Node* head, int);
Node* Sort(Node *start);
void SearchNode(Node *head);

int main() { 
	int mode;
	Node *head = NULL; 
	int size=0;
	int value, position;

	while(1) {
		printf("Please enter the mode\n1. print 2.add 3.delete 4.sort 5.search 6.exit\n"); 
		scanf("%d",&mode);

		if(mode == 1) {
			PrintList(head); 
		} else if(mode == 2) {
			printf("What value do you want to add?\n");
			scanf("%d", &value);
			printf("Which position do you want to add?\n");
			scanf("%d", &position);
			head = AddNode(head, value, position); 
		} else if(mode == 3) {
			printf("Which node do you want to delete?\n");
			scanf("%d", &value);
			head = DeleteNode(head, value); 
		} else if(mode == 4) {
			head = Sort(head);
		} else if(mode == 5) { 
			SearchNode(head);
		} else if(mode == 6) { 
			break;
		} 
	}
	return 0;
}

void PrintList(Node *head) {
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

Node* AddNode(Node *head, int value, int position) {
	Node *newPtr = malloc(sizeof(Node));
	Node *previousPtr;
	Node *currentPtr;

	if(newPtr != NULL) {
		newPtr->data = value;

		previousPtr = NULL;
		currentPtr = head;

		for(int i = 0; i < position; i++) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		if(previousPtr == NULL) {
			newPtr->next = head;
			head = newPtr;
		} else {
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
		}
	} else {
		printf("%d not inserted. No memory available.\n", value);
	}
	return head;
}

Node* DeleteNode(Node* head, int value) {
	Node *previousPtr = NULL;
	Node *currentPtr = head;

	while(currentPtr != NULL && currentPtr->data != value) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->next;
	}

	if(currentPtr == NULL)
		printf("Node not found.\n");
	else if(previousPtr == NULL) {
		head = currentPtr->next;
		free(currentPtr);
	} else {
		previousPtr->next = currentPtr->next;
		free(currentPtr);
	}
	return head;
}

Node* Sort(Node *start) {
	int min, position = 0;
	Node *sortedList = NULL;

	while(start != NULL) {
		min = start->data;
		Node *sPtr = start;

		while(sPtr != NULL) {
			if(sPtr->data < min)
				min = sPtr->data;
			sPtr = sPtr->next;
		}

		sortedList = AddNode(sortedList, min, position);		
		start = DeleteNode(start, min);
		position++;
	}
	return sortedList;
}

void SearchNode(Node *head) {
	int value;
	printf("Which node do you want to search?\n");
	scanf("%d", &value);

	Node *previousPtr = NULL;
	Node *currentPtr = head;

	while(currentPtr != NULL && currentPtr->data != value) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->next;
	}

	if(currentPtr == NULL)
		printf("%d can not be found.\n", value);
	else
		printf("%d can be found in list.\n", value);
}