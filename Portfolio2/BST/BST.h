#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>
#include <queue>

template <typename T>
class BST
{
private:
    // basic node structure
    // one value two children
    struct Node
    {
        T value;
        Node* left;
        Node* right;

        // Node without children
        Node(const T& newValue)
            : value(newValue), left(nullptr), right(nullptr)
        {
	  
        }
    };

    Node* root;  // Points at top node

  //delete the tree with
  void clearNode(Node* current)
  {
    if (current == nullptr)
      {
	return;
      }

    //dekete side left and right
    clearNode(current->left);
    clearNode(current->right);

    delete current;
  }
  
  Node* copyNode(const Node* current)
  {
    if (current == nullptr)
      {
	return nullptr;
      }

    //makes new copy node
    Node* copy = new Node(current->value);

    copy->left = copyNode(current->left);
    copy->right = copyNode(current->right);

    return copy;
  }
    // counts nodes
    std::size_t countNodes(Node* current) const
    {
        // no node here
        if (current == nullptr)
        {
            return 0;
        }

        // this node plus both sides
        return 1 + countNodes(current->left)
                 + countNodes(current->right);
    }

    // insert using recursion
    Node* insertNode(Node* current, const T& newValue)
    {
        if (current == nullptr)
        {
            return new Node(newValue);
        }

        if (newValue < current->value)
        {
            current->left = insertNode(current->left, newValue);
        }
        else if (current->value < newValue)
        {
            current->right = insertNode(current->right, newValue);
        }

        return current;
    }

    // Searches for value in the tree
    bool searchNode(Node* current, const T& target) const
    {
        // Value not found
        if (current == nullptr)
        {
            return false;
        }

        // value found
        if (target == current->value)
        {
            return true;
        }

        // left side
        if (target < current->value)
        {
            return searchNode(current->left, target);
        }

        // switch ro right side
        return searchNode(current->right, target);
    }

    // to find the smallest node
    Node* findMin(Node* current) const
    {
        while (current->left != nullptr)
        {
            current = current->left;
        }

        return current;
    }

    // remove using recursion
    Node* removeNode(Node* current, const T& target)
    {
        if (current == nullptr)
        {
            return nullptr;
        }

        if (target < current->value)
        {
            current->left = removeNode(current->left, target);
        }
        else if (current->value < target)
        {
            current->right = removeNode(current->right, target);
        }
        else
        {
            // No children means return nullptr
            if (current->left == nullptr &&
                current->right == nullptr)
            {
                delete current;
                return nullptr;
            }

            // return right child
            if (current->left == nullptr)
            {
                Node* child = current->right;
                delete current;
                return child;
            }

            // return left child
            if (current->right == nullptr)
            {
                Node* child = current->left;
                delete current;
                return child;
            }

            // Both children
            Node* successor = findMin(current->right);
            current->value = successor->value;

            current->right = removeNode(current->right,
                                        successor->value);
        }

        return current;
    }
  // left then(node) right now yall :)
  void inorderNode(Node* current) const
  {
    //all about that BASE
    if (current == nullptr)
      {
	return;
      }

    inorderNode(current->left);
    std::cout << current->value << " ";
    inorderNode(current->right);
  }

  // node left right :|
  void preorderNode(Node* current) const
  {
    if (current == nullptr)
      {
	return;
      }

    std::cout << current->value << " ";
    preorderNode(current->left);
    preorderNode(current->right);
  }
  //left right node
  void postorderNode(Node* current) const
  {
    if(current == nullptr)
      {
	return;
      }

    //left right
    postorderNode(current->left);
    postorderNode(current->right);

    //parent print
    std::cout << current->value << " ";
  }

    // counts the trees levels
    int heightNode(Node* current) const
    {

      if (current == nullptr)
	{
	  return 0;
	}

      //height of both sides
      int leftHeight = heightNode(current->left);
      int rightHeight = heightNode(current->right);

      if (leftHeight > rightHeight)
	{
	  return leftHeight + 1;
	}

      return rightHeight + 1;
				  
    }
public:
    // empty tree
    BST()
        : root(nullptr)
    {
      
    }

    //copy constructor
    BST(const BST& other)
      : root(nullptr)
    {
      root = copyNode(other.root);
    }

    //assignment operator
    BST& operator=(const BST& other)
    {
      if (this != &other)
	{
	  //make copy del old tree use new one
	  Node* copy = copyNode(other.root);
	  clearNode(root);
	  root = copy;
	}
      return *this;
    }
    //destructor
    ~BST()
    {
      clearNode(root);
    }
	
    // Adds a value to tree
    void insert(const T& newValue)
    {
        root = insertNode(root, newValue);
    }

    // Checks whether a value exists
    bool search(const T& target) const
    {
        return searchNode(root, target);
    }

    //removal in BST
    void remove(const T& target)
    {
        root = removeNode(root, target);
    }

    // total nodes in tree
    std::size_t size() const
    {
        return countNodes(root);
    }

    //ORDERING _____

  
    //INORDER

    void inorder() const
    {
        inorderNode(root);
        std::cout << "\n";
    }
  
    //PREORDER

    void preorder() const
    {
        preorderNode(root);
        std::cout << "\n";
    }

    //POSTORDER
    void postorder() const
    {
      postorderNode(root);
      std::cout << "\n";
    }

    //Level by Level

    void levels() const
    {
      //from <queue> header
      std::queue<Node*> nodes;
      //using it to have easy pop push etc
      if (root != nullptr)
	{
	  //adds root to back of line
	  nodes.push(root);
	}

      //empty also from <queue>
      //returns true when nothing is left
      while (!nodes.empty())
	{
	  //front gets first item in queue
	  Node* current = nodes.front();

	  //pop removing the front
	  nodes.pop();

	  std::cout << current->value << " ";

	  //if left child add to back
	  if (current->left != nullptr)
	    {
	      nodes.push(current->left);
	    }

	  //if right child add after left
	  if (current->right != nullptr)
	    {
	      nodes.push(current->right);
	    }

	}

      std::cout << "\n";
    }
      //get tree height
      int height() const
    {
      return heightNode(root);
    }
};

#endif
