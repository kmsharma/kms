#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T>
struct Node{
	T data;
	Node* left;
	Node* right;

	Node(T data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

template<class T>
void LevelOrder(Node<T>* root)
{
	if (root == NULL)
	{
		cout << "No Nodes Found" << "\n";
	}
	queue<Node<T>*> q;
	q.push(root);

	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			Node<T>* temp = q.front();
			q.pop();
			cout << temp->data << " ";

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
		cout << "\n";
	}
};


template<class T>
int Height(Node<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int leftHeight = Height(root->left);
		int rightHeight = Height(root->right);

		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
}

template<class T>
void PrintPath(vector<T> v)
{
	typename vector<T>::iterator itr;

	for (itr = v.begin(); itr != v.end(); itr++)
	{
		cout << *itr <<" ";
	}
}

template<class T>
void PrintAllRootToLeafPaths(Node<T>* root, vector<T> v)
{
	if (root == NULL)
		return;

	v.push_back(root->data);

	if (root->left == NULL && root->right == NULL)
	{
		PrintPath(v);
		cout << endl;
		//v.pop_back();
	}

	if (root->left)
		PrintAllRootToLeafPaths(root->left, v);


	if (root->right)
		PrintAllRootToLeafPaths(root->right, v);
}


/*
*		   10			
*		  /	  \
*		 20    30
*		/ \	  / \ 	
*	  40  50 60  70
*			/ \
*		   80  90
*/

int main()
{
	Node<int>* root = new Node<int>(10);

	root->left = new Node<int>(20);
	root->right = new Node<int>(30);

	root->left->left = new Node<int>(40);
	root->left->right = new Node<int>(50);

	root->right->left = new Node<int>(60);
	root->right->right = new Node<int>(70);

	root->right->left->left = new Node<int>(80);
	root->right->left->right = new Node<int>(90);


	LevelOrder(root);
	cout << endl;

	cout << "Tree Height = " << Height(root) << endl;


	cout << "All ROOT to Leaf Paths" << endl;
	vector<int> v;
	PrintAllRootToLeafPaths(root, v);

}