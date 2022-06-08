#ifndef MAP
# define MAP

#include <memory>
#include <functional>
#include <utils.hpp>
#include <iterators.hpp>

namespace ft
{
    
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map
{
	public :
	
    typedef Key											key_type;
    typedef T											mapped_type;
    typedef ft::pair<const key_type, mapped_type>	    value_type;
    typedef Compare                                     key_compare;
	class Value_compare
	{   
		friend class map;
		protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  
		public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	}
	typedef ValueCompare												value_compare;
    typedef Alloc                                       				allocator_type;
    typedef typename allocator_type::reference							reference;
    typedef typename allocator_type::const_reference					const_reference;
    typedef typename allocator_type::pointer							pointer;
    typedef typename allocator_type::const_pointer						const_pointer;
	typedef	typename ft::bidirectional_iterator							iterator;
	typedef	typename ft::bidirectional_iterator<const T> 				const_iterator;
	typedef	typename ft::reverse_iterator<iterator>						reverse_iterator;
	typedef	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef typename allocator_type::size_type							size_type;

	//empty (1)	
	explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
				
	//range (2)	
	template <class InputIterator>
	map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
		
	//copy (3)	
	map (const map& x);

	~map();

	map& operator= (const map& x);

	iterator begin();

	const_iterator begin() const;

	iterator end();

	const_iterator end() const;

	reverse_iterator rbegin();

	const_reverse_iterator rbegin() const;

	reverse_iterator rend();

	const_reverse_iterator rend() const;

	bool empty() const;

	size_type size() const;

	size_type max_size() const;

	mapped_type& operator[] (const key_type& k)
	{
		return (*((this->insert(make_pair(k,mapped_type()))).first)).second
	}


	//single element (1)	
	pair<iterator,bool> insert (const value_type& val);

	//with hint (2)	
	iterator insert (iterator position, const value_type& val);

	//range (3)	
	template <class InputIterator>
  	void insert (InputIterator first, InputIterator last);


	void erase (iterator position);

	size_type erase (const key_type& k);

	void erase (iterator first, iterator last);
	

	void swap (map& x);

	void clear();

	key_compare key_comp() const;

	value_compare value_comp() const;

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const

	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	pair<iterator,iterator>             equal_range (const key_type& k);

	allocator_type get_allocator() const;

};




} // namespace ft

#endif 