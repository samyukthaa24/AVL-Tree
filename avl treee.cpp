#include<iostream>
using namespace std;
class AVL_tree{
	struct node{
		int data;
		node *left;
		node *right;
		int height;
		
	}*root;
	public:
		AVL_tree(){
			root=NULL;
		}
	void insertion(int x){
		root=insert(x,root);
	}
	int Height(node *P){
		if(P==NULL){
			return -1;
			return P->height;
		}
	}
	int getbalance(node *P){
		if(P==NULL){
			return -1;
			return (Height(P->left)-Height(P->right));
		}
	}
	int max(int a,int b)
	{
		return(a>b)?a:b;
	}
	
	node *singleleftrotate(node *k1){
		node *k2=k1->right;
		node *temp=k2->left;
		k2->left=k1;
		k1->right=temp;
		k1->height=max(Height(k1->left),Height(k1->right))+1;
		k2->height=max(Height(k2->left),Height(k2->right))+1;
		return k2;
	}
	node *singlerightrotate(node *k2){
		node *k1=k2->left;
	    node *temp=k1->right;
     	k1->right=k2;
	    k2->left=temp;
	    k2->height=max(Height(k2->left),Height(k2->right))+1;
	    k1->height=max(Height(k1->left),Height(k1->right))+1;
	    return k1;
		
	}
	node *doubleleftrightrotate(node *k3){
		k3->left=singlerightrotate(k3->left);
		return singleleftrotate(k3);
		
	}
	node *doublerightleftrotate(node *k1){
		k1->right=singleleftrotate(k1->right);
		return singlerightrotate(k1);
	}
	node *insert(int x,node*T){
		if(T==NULL){
			T=new node;
			T->data=x;
			T->left=T->right=NULL;
			T->height=0;
		}
		else if(x<T->data){
			T->left=insert(x,T->left);
			if(Height(T->left)-Height(T->right)>=2){
				if(x<T->left->data){
					T=singlerightrotate(T);
				}
				else{
					T=doubleleftrightrotate(T);
				}
			}
		}
		else if(x>T->data){
			T->right=insert(x,T->right);
			if(Height(T->left)-Height(T->right)>=-2){
				if(x>T->right->data){
					T=singleleftrotate(T);
				}
				else{
					T=doublerightleftrotate(T);
				}
			}
		}
		T->height=1+max(Height(T->left),Height(T->right));
		return T;
	}
		node *inorder(node *T){
			if(T!=NULL){
				T->left=inorder(T->left);
		        cout<<"\t";
				cout<<T->data;"\t\n";
				T->right=inorder(T->right);
			}
		}
		
		node *postorder(node *T){
			if(T!=NULL){
				T->left=postorder(T->left);
				T->right=postorder(T->right);
				cout<<"\t";
				cout<<T->data;"\n";
				
			}
		}
		node *deleteNode(node *T, int key) {
        if (T == NULL)
            return T;

        if (key < T->data)
            T->left = deleteNode(T->left, key);
        else if (key > T->data)
            T->right = deleteNode(T->right, key);
        else {
            // Node with one child or no child
            if ((T->left == NULL) || (T->right == NULL)) {
                node *temp = T->left ? T->left : T->right;
                if (temp == NULL) {
                    temp = T;
                    T = NULL;
                } else {
                    *T = *temp; // copy child contents
                }
                delete temp;
            } else {
                // Node with two children: Get inorder successor
                node *temp = minValueNode(T->right);
                T->data = temp->data;
                T->right = deleteNode(T->right, temp->data);
            }
        }

        // If tree had only one node
        if (T == NULL)
            return T;

        // Update height
        T->height = 1 + max(Height(T->left), Height(T->right));

        // Balance it
        int balance = getBalance(T);

        // Left Heavy
        if (balance > 1 && getBalance(T->left) >= 0)
            return singlerightotate(T);

        // Left Right
        if (balance > 1 && getBalance(T->left) < 0) {
            T->left = singleleftrotate(T->left);
            return singlerightrotate(T);
        }

        // Right Heavy
        if (balance < -1 && getBalance(T->right) <= 0)
            return singleleftrotate(T);

        // Right Left
        if (balance < -1 && getBalance(T->right) > 0) {
            T->right = singlerightrotate(T->right);
            return singleleftrotate(T);
        }

        return T;
    }

    void deletion(int key) {
        root = deleteNode(root, key);
    }
		void display(){
			cout<<"Insertion in AVL Tree"<<endl;
			cout<<"Inorder Display:\n";
			inorder(root);
			cout<<endl;
			cout<<"Postorder Display:\n";
			postorder(root);
	        cout<<"\n";		
			
			
		}
};

int main(){
	AVL_tree ob;
	int x,no;
	cout<<"Enter number of entries:";
	cin>>no;
	for(int i=0;i<no;i++){
		cout<<"Enter number"<<i+1<<":";
		cin>>x;
		ob.insertion(x);
	}
	ob.display();
}
	
	


	

