#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <memory>
#include <functional>
#include <unistd.h>
#include "utils.hpp"

namespace ft{



template <class Tree >
class BSTIterator : ft::iterator<ft::bidirectional_iterator_tag, Tree> {
public:

    typedef typename Tree::value_type            value_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer               pointer;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

    typedef typename Tree::node_type                                                           node_type;
    typedef typename Tree::node_pointer                                                        node_pointer;
    typedef typename Tree::node_reference                                                      node_reference;
    typedef typename Tree::node_const_pointer                                                  node_const_pointer;
    typedef typename Tree::node_const_reference                                                node_const_reference;

   private:
    node_pointer _node;
    

    public:


    BSTIterator() : _node(NULL) {}
    BSTIterator(const node_pointer node) : _node(node) {}

    BSTIterator& operator=(const BSTIterator& other) 
    {
        _node = other._node;
        return *this;
    }
    
    reference operator*() const  { return _node->m_value; }
    pointer operator->() const  { return &(_node->m_value); }

   
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


};





// template <class Tree >
// class BSTConstIterator : ft::iterator<ft::bidirectional_iterator_tag, Tree> {
// public:

//     typedef typename Tree::value_type            value_type;
//     typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
//     typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
//     typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer               pointer;
//     typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

//     typedef typename Tree::node_type                                                           node_type;
//     typedef typename Tree::node_pointer                                                        node_pointer;
//     typedef typename Tree::node_reference                                                      node_reference;
//     typedef typename Tree::node_const_pointer                                                  node_const_pointer;
//     typedef typename Tree::node_const_reference                                                node_const_reference;

//    private:
//     node_const_pointer _node;

//     public:


//     BSTConstIterator() : _node(NULL) {}
//     BSTConstIterator(node_const_pointer node) : _node(node) {}
//     //BSTConstIterator(node_const_pointer node) : _node1(node) {}

//     template<typename U>
//     BSTConstIterator(const BSTConstIterator<const U>& src ) : _node(src._node) {}
   
//     BSTConstIterator(const BSTConstIterator& other) : _node(other._node) {}

//     BSTConstIterator& operator=(const BSTConstIterator& other) 
//     {
//         _node = other._node;
//         return *this;
//     }
    
//     reference operator*() const { return _node->m_value; }
  
//     pointer operator->() const  { return &(_node->m_value); }
   

   
//     //for non-const iterator to const iterator
//     operator BSTConstIterator<const Tree> () const
//     { 
//         return (BSTConstIterator<const Tree>(this->_node));
//     }

     
 
	
//     BSTConstIterator& operator++() {
//        _node = Tree::next(_node);
// 		return (*this);
//     }
//     BSTConstIterator operator++(int) {
//         BSTConstIterator tmp = *this;
//         ++(*this);
//         return tmp;
//     }
//     bool operator==(const BSTConstIterator& rhs) {
//         return _node == rhs._node;
//     }
//     bool operator!=(const BSTConstIterator& rhs) {
//         return _node != rhs._node;
//     }
    
//     BSTConstIterator& operator--() {
//         _node = Tree::prev(_node);
//         return *this;
//     }
//     BSTConstIterator operator--(int) {
//         BSTConstIterator temp = *this;
//         --*this;
//         return temp;
//     }


// };


template <class T>
class Node_base
{
    public:
        T m_value;
       
        Node_base<T> *left;
        Node_base<T> *right;
		Node_base<T> *parent;
        bool color;
        
        

        Node_base() :  m_value(), left(NULL), right(NULL), parent(NULL), color(1) {}
        Node_base(const T& value) : m_value(value), left(NULL), right(NULL), parent(NULL), color(1)  {}
        Node_base (const Node_base<T>& other) : m_value(other.m_value), left(other.left), right(other.right), parent(other.parent), color(other.color)  {}
        
};




template<class T, class Compare = std::less<T>, class BSTNode = Node_base<T>, class Alloc = std::allocator<Node_base<T> > >
class BST
{
    public :

        typedef T 																value_type;
		typedef BST<value_type,  Compare, BSTNode ,Alloc> 						self_type;
		typedef	 Alloc 													    	allocator_type;
        typedef typename allocator_type::size_type                              size_type;
		typedef Compare                                                     	key_compare;
		typedef typename ft::BSTIterator<self_type>                         	iterator;
		typedef typename ft::BSTIterator<const self_type>                       const_iterator;

