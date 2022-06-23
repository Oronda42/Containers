#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <functional>
#include "utils.hpp" 
#include "iterators.hpp" 
#include "BST.hpp"


namespace ft
{






    
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map
{
	public :
	
    typedef Key											key_type;
    typedef T											mapped_type;
    typedef ft::pair<const Key, T>	   					value_type;
    typedef Compare                                     key_compare;
	class value_compare
	{   
		friend class map;
		friend class BST<value_type, value_compare>;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {} 
			value_compare (const value_compare& c) : comp(c.comp) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
                bool result = comp(x.first, y.first);
				return result;
			}
	};
	
    //typedef value_compare   value_comp;
    typedef Alloc                                       				allocator_type;
    typedef typename allocator_type::reference							reference;
    typedef typename allocator_type::const_reference					const_reference;
    typedef typename allocator_type::pointer							pointer;
    typedef typename allocator_type::const_pointer						const_pointer;
	
    typedef	typename allocator_type::difference_type				    difference_type;
	typedef typename allocator_type::size_type							size_type;

	typedef typename ft::BST<value_type, value_compare>					tree;
    typedef typename tree::node_type					                node_type;
    typedef typename tree::node_pointer					                node_pointer;
    typedef typename tree::node_reference				                node_reference;
    typedef typename tree::node_const_pointer			                node_const_pointer;
    typedef typename tree::node_const_reference			                node_const_reference;

    typedef	typename tree::iterator			                            iterator;
	typedef	typename tree::const_iterator	                            const_iterator;
	typedef	typename ft::reverse_iterator<iterator>						reverse_iterator;
	typedef	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

	public:


	//empty (1)	
	explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) : 
       _tree(allocator_type(), value_compare(comp)),  _comp(comp), _alloc(alloc), _size(0)   {}
	
	
				
	//range (2)	

	template <class InputIterator >
	map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type(),
    typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator >::type* = NULL) : 
	_tree(allocator_type(), value_compare(comp)),  _comp(comp), _alloc(alloc), _size(0)  
    {
        insert(first, last);
    }
		
         
	
		
	//copy (3)	
	map (const map& x)
	{
		
		_size = x._size;
		_comp = x._comp;
		_alloc = x._alloc;
		insert(x.begin(), x.end());
	}

	// ~map()
	// {
	// 	clear();
	// }

	// map& operator= (const map& x)
	// {
	// }

    // bool isInf(const value_type& lhs, const value_type& rhs) const
    // {
    //     return _comp(lhs, rhs);
    // }
    // bool isEqual(const value_type& lhs, const value_type& rhs) const
    // { 
    //     return (!_comp(lhs, rhs) && !_comp(rhs, lhs)); 
    // }
    
    // bool isSup(const value_type& lhs, const value_type& rhs) const
    // {
    //     return (!_comp(lhs, rhs) && !isEqual(lhs, rhs));
    // }


	iterator begin() 
	{
		return  _tree.begin();
	}

	const_iterator begin() const
	{
		return  _tree.begin();
	}

	iterator end() 
	{
        return _tree.end();
	}

	const_iterator end() const
	{
        return _tree.end();
	}

	// reverse_iterator rbegin()
	// {
    //     return _tree.rbegin();
	// }

	// const_reverse_iterator rbegin() const
	// {
    //     return _tree.rbegin();
	// }

	// reverse_iterator rend()
	// {
    //     return _tree.rend();
	// }

	// const_reverse_iterator rend() const
	// {
    //     return _tree.rend();
	// }

	bool empty() const
	{
		return (_size == 0);
	}

	size_type size() const
	{
		return (_tree.GetSize());
	}

	size_type max_size() const
	{
         
		return std::allocator<node_type>().max_size();
			//typename Alloc::template rebind<node_type>::other tmp;
			//return tmp.max_size();
	}

  

	mapped_type& operator[] (const key_type& k)
	{
       return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
	}


	//single element (1)	
	pair<iterator,bool> insert (const value_type& val)
	{
		bool success = _tree.insert(val);
		iterator it = find(val.first);

		return (pair<iterator,bool>(it, success));
	}

	//with hint (2)	
	iterator insert (iterator position, const value_type& val)
	{
        (void) position;
        _tree.insert(val);
        return iterator(find(val.first));
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


	// void erase (iterator position)
	// {
	// }

	// size_type erase (const key_type& k)
	// {
	// }

	// void erase (iterator first, iterator last)
	// {
	// }
	

	// void swap (map& x)
	// {
	// }

	// void clear()
	// {
	// }


	key_compare key_comp() const
	{
		return _comp;
	}


	value_compare value_comp() const
	{
		return value_compare(_comp);
	}

	iterator find (const key_type& k)
	{
		node_pointer p = _tree.find(value_type(k, T()));
		return iterator( p);
	}
	const_iterator find (const key_type& k) const
	{
		node_const_pointer p = _tree.find(value_type(k, T()));
		return const_iterator( p);
	}

	// size_type count (const key_type& k) const
	// {
	// }

	iterator lower_bound (const key_type& k)
	{
        iterator it = begin();
        iterator ite = end();
        while(it != ite)
        {
            bool inf = _comp(it->first,k);
            if(!inf)
                return it;
            it++;
        }
        return ite;
	}
	const_iterator lower_bound (const key_type& k) const
	{
        const_iterator it = begin();
        const_iterator ite = end();
        while(it != ite )
        {
            bool inf = _comp(it->first,k);
            if(!inf)
                return it;
            it++;
        }
        return ite;
	}

	iterator upper_bound (const key_type& k)
	{
         iterator it = begin();
        iterator ite = end();
        while(it != ite )
        {
            //bool isinf = _comp(it->first,k);
            bool issup = _comp(k, it->first);
            if(issup)
                return it;
            it++;
        }
        return ite;
        
	}
	const_iterator upper_bound (const key_type& k) const
	{
        const_iterator it = begin();
        const_iterator ite = end();
        while(it != ite )
        {
            
            bool issup = _comp(k, it->first);
            if(issup)
                return it;
            it++;
        }
        return ite;
	}


    pair<iterator,iterator> equal_range (const key_type& k)
	{
        pair<iterator,iterator> p = ft::make_pair(lower_bound(k), upper_bound(k));
        return p;
	}
    pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
        pair<const_iterator,const_iterator> p = ft::make_pair(lower_bound(k), upper_bound(k));
        return p;

	}

	allocator_type get_allocator() const
	{
		return _alloc;
	}

	void print2D()
	{   
        std::cout << "size: " << _size << std::endl;
		_tree.print2d();
	}

    void printinOrder()
	{   
        std::cout << std::endl;
		_tree.print_tree_inOrder();
        std::cout << std::endl;
	}

    

    private:
		tree _tree;
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;


};






} // namespace ft

#endif 