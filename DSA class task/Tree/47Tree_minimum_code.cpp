#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Tree
{
private:
	class TreeNode
	{
	public:
		string data;
		vector<TreeNode *> children;

		TreeNode(string d)
		{
			this->data = d;
		}
	};

	TreeNode *root;

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// to be implemented
	}

	void show() // display the tree node in a line
	{
		if (root != NULL)
		{
			stack<TreeNode *> s;
			s.push(root);

			TreeNode *tmp = NULL;

			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				cout << tmp->data << endl;

				vector<TreeNode *> &cld = tmp->children;

				int k = 0;
				while (k < cld.size())
				{
					s.push(cld[k]);
					k++;
				}
				// int k = cld.size() - 1;
				// while (k >= 0)
				// {
				// 	s.push(cld[k]);
				// 	k--;
				// }
			}
		}
	}

	void addRoot(string d)
	{
		if (root == NULL)
		{
			root = new TreeNode(d);
		}
		else
		{
			// exception
		}
	}

	void addChild(string d, string parent)
	{
		TreeNode *tmp = NULL;
		TreeNode *parentPtr = NULL;

		stack<TreeNode *> s;

		s.push(root);
		while (!s.empty())
		{
			tmp = s.top();
			s.pop();

			if (tmp->data == parent)
			{
				parentPtr = tmp;
				break;
			}
			else
			{
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					s.push(*p);
				}
			}
		}
		if (parentPtr != NULL)
		{
			tmp = new TreeNode(d);
			parentPtr->children.push_back(tmp);
		}
		else
		{
			// exception
		}
	}
};

int main()
{
	Tree t;

	t.addRoot("D:");
	t.addChild("PF", "D:");
	t.addChild("OOP", "D:");
	t.addChild("Quiz", "PF");
	t.addChild("Project", "PF");
	t.addChild("DSA", "D:");
	t.addChild("Marks", "DSA");
	//t.addChild("TTTTT", "Marks");
	//t.addChild("UUUUU", "D:");

	t.show(); // Unformatted output of a tree
	cout << endl;
	return 0;
}
