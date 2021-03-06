#include <iostream>
#include "RBTree.h"
using namespace std;

template <class T1, class T2>
class tmp
{
private:
	RBTree<T1, T2>* tree;
public:
	tmp()
	{
		tree = new RBTree<T1, T2>();
	}
	void insert(T1 key, T2 data)
	{
		tree->insert(key, data);
	}
	T2 find(T1 key)
	{
		return tree->find(key);
	}
	void remove(T1 key)
	{
		tree->remove(key);
	}
	void print()
	{
		if (tree->NotEmpty())
		{
			tree->print();
		}
		else
		{
			cout << "[]\n\n";
		}
	}
	List<T1> get_keys()
	{
		return tree->get_keys();
	}
	List<T2> get_values()
	{
		return tree->get_values();
	}
	void clear()
	{
		tree->clear();
		tree = new RBTree<T1, T2>();
	}
};