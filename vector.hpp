/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:10:48 by oronda            #+#    #+#             */
/*   Updated: 2022/05/21 23:19:19 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "iterators.hpp"
#include "utils.hpp"
#include <cstring>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
struct vector
{
	typedef	T 														value_type;
	typedef	 Alloc 													allocator_type;
	typedef	typename allocator_type::reference						reference;
	typedef	typename allocator_type::const_reference 				const_reference;
	typedef typename Alloc::pointer									pointer;
	typedef typename Alloc::const_pointer							const_pointer;
	typedef	typename ft::random_access_iterator<T>					iterator;
	//typedef	typename ft::random_access_iterator<const T> 			const_iterator;
	//typedef	typename ft::reverse_iterator<iterator>				reverse_iterator;
	//typedef	typename ft::const_reverse_iterator<const iterator>	const_reverse_iterator;
	//typedef	typename ft::iterator_traits::difference_type		difference_type;
	typedef std::size_t						size_type;


	//----------MEMBER FUNCTIONS------------

		//----------CONSTRUCTORS------------

	explicit vector (const allocator_type& alloc = allocator_type()) :  _alloc(alloc), _size(0), _capacity(0), _ptr(0)
	{
		std::cout << "ft vector default constructor" << std::endl;
	}

	explicit vector (size_type n, 
	const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _ptr(0)
	{
		std::cout << "ft vector fill constructor" << std::endl;
		_ptr = _alloc.allocate(n);
		for (size_type i = 0; i < n; i++)
		{
			_alloc.construct(_ptr + i, val);
			//*(_ptr + i) = val;
		}
	}
	
	template <class iterator> 
	vector (iterator first, iterator last,const allocator_type& alloc = allocator_type()) :  _alloc(alloc), _size(0), _capacity(0), _ptr(0)
	{
		// for (iterator it; it != last; it++ )
		// {
			
		// }
		std::cout << "ft vector range constructor" << std::endl;
	}

	vector (const vector& src) : _alloc(src._alloc)
	{
		std::cout << "ft vector copy constructor" << std::endl;
		*this = src;
	}


	//-----------DESTRUCTOR-------------

	~vector()
	{
		_alloc.destroy(_ptr);
		_alloc.deallocate(_ptr,_size);
	}

	vector& operator= (const vector& rhs)
	{

	}


	//-----------ELEMENT ACCESS------------



	reference operator[] (size_type n)
	{
		return _ptr[n];
	}

	const_reference operator[] (size_type n) const
	{
		return _ptr[n];
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
	
	void assign (iterator first, iterator last)
	{
		
	}

	void assign (size_type n, const value_type& val)
	{

	}

	void push_back (const value_type& val)
	{
		if (_size == _capacity)
		{
			if(_size == 0)
				reserve(1);
			else 
				reserve(_capacity * 2);
		}
		_alloc.construct(_ptr + _size,val);
		_size++;
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
		return _alloc;
	}

	//----------ITERATORS-----------

	iterator begin()
	{
		return iterator(_ptr);
	}

	iterator end()
	{
		return iterator(_ptr + _size);
	}
	//  iterator& rbegin(){return iterator.rbegin();}
	//  iterator& rend(){return iterator.rend();}

	//----------CAPACITY-----------

	size_type size() const
	{
		return _size;
	}

	size_type max_size() const
	{
		return std::numeric_limits<size_type>::max();
	}

	void resize(size_type n, value_type val = value_type())
	{

	}

	size_type capacity() const
	{
		return _capacity;
	}

	bool empty() const
	{
		if(_size == 0)
			return true;
		else	
			return false;
	}

	void reserve(size_type n)
	{
		if(n <= _capacity)
			return;
		n = std::max(n , _capacity*2);
		pointer temp = _alloc.allocate(n);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(temp + i, _ptr[i]);
		_alloc.deallocate(_ptr,_size);
		_ptr = temp;
		_capacity = n;
	}

	//----------MEMBER VARIABLES-----------
	private :
		pointer _ptr;
		size_t _size;
		size_t _capacity;
		allocator_type _alloc;
		
};
}
#endif