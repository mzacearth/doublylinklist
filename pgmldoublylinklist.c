#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	
	struct node *head=NULL,*pos=NULL,*tail=NULL,*temp;
	
	int ch, entry,c=0,i;
	
	while(1)
	{
		printf("\n\n1:Insert(at front)\n2:Insert(at back)\n3:Display\n4:Delete(at front)\n5:Delete(at end)\n6:Exit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			/*Insert an element at front*/
			case 1:
			{
				printf("Enter data");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					head->prev=(struct node*)malloc(sizeof(struct node));
					head->prev->next=head;
					head->prev->data=entry;
					head->prev->prev=NULL;
					head=head->prev;
				}
				break;
			}
			
			/*Insert an element at end*/
			case 2:
			{
				printf("Enter data");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			
			/*display*/
			case 3:
			{
				pos=head;
				if(head==NULL)
				{
					printf("Empty list");
					break;
				}
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				}
				break;
			}
			
			/*delete head*/
			case 4:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}
				
				if(head->next==NULL)
				{
					head=NULL;
					break;
				}
				temp=head;
				head=head->next;
				temp->next=NULL;
				head->prev=NULL;
				printf("Element deleted is %d",temp->data);
				free(temp);
				break;
			}
			
			/*delete tail*/
			case 5:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}
				if(head->next==NULL)
				{
					head=NULL;
					break;
				}
				temp=tail;
				tail=tail->prev;
				temp->prev=NULL;
				tail->next=NULL;
				printf("Element deleted is %d",temp->data);
				free(temp);
				break;
			}
			
			/*exit*/
			case 6:
			{
				printf("\nExiting...");
				exit(0);
			}
			
			default :
			{
				printf("Invalid choice");
				break;
			}
		}
	}
}
