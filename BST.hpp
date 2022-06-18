#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <memory>
#include <functional>
#include <unistd.h>
#include "utils.hpp"

namespace ft{



template <typename Tree >
class BSTIterator {
public:

    typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tree>::iterator_category     iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tree>::value_type            value_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tree>::difference_type       difference_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tree>::pointer               pointer;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, Tree>::reference             reference;

    typedef typename Tree::node_type                                                           node_type;
    typedef typename Tree::node_pointer                                                        node_pointer;
    typedef typename Tree::node_reference                                                      node_reference;
    typedef typename Tree::node_const_pointer                                                  node_const_pointer;
    typedef typename Tree::node_const_reference                                                node_const_reference;


    BSTIterator() : _node(NULL) {}
    BSTIterator(node_pointer node) : _node(node) {}
    node_reference operator*() { return *_node; }
    node_pointer operator->() { return _node; }


    //for non-const iterator to const iterator
    operator BSTIterator<const Tree> () const
    { 
        return (BSTIterator<const Tree>(this->_node));
    }
	
    BSTIterator& operator++() {
       _node = Tree::next(_node);
		return (*this);
    }
    BSTIterator operator++(int) {
        BSTIterator tmp = *this;
        ++(*this);
        return tmp;
    }
    bool operator==(const BSTIterator& rhs) {
        return _node == rhs._node;
    }
    bool operator!=(const BSTIterator& rhs) {
        return _node != rhs._node;
    }
    
    BSTIterator& operator--() {
        _node = Tree::prev(_node);
        return *this;
    }
    BSTIterator operator--(int) {
        BSTIterator temp = *this;
        --*this;
        return temp;
    }


	
    
private:
    node_pointer _node;

};


template <class T>
class Node_base
{
    public:
        T m_value;
        Node_base<T> *left;
        Node_base<T> *right;
		Node_base<T> *parent;

        Node_base() : left(NULL), right(NULL), parent(NULL), m_value() {}
        Node_base(T& value) : left(NULL), right(NULL), parent(NULL), m_value(value) {}
        Node_base (const Node_base<T>& other) : left(other.left), right(other.right), parent(other.parent), m_value(other.m_value) {}
        
};

 


template<class T, class Compare = std::less<T>, class BSTNode = Node_base<T>, class Alloc = std::allocator<Node_base<T> > >
class BST
{
    public :

		typedef BST<T,  Compare, BSTNode ,Alloc> 								self_type;
		typedef T 																value_type;
		typedef	 Alloc 													    	allocator_type;
        typedef typename allocator_type::size_type                              size_type;
		typedef Compare                                                     	key_compare;
		typedef typename ft::BSTIterator<self_type>                         	iterator;
		typedef typename ft::BSTIterator<const self_type>                   	const_iterator;

		typedef BSTNode                                                         node_type;
		typedef node_type*                                                      node_pointer;
		typedef node_type&                                                      node_reference;
		typedef const node_type*                                                node_const_pointer;
		typedef const node_type&                                                node_const_reference;
       
       

        BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare() ) : 
        _root(NULL), 
        _last(), 
        _alloc(alloc), 
        _comp(comp)  
        {}
       
        ~BST(){};

		void inOrderTraversal(node_pointer node)
		{
			if(node == NULL)
				return ;
			else
			{
				inOrderTraversal(node->left);
				std::cout << node->m_value.first << " " ;
				inOrderTraversal(node->right);
			}
		}

		void inOrderTraversal()
		{
			inOrderTraversal(_root);
		}

		void postTraversal(node_pointer node)
		{
			if(node == NULL)
				return ;
			else
			{
				postTraversal(node->left);
				postTraversal(node->right);
				std::cout << node->value << " " << std::endl;
			}
		}

		void preOrderTraversal(node_pointer node)
		{
			if(node == NULL)
				return;
			else
			{
				std::cout << node->value << " " << std::endl;
				preTraversal(node->left);
				preTraversal(node->right);
			}
		}
		

		node_pointer GetMin(node_pointer root)
		{

			if(root->left == NULL)
				return root;
			else
				return GetMin(root->left);
		}

		node_pointer GetMin()
		{
			return GetMin(_root);
		}
		
		node_pointer GetMax(node_pointer root)
		{
			if(root->right == NULL || root->right == &_last)
				return root;
			else
				return GetMax(root->right);
		}

		node_pointer GetMax()
		{
			return GetMax(_root);
		}

		iterator begin()
		{
			node_pointer temp = GetMin(_root);
			return iterator(temp);
		}	

