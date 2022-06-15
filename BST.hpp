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
	
    BSTIterator& operator++() {
       _node = Tree::inOrderTraversal(_node);
		return (*this);
    }
    BSTIterator operator++(int) {

    }
    bool operator==(const BSTIterator& rhs) {
        return _node == rhs._node;
    }
    bool operator!=(const BSTIterator& rhs) {
        return _node != rhs._node;
    }
    
    BSTIterator& operator--() {
        _node = _node->prev;
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
        Node_base (const Node_base<T>& other) : left(other->left), right(other->right), parent(other->parent), m_value(other.m_value) {}
        
};

 


template<class T, class BSTNode = Node_base<T>, class Compare = std::less<T>, class Alloc = std::allocator<Node_base<T> > >
class BST
{
    public :

		typedef BST<T, BSTNode, Compare, Alloc> 								self_type;
		typedef T 																value_type;
		typedef	 Alloc 													    	allocator_type;
		typedef Compare                                                     	key_compare;
		typedef typename ft::BSTIterator<self_type>                         	iterator;
		typedef typename ft::BSTIterator<const self_type>                   	const_iterator;

		typedef BSTNode                                                         node_type;
		typedef node_type*                                                      node_pointer;
		typedef node_type&                                                      node_reference;
		typedef const node_type*                                                node_const_pointer;
		typedef const node_type&                                                node_const_reference;

  
   
   
        BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare() ) : _root(NULL), _alloc(alloc), _comp(comp) {}
       
        ~BST(){};

		void inOrderTraversal(node_pointer node)
		{
			if(node == NULL)
				return ;
			else
			{
				inOrderTraversal(node->left);
				std::cout << node->m_value << " " << std::endl;
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
				return ;
			else
			{
				std::cout << node->value << " " << std::endl;
				preTraversal(node->left);
				preTraversal(node->right);
			}
		}

		iterator begin()
		{
			return iterator(_root);
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
			if(root->right == NULL)
				return root;
			else
				return GetMax(root->right);
		}

		node_pointer GetMax()
		{
			return GetMax(_root);
		}

        bool insert(T value)
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
           
            while (current != NULL)
            {
                parent = current;
               
                if (_comp(value, current->m_value) > 0)
                {
                    current = current->left;
                    if(current == NULL)
                    {
                        parent->left = new_node;
                        break;
                    }
                }
                else if(_comp(value, current->m_value) < 0)
                {
                    current = current->right;
                    if(current == NULL)
                    {
                        parent->right = new_node;
                        break;
                    }
                }
                else
                {
                    current = new_node;
                    return false;
                }
            }
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
        void print_tree()
        {
            print_tree(_root);
        }

        void print_tree(node_pointer node)
        {
            if (node == NULL)
            {
                return;
            }
            print_tree(node->left);
            std::cout << node->value << std::endl;
            print_tree(node->right);
        }
        private:
            node_pointer _root;
            allocator_type _alloc;
            key_compare _comp;
};

}

#endif