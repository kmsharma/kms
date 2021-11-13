#include <iostream>
#include <queue>
#include <vector>
#include <iterator>

using namespace std;
template<class T>
class NAryNode
{

public :
	vector<NAryNode*> child;
	T data;

	NAryNode(T dd)
	{
		data = dd;
	}
};


template <class T>
void NAry_PreOrder(NAryNode<T>* root)
{
	if (root)
	{
		cout << root->data <<" ";

		for (auto it : root->child)
		{
			NAry_PreOrder(it);
		}
	}
};

template <class T>
void NAry_LevelOrder(NAryNode<T>* root)
{
	if (!root)
		return;

	queue<NAryNode<T>*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		while (size--)
		{
			NAryNode<T>* node = queue.front();
			cout << node->data << " ";
			queue.pop();
			for (auto it : node->child)
			{
				queue.push(it);
			}
		}
		cout << "\n";
	}
};

template <class T>
NAryNode<T>* clone(NAryNode<T> *root)
{
	if (!root)
		return nullptr;

	NAryNode<T>* newRoot = new NAryNode<T>(root->data);

	for (auto ch : root->child)
	{
		newRoot->child.push_back(clone(ch));
	}

	return newRoot;
}


//Convert to Mirror
template <class T>
void mirror(NAryNode<T>* root)
{
	if (!root)
		return;

	//convert to mirror all sub-trees
	for (auto ch : root->child)
	{
		mirror(ch);
	}

	//reverse the order
	reverse(root->child.begin(), root->child.end());
}


/*  NAry Tree
*		      10			
*		  /	\  \  \
*		 20  30 40  50   
*		/ | \	   /  \ 	
*	  60  70 80   90  100
*			/ \
*		   88  99
*/

int main()
{

	NAryNode<int>* root = new NAryNode<int>(10);
	root->child.push_back(new NAryNode<int>(20));
	root->child.push_back(new NAryNode<int>(30));
	root->child.push_back(new NAryNode<int>(40));
	root->child.push_back(new NAryNode<int>(50));


	root->child[0]->child.push_back(new NAryNode<int>(60));
	root->child[0]->child.push_back(new NAryNode<int>(70));
	root->child[0]->child.push_back(new NAryNode<int>(80));
	
	root->child[3]->child.push_back(new NAryNode<int>(90));
	root->child[3]->child.push_back(new NAryNode<int>(100));


	root->child[0]->child[2]->child.push_back(new NAryNode<int>(88));
	root->child[0]->child[2]->child.push_back(new NAryNode<int>(99));


	//Traversal
	cout << "Pre-Order - ";
	NAry_PreOrder(root);

	cout << endl;

	cout << "Level-Order - "<<endl;
	NAry_LevelOrder(root);
	
	cout << endl;

	//Clone Test
	cout << "Cloned Tree -" << endl;
	NAryNode<int>* newRoot = clone(root);
	NAry_LevelOrder(newRoot);

	cout << endl;


	//Mirror Test
	cout << "Mirror Tree -" << endl;
	mirror(root);
	NAry_LevelOrder(root);

	cout << endl;

}