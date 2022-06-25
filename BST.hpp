#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <memory>
#include <functional>
#include <unistd.h>
#include "utils.hpp"

namespace ft{



template <class Tree , bool IsConst>
class BSTIterator : ft::iterator<ft::bidirectional_iterator_tag, Tree> {
public:

    typedef typename Tree::value_type            													value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type> 						it;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, const value_type> 				const_it;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
    typedef typename ft::is_const<IsConst, typename const_it::pointer,  typename it::pointer>::type               				pointer;
    typedef typename ft::is_const<IsConst, typename const_it::reference,  typename it::reference>::type        				reference;

    typedef typename Tree::node_type                                                           			node_type;
    typedef typename Tree::node_pointer                                                        			node_pointer;
    typedef typename Tree::node_reference                                                      			node_reference;
    typedef typename Tree::node_const_pointer                                                  			node_const_pointer;
    typedef typename Tree::node_const_reference                                                			node_const_reference;

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
    // operator BSTIterator<const Tree> () const
    // { 
    //     return (BSTIterator<const Tree>(this->_node));
    // }
	 operator BSTIterator<Tree, true> () const
    { 
        return (BSTIterator<Tree, true>(this->_node));
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
		typedef typename ft::BSTIterator<self_type, false>                         	iterator;
		typedef typename ft::BSTIterator<self_type, true>                       const_iterator;
        typedef typename ft::reverse_iterator<iterator>                       reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>                  const_reverse_iterator;

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

		
        BST(const self_type& other) : _root(NULL), _last(CreateNode()), _alloc(other._alloc), _comp(other._comp), _size(0)
        {
           const_iterator it = other.begin();
           const_iterator ite =  other.end();
          
            for(; it != ite; ++it)
				insert(*it);
		}
       
        
       
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

        self_type& operator=(const self_type& other)
        {
            clear();
            _alloc = other._alloc;
            _comp = other._comp;
            _root = NULL;
            _last = CreateNode();
            _size = 0;
            

            const_iterator it = other.begin();
            const_iterator ite = other.end();
            for (; it != ite; ++it)
                insert(*it);
            return (*this);
        }

        // size_type count(const T& value) const
        // {
        //     // size_type count = 0;
        //     // const_iterator it = begin();
        //     // const_iterator ite = end();
        //     // for (; it != ite; ++it)
        //     //     if (*it == value)
        //     //         ++count;
        //     // return count;
        //     iterator p = find(value);
        //     return p == _last ? 0 : 1;
        // }

	  

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
            if(_root == NULL)
            {

                return iterator(NULL);
            }

           	node_pointer temp = GetMin();
			return iterator(temp);
		}	

        const_iterator begin() const
		{
            if(_root == NULL)
            {

                return end();
            }

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
            
            // node_pointer temp = GetMax(_root);
            // if(temp->right)
            //     return const_iterator(temp->right);
            // return const_iterator(NULL);
            const_iterator temp = const_iterator(_last);
			return temp;
            
		}	

       reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
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
		
        void swap (self_type& x)
	    {
            // std::swap(_root, x._root);
            // std::swap(_last, x._last);
            // std::swap(_size, x._size);
            // std::swap(_alloc, x._alloc);
            // std::swap(_comp, x._comp);

            node_pointer tmp_root = _root;
            node_pointer tmp_last = _last;
            allocator_type tmp_alloc = _alloc;
            Compare tmp_comp = _comp;
            size_type tmp_size = _size;

            _root = x._root;
            _last = x._last;
            _alloc = x._alloc;
            _comp = x._comp;
            _size = x._size;

            x._root = tmp_root;
            x._last = tmp_last;
            x._alloc = tmp_alloc;
            x._comp = tmp_comp;
            x._size = tmp_size;

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

	//range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first++);
			}
			
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
        
		void DeleteNode(node_pointer n)
		{
			
            if(n->left)
                n->left = NULL;
            if(n->right)
                n->right = NULL;
            if(n == _root)
                _root = NULL;
            if(n != _last)
			    _size--;
            _alloc.destroy(n);
			_alloc.deallocate(n, 1);
		}

