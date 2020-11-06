#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *root;
int found=0;

void display_preorder(struct node *temp);
void display_inorder(struct node *temp);
void display_postorder(struct node *temp);
void insert(int data);
void search(int n);
struct node * delete(struct node *,int);
struct node * minValueNode(struct node *);

int main(){
	printf("Enter 1 for Inserting into the BST\nEnter 2 for Preorder Traversal\nEnter 3 for Inorder Traversal");
    printf("\nEnter 4 to Postorder Traversal\nEnter 5 to Search in BST\nEnter 6 for Deleting from BST\n");
    printf("Enter 7 for Exiting\n");
	int choice,again=1;
	int n;
    
	while(again!=0){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter a number to be inserted into the BST: ");
				scanf("%d", &n);
				insert(n);
				break;
			case 2:
				printf("Preorder Traversal: ");
                display_preorder(root);
				break;
			case 3:
				printf("Inorder Traversal: ");
                display_inorder(root);
				break;
			case 4:
				printf("Postorder Traversal: ");
                display_postorder(root);
				break;
			case 5:
				printf("\nEnter a number to search in the BST: ");
				scanf("%d", &n);
				search(n);
				break;
			case 6:
                printf("\nEnter a number to delete from the BST: ");
				scanf("%d", &n);
                search(n);
                if(found==1){
                    root=delete(root,n);
                    printf("\n%d has been deleted",n);
                }    
                break;
            case 7:
				again=0;
				printf("\nExiting...");
				break;
			default:
				printf("\nInvalid Choice!");
				
		}
	}
}

void display_preorder(struct node *temp){
    if(temp==NULL)
        return;
    printf(" %d", temp->data);
    display_preorder(temp->left);
    display_preorder(temp->right);
}
void display_inorder(struct node *temp){
    if(temp==NULL)
        return;
    display_inorder(temp->left);
    printf(" %d", temp->data);
    display_inorder(temp->right);
}
void display_postorder(struct node *temp){
    if(temp==NULL)
        return;
    display_postorder(temp->left);
    display_postorder(temp->right);
    printf(" %d", temp->data);
}

void insert(int key){
    struct node *temp1,*temp2;
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        temp1=root;
        while(temp1!=NULL){
            temp2=temp1;
            if(key<temp1->data)
                temp1=temp1->left;
            else
                temp1=temp1->right;
        }
        if(key<temp2->data){
            temp2->left=(struct node *)malloc(sizeof(struct node));
            temp2=temp2->left;
            temp2->data=key;
            temp2->left=NULL;
            temp2->right=NULL;
        }
        else{
            temp2->right=(struct node *)malloc(sizeof(struct node));
            temp2=temp2->right;
            temp2->data=key;
            temp2->left=NULL;
            temp2->right=NULL;
        }
    }
}

void search(int key){
    struct node *temp=root;
    if(root==NULL){
        printf("The tree is empty!");
        found=0;
        return;
    }
    else{
        while(temp!=NULL){
            if(temp->data==key){
                printf("Element found!");
                found=1;
                return;
            }
            else if(key<temp->data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        printf("Element is not found!");
        found=0;
        return;
    }
}

struct node * minValueNode(struct node *node){
   struct node* current=node;
   while(current!=NULL && current->left!=NULL)
      current=current->left;
   return current;
}
struct node * delete(struct node *root, int key){
    if (root==NULL)
        return root;
    if (key<root->data)
        root->left=delete(root->left,key);
    else if (key>root->data)
        root->right=delete(root->right,key);
    else{
        if (root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=delete(root->right, temp->data);
    }
    return root;
}