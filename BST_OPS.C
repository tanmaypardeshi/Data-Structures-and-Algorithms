/*Operations on BST*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *left,*right;
};

/*fn declns*/
struct node *createbst(struct node *);
/*this function return the address of root of BST.Check SLL*/
void preorder(struct node *),inorder(struct node *),postorder(struct node *);
int countnodes(struct node *),countleaf(struct node *),countnonleaf(struct node *);
int displaylevelnode(struct node *,int);
int displaydepthbst(struct node *,int);
void insertnode(struct node *,int);
struct node *deletenodebst(struct node *root,int no);

void main()
{
	struct node *root;
	int choice,no,level;
	root=NULL;
	while(1)
	{
		clrscr();
		printf("\nOperations on BST\n");
		printf("1. Create BST\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. Count nodes\n");
		printf("6. Count leaf nodes\n");
		printf("7. Count non leaf nodes\n");
		printf("8. Display level of node\n");
		printf("9. Display depth of node\n");
		printf("10. Insert a node in BST\n");
		printf("11. Delete a node in BST\n");
		printf("12. Exit\n\n");
		printf("Enter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				root=createbst(root);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("Number of nodes are:- %d",countnodes(root));
				break;
			case 6:
				printf("Number of leaf nodes are:- %d",countleaf(root));
				break;
			case 7:
				printf("Number of non leaf nodes are:- %d",countnonleaf(root));
				break;
			case 8:
				printf("Enter value of node:- ");
				scanf("%d",&no);
				level=displaylevelnode(root,no);
				if(level==-1)
					printf("Node with value %d not found",no);
				else
					printf("Node with value %d found at level %d",no,level);
				break;
			case 9:
				printf("Depth of BST is %d",displaydepthbst(root,-1));
				break;
			case 10:
				printf("Enter the number to be inserted:- ");
				scanf("%d",&no);
				insertnode(root,no);
				break;
			case 11:
				printf("Enter a number to be deleted:- ");
				scanf("%d",&no);
				root=deletenodebst(root,no);
				printf("The no. deleted is %d",no);
				break;
			case 12:
				exit();
		}
		getch();
	}
}

struct node *createbst(struct node *root)
{
	struct node *newnode,*temp;
	char ask='y';
	while(ask=='y' || ask=='Y')
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value to be put in BST:- ");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;

		/*check whether its first node. If so, make it root*/
		if(root==NULL)
			root=newnode;
		else
		{
			temp=root;
			/*search in BST for proper place*/
			while(1)
			{
				if(newnode->data<temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
						temp=temp->left;
				}
				else /*newnode->data>temp->data*/
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
						temp=temp->right;
				}
			}/*end of while(1)*/
		}/*end of else*/
		flushall();
		printf("Add more nodes to bst:- ?");
		scanf("%c",&ask);
	}/*end of while(ask=='y' || ask=='Y')*/
	return root;
}

void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d  ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}/*recursive call*/
}

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d  ",temp->data);
		inorder(temp->right);
	}/*recursive call*/
}


void postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d  ",temp->data);
	}/*recursive call*/
}

int countnodes(struct node *temp)
{
	static int cntr;	/*auto initialised to zero*/
	if(temp!=NULL)
	{
		cntr++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	return cntr;
}


int countleaf(struct node *temp)
{
	static int cntr;
	if(temp!=NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
			cntr++;
		countleaf(temp->left);
		countleaf(temp->right);
	}
	return cntr;
}

int countnonleaf(struct node *temp)
{
	static int cntr;
	if(temp!=NULL)
	{
		if(temp->left!=NULL || temp->right!=NULL)
			cntr++;
		countleaf(temp->left);
		countleaf(temp->right);
	}
	return cntr;
}

int displaylevelnode(struct node *temp,int no)
{
	int level=-1,flag=0;
	while(temp!=NULL)
		/*temp is pointing to some valid node*/
	{
		level++;
		if(no==temp->data)
		{
			flag=1;	/*search successful*/
			break;
		}
		if(no<temp->data)
			temp=temp->left;	/*search successful*/
		else
			temp=temp->right;	/*search right subtree*/
	}
	if(flag)
		return level;
	return -1;
}

int displaydepthbst(struct node *temp,int level)
{
	static int depth=1;
	/*this is a recursive fn and everytime we will compare level
	with depth. If level<depth, we will assign level to depth*/
	if(temp!=NULL)
	{
		level++;
		if(depth<level)
			depth=level;
		/*recursive call*/
		displaydepthbst(temp->left,level);
		displaydepthbst(temp->right,level);
	}
	return depth;
}


void insertnode(struct node *root,int no)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=no;
	temp=root;
	while(1)
	{
		if(newnode->data<temp->data)
		{
			if(temp->left==NULL)
			{
				temp->left=newnode;
				break;
			}
			else
				temp=temp->left;
		}
		else /*newnode->data>temp->data*/
		{
			if(temp->right==NULL)
			{
				temp->right=newnode;
				break;
			}
			else
				temp=temp->right;
		 }
	}/*end of while(1)*/
}

struct node *deletenodebst(struct node *root,int no)
{
	struct node *temp,*parent_temp,*rn,*parent_rn,*son;

	parent_temp=NULL;
	temp=root;

	/*search for node to delete*/
	while(temp!=NULL)
	{
		if(no==temp->data)
			break;
		parent_temp=temp;
		if(no<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp==NULL)
	{
		printf("Node with data %d not found",no);
		getch();
		return root;
	}
	/*case 1 and 2 in single section*/
	if(temp->left==NULL)
		rn=temp->right;
	else
	{
		if(temp->right==NULL)
			rn=temp->left;
		else	/*2 children*/
		{
			/*rn is right subtree's leftmost node*/
			parent_rn=temp;
			rn=parent_rn->right;
			son=rn->left;

			while(son!=NULL)
			{
				parent_rn=rn;
				rn=son;
				son=son->left;
			}
			if(parent_rn!=temp)
			{
				parent_rn->left=rn->right;
				rn->right=temp->right;
			}
			rn->left=temp->left;
		}
		/*if node to be deleted is root node*/
		if(parent_temp==NULL)
			root=rn;
		else
		{
			/*node to delete is parent's left child*/
			if(temp==parent_temp->left)
				parent_temp->left=rn;
			else
				parent_temp->right=rn;
		}
	}
		free(temp);
		return root;
}
