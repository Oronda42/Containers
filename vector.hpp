
#include <memory>
#include <iostream>
#include "iterator.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
struct vector
{
	typedef	T 														value_type;
	typedef	Alloc 													allocator_type;
	typedef	typename allocator_type::reference 						reference;
	typedef	typename allocator_type::const_reference 				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	typename ft::random_iterator<T>							iterator;
	typedef	typename ft::random_iterator<const T> 					const_iterator;
	//typedef	typename ft::reverse_iterator<iterator>				reverse_iterator;
	//typedef	typename ft::const_reverse_iterator<const iterator>	const_reverse_iterator;
	//typedef	typename ft::iterator_traits::difference_type		difference_type;
	typedef std::size_t						size_type;


//----------MEMBER FUNCTIONS------------

	//----------CONSTRUCTORS------------

	explicit vector (const allocator_type& alloc = allocator_type())
	{

	}

	explicit vector (size_type n, 
	const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type())
	{
		std::cout << "coucou" << std::endl;
	}

	template <class InputIterator> 
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	{
		std::cout << "pouet" << std::endl;
	}

	vector (const vector& x)
	{

	}


	//-----------DESTRUCTOR-------------

	~vector()
	{

	}

vector& operator= (const vector& rhs)
{

}


//-----------ELEMENT ACCESS------------



reference operator[] (size_type n)
{

}

const_reference operator[] (size_type n) const
{

}

reference at (size_type n)
{

}
const_reference at (size_type n) const
{

}

reference front()
{

}
const_reference front() const
{

}

reference back()
{

}
const_reference back() const
{

}


//----------MODIFIERS-----------
template <class InputIterator>
void assign (InputIterator first, InputIterator last)
{
	
}

void assign (size_type n, const value_type& val)
{

}

void push_back (const value_type& val)
{

}

void pop_back()
{

}

iterator insert (iterator position, const value_type& val)
{

}

void insert (iterator position, size_type n, const value_type& val)
{

}

template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last)
{
	
}

iterator erase (iterator position)
{

}

iterator erase (iterator first, iterator last)
{

}

void swap (vector& x)
{

}

void clear()
{

}


//----------AllOCATOR-----------

allocator_type get_allocator() const
{

}

//----------ITERATORS-----------

iterator& begin(){return iterator(_ptr);}

//  iterator& end(){return iterator.end();}
//  iterator& rbegin(){return iterator.rbegin();}
//  iterator& rend(){return iterator.rend();}

//----------CAPACITY-----------

size_type size() const
{

}

size_type max_size() const
{

}

void resize (size_type n, value_type val = value_type())
{

}

size_type capacity() const
{

}

bool empty() const
{

}

void reserve (size_type n)
{

}




//----------MEMBER VARIABLES-----------
private :
	size_t size;
	T* _ptr;
	size_t capacity;
	
};
}