		iterator end()
		{
            iterator temp = iterator(&_last);
			return temp--;
		}	

		static node_pointer next(node_pointer n)
		{
			// Gets the next node in an in-order traversal of the tree; returns null

			if (!n) { return n; }

			// If the node has a right child, we traverse the link to that child
			// then traverse as far to the left as we can:
			if (n->right)
			{
				n = n->right;
				while (n->left) { n = n->left; }
			}
			// If the node is the left node of its parent, the next node is its
			// parent node:
			else if (n->parent && n == n->parent->left)
			{
				n = n->parent;
			}
			// Otherwise, this node is the furthest right in its subtree; we 
			// traverse up through its parents until we find a parent that was a
			// left child of a node.  The next node is that node's parent.  If 
			// we have reached the end, this will set node to null:
			else
			{
				while (n->parent && n == n->parent->right) 
				{
					n = n->parent; 
				}
				n = n->parent;
			}
			return n;
		}

       static  node_pointer prev(node_pointer n)
        {
            // Gets the previous node in an in-order traversal of the tree; returns null
            if (!n) { return n; }
            // If the node has a left child, we traverse the link to that child
            // then traverse as far to the right as we can:
            if (n->left)
            {
                n = n->left;
                while (n->right) { n = n->right; }
            }
            // If the node is the right node of its parent, the previous node is its
            // parent node:
            else if (n->parent && n == n->parent->right)
            {
                n = n->parent;
            }
            // Otherwise, this node is the furthest left in its subtree; we 
            // traverse up through its parents until we find a parent that was a
            // right child of a node.  The previous node is that node's parent.  If 
            // we have reached the end, this will set node to null:
            else
            {
                while (n->parent && n == n->parent->left) 
                {
                    n = n->parent; 
                }
                n = n->parent;
            }
            return n;
        }
		
        
        bool isInf(const value_type& lhs, const value_type& rhs) const
        {
            return _comp(lhs, rhs);
        }
        bool isEqual(const value_type& lhs, const value_type& rhs) const
        { 
            return (!_comp(lhs, rhs) && !_comp(rhs, lhs)); 
        }
      
        bool isSup(const value_type& lhs, const value_type& rhs) const
        {
            return (!_comp(lhs, rhs) && !isEqual(lhs, rhs));
        }

        

        bool insert( T value)
        {
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, value);

            if (_root == NULL)
            {
                _root = new_node;
                return true;
            }
               
            node_pointer current = _root;
            node_pointer parent;
           
            while (current && current != &_last)
            {
                parent = current;
               
                if (isInf(value, current->m_value))
                {
                    current = current->left;
                    if(current == NULL)
                    {
                        parent->left = new_node;
                        new_node->parent = parent;
                        break;
                    }
                }
                else if(isSup(value, current->m_value))
                {
                    
                    current = current->right;
                    if(current == NULL || current == &_last)
                    {
                        parent->right = new_node;
                        new_node->parent = parent;
                        break;
                    }
                   
                }
                else if (isEqual(value, current->m_value))
                {
                    std::cout << "WARNING equal Key" << std::endl;
                    return false;
                }
            }
            
            node_pointer max = GetMax();
            max->right = &_last;
            _last.parent = max;
            _size++;
            return true;
        }

        node_pointer find(T value)
        {
            node_pointer current = _root;
            while (current != NULL)
            {
                if (_comp(value, current->m_value) > 0)
                    current = current->left;
                else if (_comp(value, current->m_value) < 0)
                    current = current->right;
                else
                    return current;
            }
            return NULL;
        }
        void print_tree_inOrder()
        {
            std::cout << "inorder: ";
            print_tree(_root);
        }

        void print_tree(node_pointer node)
        {
            if (node == NULL || node == &_last)
                return;
            
            print_tree(node->left);
            std::cout << node->m_value.first << " " ;
            print_tree(node->right);
        }

        #define COUNT 5

        void print2d(node_pointer node, int space)
        {
            if (node == NULL)
                return;
            space += COUNT;
           
            print2d(node->right, space);
             
            std::cout << std::endl;
            for (int i = COUNT; i < space; i++)
                std::cout << " ";
            if(node == &_last)
            {
                std::cout << "LAST" << std::endl;
            }
            else
            {
                std::cout << node->m_value.first << std::endl;
            }
            
            print2d(node->left, space);
        }

        void print2d()
        {
           
            print2d(_root, COUNT);
        }

        node_pointer GetRoot()
        {
            return _root;
        }
        private:
            node_pointer _root;
			node_type _last;
            allocator_type _alloc;
            key_compare _comp;
            size_type _size;
};

}

#endif