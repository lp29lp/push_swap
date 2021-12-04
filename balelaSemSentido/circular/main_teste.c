#include "header.h"
//!fix it
int main()
{
	t_node	*tail = NULL;
	tail = new_node(45);
	tail = add_first(tail, 34);
	//print section
	if (tail == NULL)
		printf("no elements in list");
	else
	{
		t_node	*temp = tail->next;
		do
		{
			printf("%d\n", temp->data);
		} while(temp != tail->next);
	}
	return (0);
}
