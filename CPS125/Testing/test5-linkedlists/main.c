#include <stdio.h>
#include <stdlib.h>

// Create a node type
typedef struct node
{
	int data;
	struct node * next;
} node_t;


// Go through the list and print out the data at each node
void print_list(node_t * head)
{
	// create local variable type node, and set it to the address of the head 
	node_t * current = head;

	// checks if the current value exists
	while(current != NULL)
	{

		// print out the data from the linked list
		printf("%d\n",current -> data );

		// point the variable current to the next item on the list
		current = current -> next;
	}
}

void push(node_t *head, int data)
{
	// Set a temporary variable to the head
	node_t* current = head;

	while(current != NULL)
	{
		// Move to the last item on the list
		current = current -> next;
	}

	// Set the next item to have an allocated memory large enough
	current -> next = (node_t*)malloc(sizeof(node_t));

	// Set the current pointer to the new item
	current = current -> next;

	// Set the data to be input
	current -> data  = data;

	// Set the next value in the list to be NULL
	current -> next = NULL;
	
}

int pop_head(node_t ** head)
{

	// return value, default set to -1 for unsuccessful pop
	int ret_val = -1;

	// Create a new node
	node_t * next_node = NULL;

	// check if the current head is nulled
	if (*head == NULL)
	{
	    return -1;
	}
	
	// set the new node to the next value in the linked list
	next_node = (*head) -> next;

	// set the return value from the value about to be popped
	ret_val = (*head) -> data;

	// deallocate the memory for the current head
	free(*head);

	// set the current head to the new node
	*head = next_node;

	// return the value of the popped node
	return ret_val;
}

int pop_last(node_t * head)
{
	// Set the default return value to unsuccessful pop
	int ret_val = -1;

	node_t* current = head;

	// If there exists only one value in the list
	if (head -> next == NULL)
	{
		// take that value and return the data, then free the space allocated for head
		ret_val = head -> data;
		free(head);
		return ret_val;
	}

	/*
	  [A][next] -> [B][next] -> [C][data] -> [D][NULL]
	  
	  we start at A and check if there is value that exists for the next item in the list,
	  then check if that value points to anything (Future Elston, hope you did something successful in life)
	*/

	// Move to the second last value in the list
	while(current -> next -> next != NULL)
	{
		current = current-> next;
	}

	// take the last value's data 
	ret_val = current -> next -> data;

	// free the last value
	free(current -> next);

	// set the second last value's pointer to NULL
	current -> next = NULL;
   
	return ret_val;
		
}

int pop_by_idex(node_t** head, int n)
{
	int ret_val = -1;

	node_t * current  = *head;
	node_t * temp_node;

	// Pop the head if pop_index is 0
	if (n == 0)
	{
		return pop_head(head);
	}

	// Itterate through the list (stop at the item n-1)
	for (int i = 0; i < n-1; i++)
	{
		// If the number of elements do not exist return -1
		if (current -> next == NULL)
			return -1;
		
		current = current -> next;
	}

	// Set a temporary node to the next node to be popped, find the value of that next node
	temp_node = current -> next;
	ret_val = current -> next -> data;

	// Set the next node to the node after the currently popped one
	current -> next = temp_node -> next;

	// Remove the node that was to be popped
	free(temp_node);

	// Return poped node's value
	return ret_val;
}

// Pass a pointer the head, NOT THE HEAD ITSELF, we change it.
void move_head(node_t** head, int data)
{
    // Create a new node and set the data
    node_t * new_node = (node_t*)malloc(sizeof(node_t));
	new_node -> data = data;

	// set the next pointer of the new_node to the current head (preserve the old data and list)
	// Dereference the head 
	new_node -> next = *head;

	// Change the main head pointer to the new head, the old head is saved in the new_node
	*head = new_node;
}

int pop_by_data(node_t** head, int n)
{

    int ret_val = -1;

    node_t * current = *head;
    
    
    while(int i == 0; current -> next == NULL; i++)
    {
	if ( current -> data == n )
	    return pop_by_index(head, i)
    }
    
    return ret_val;
}

int main()
{
	
	node_t * head = NULL;

	head  = (node_t*)malloc(sizeof(node_t));

	if (head == NULL)
	{
		return 1;
	}

	head -> data = 1;
	head -> next = (node_t*)malloc(sizeof(node_t));

	head -> next -> data = 2;
	head -> next -> next = NULL;

	

	return 0;
	
}