        void erase(value_type node)
        {   

            node_pointer nodeToDelete = find(node);
			if(nodeToDelete == NULL)
				return;
            node_pointer sucessor;

            // If the node has no children, just remove it from the tree
            if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
            {
				if(nodeToDelete == _root)
				{
					_root->parent = NULL;
					DeleteNode(_root);
					return;
				}

                if (nodeToDelete->parent->left == nodeToDelete)
                    nodeToDelete->parent->left = NULL;
                else
                    nodeToDelete->parent->right = NULL;
                DeleteNode(nodeToDelete);
                return;
            }

            // If the node has only one child, replace it with its child
            if (nodeToDelete->left == NULL || nodeToDelete->right == NULL)
            {
                
               

				if(nodeToDelete == _root)
				{
					if(nodeToDelete->left)
					{
						_root = nodeToDelete->left;
						_root->parent = NULL;
					}
					else
					{
						_root = nodeToDelete->right;
						_root->parent = NULL;
					}
					DeleteNode(nodeToDelete);
					return;
				}
									
                if (nodeToDelete->left)
                    sucessor = nodeToDelete->left;
                else
                    sucessor = nodeToDelete->right;

                if (nodeToDelete->parent->left == nodeToDelete)
                    nodeToDelete->parent->left = sucessor;
                else
                    nodeToDelete->parent->right = sucessor;
                 sucessor->parent = nodeToDelete->parent;
                 DeleteNode(nodeToDelete);
        
                // if (sucessor->parent->left == sucessor)
                // {
                //     if(sucessor->left)
                //     {
                //         sucessor->parent->left = sucessor->left;
                //         sucessor->left->parent= sucessor->parent;
                //     }
                //     else
                //         sucessor->parent->left = NULL;
                // }
                // else
                // {
                //     if(sucessor->left)
                //     {
                //         sucessor->parent->right = sucessor->left;
                //         sucessor->left->parent= sucessor->parent;
                //     }
                //     else
                //         sucessor->parent->right = NULL;
                // }


                // sucessor->left = nodeToDelete->left;
                // sucessor->right = nodeToDelete->right;
               

                // if (nodeToDelete->left)
                //     nodeToDelete->left->parent = sucessor;
                // if (nodeToDelete->right)
                //     nodeToDelete->right->parent = sucessor;

                
                 
                 return;
            }
    



            // If the node has two children, find the successor of the node
			// if(nodeToDelete == _root)
			// {
			// 	if(nodeToDelete->left)
			// 	{
			// 		_root = nodeToDelete->left;
			// 		_root->parent = NULL;
			// 		if(nodeToDelete->right)
			// 		{
			// 			_root->right = nodeToDelete->right;
			// 			_root->right->parent = _root;
			// 		}
			// 	}
			// 	else
			// 	{
			// 		_root = nodeToDelete->right;
			// 		_root->parent = NULL;
			// 		if(nodeToDelete->left)
			// 		{
			// 			_root->left = nodeToDelete->left;
			// 			_root->left->parent = _root;
			// 		}
			// 	}
			// 	DeleteNode(nodeToDelete);
			// 	return;
			// }

			sucessor = GetMax(nodeToDelete->left);

			// Remove the successor from the tree
			if (sucessor->parent->left == sucessor)
            {
                if(sucessor->left)
                {
                    sucessor->parent->left = sucessor->left;
                    sucessor->left->parent= sucessor->parent;
                }
                else
				    sucessor->parent->left = NULL;
            }
			else
            {
                if(sucessor->left)
                {
                    sucessor->parent->right = sucessor->left;
                    sucessor->left->parent= sucessor->parent;
                }
                else
				    sucessor->parent->right = NULL;
            }

			// Move the successor's children to the node's position
            if(nodeToDelete != _root)
            {
                if (nodeToDelete->parent->left == nodeToDelete)
                    nodeToDelete->parent->left = sucessor;
                else
                    nodeToDelete->parent->right = sucessor;
            }
            else
                _root = sucessor;
			

			sucessor->left = nodeToDelete->left;
			sucessor->right = nodeToDelete->right;
			sucessor->parent = nodeToDelete->parent;

			if (nodeToDelete->left)
				nodeToDelete->left->parent = sucessor;
			if (nodeToDelete->right)
				nodeToDelete->right->parent = sucessor;
			 DeleteNode(nodeToDelete);
           
        }

		void clear()
		{
            if(_root == NULL)
                clear(_last);
			clear(_root);
            //_size = 0;
		}

		void clear(node_pointer n)
		{
            if(n == NULL)
                return;
			if(n->left)
				clear(n->left);
			if(n->right)
				clear(n->right);
			DeleteNode(n);
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

       void replaceNode(node_pointer node, node_pointer replacement)
        {
            // this->_end->parent->right = NULL;
            /* Parent now points to replacement */
            if (node == this->_root)
                this->_root = replacement;
            else if (node == node->parent->left)
                node->parent->left = replacement;
            else
                node->parent->right = replacement;

            /* Replacement parent now points node parent */
            if (replacement != NULL)
                replacement->parent = node->parent;

            // this->setEndNode();
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

        void print2d(node_pointer node, int space) const
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

        void print2d() const
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