		typedef BSTNode                                                         node_type;
		typedef node_type*                                                      node_pointer;
		typedef node_type&                                                      node_reference;
		typedef const node_type*                                                node_const_pointer;
		typedef const node_type&                                                node_const_reference;
       


        BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare() ) : 
        _root(NULL), 
        _last(CreateNode()), 
        _alloc(alloc), 
        _comp(comp),
        _size(0)
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
            if(_root)
			    return GetMin(_root);
            return NULL;
		}
		
		node_pointer GetMax(node_pointer root) 
		{
			if(root->right == NULL || root->right == _last)
				return root;
			else
				return GetMax(root->right);
		}

		node_pointer GetMax() 
		{
			return GetMax(_root);
		}

        ////////////////////////// CONST ////////////////////////////////

       
        node_pointer GetMin(node_pointer root) const
		{

			if(root->left == NULL)
				return root;
			else
				return GetMin(root->left);
		}

		node_pointer GetMin() const
		{
			return GetMin(_root);
		}
		
		node_pointer GetMax(node_pointer root) const
		{
			if(root->right == NULL || root->right == _last)
				return root;
			else
				return GetMax(root->right);
		}

		node_pointer GetMax() const
		{
			return GetMax(_root);
		}

        ////////////////////////////////////////////////////////////////////

		iterator begin()
		{
			node_pointer temp = GetMin();
			return iterator(temp);
		}	

        const_iterator begin() const
		{
			node_pointer temp = GetMin();
			return const_iterator(temp);
		}	

		iterator end()
		{   
            iterator temp = iterator(_last);
			return temp;
		}	

        const_iterator end() const
		{
            
            // const_iterator temp = const_iterator(&_last);
			// return temp;

            node_pointer temp = GetMax(_root);
            if(temp->right)
                return const_iterator(temp->right);
            return const_iterator(NULL);
            
            // node_type temp = _last;
            // const_iterator  result (temp--);
			// return const_iterator(result);
		}	

        node_pointer GetLast() const 
        {
            return _last;
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

      

        void SetLast()
        {
            node_pointer max = GetMax();
            max->right = _last;
            _last->parent = max;
         
        }

        node_pointer CreateNode(const value_type& k = value_type())
        {
            node_pointer new_node = _alloc.allocate(1);
            _alloc.construct(new_node, k);
            return new_node;
        }


        bool insert( const T &value)
        {
           
            node_pointer new_node = CreateNode(value);
            if (_root == NULL)
            {
                _root = new_node;
                SetLast();
                _size++;
                return true;
            }
               
            node_pointer current = _root;
            node_pointer parent;
           
            while (current && current != _last)
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
                    if(current == NULL || current == _last)
                    {
                        parent->right = new_node;
                        new_node->parent = parent;
                        break;
                    }
                   
                }
                else if (isEqual(value, current->m_value))
                {
                    return false;
                }
            }
            
            SetLast();
            _size++;
            return true;
        }

        node_pointer find(T value) const
        {
            node_pointer current = _root;
            while (current != NULL)
            {
                if (isInf(value, current->m_value))
                    current = current->left;
                else if (isSup(value, current->m_value))
                    current = current->right;
                else
                    return current;
            }
            return _last;
        }
        void print_tree_inOrder()
        {
            std::cout << "inorder: ";
            print_tree(_root);
        }

        void print_tree(node_pointer node)
        {
            if (node == NULL || node == _last)
                return;
            
            print_tree(node->left);
            std::cout << node->m_value.first << " " ;
            print_tree(node->right);
        }

        #define COUNTS 5

        void print2d(node_pointer node, int space)
        {
            if (node == NULL)
                return;
            space += COUNTS;
           
            print2d(node->right, space);
             
            std::cout << std::endl;
            for (int i = COUNTS; i < space; i++)
                std::cout << " ";
            if(node == _last)
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
           
            print2d(_root, COUNTS);
        }

        node_pointer GetRoot() const
        {
            return _root;
        }

        size_type GetSize() const
        {
            return _size;
        }
       
        private:
            node_pointer _root;
			node_pointer _last;
            allocator_type _alloc;
            key_compare _comp;
            size_type _size;
};

}

#endif