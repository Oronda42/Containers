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
#include <exception>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	struct vector
	{
		typedef	T 															value_type;
		typedef	 Alloc 														allocator_type;
		typedef	typename allocator_type::reference							reference;
		typedef	typename allocator_type::const_reference 					const_reference;
		typedef typename Alloc::pointer										pointer;
		typedef typename Alloc::const_pointer								const_pointer;
		typedef	typename ft::random_access_iterator<T>						iterator;
		typedef	typename ft::random_access_iterator<const T> 				const_iterator;
		typedef	typename std::reverse_iterator<iterator>					reverse_iterator;
		typedef	typename std::reverse_iterator<const iterator>				const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef std::size_t						size_type;


	//----------MEMBER FUNCTIONS------------

		//----------CONSTRUCTORS------------

		explicit vector (const allocator_type& alloc = allocator_type()) : _ptr(0), _size(0), _capacity(0),  _alloc(alloc) {}

		explicit vector (size_type n, 
		const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) :_ptr(0),  _size(n), _capacity(n), _alloc(alloc)
		{
			
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, val);
			}
		}
		
		template <class iterator>
		vector (iterator first, iterator last,const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<iterator>::value,iterator >::type* = NULL):  _ptr(0), _size(0),  _capacity(0) ,_alloc(alloc)
		{
			
			difference_type n = ft::distance(first, last);
			_ptr = _alloc.allocate(n);
			_size = n;
			_capacity = n;
			for (int i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, *first);
				first++;
			}
		}

		vector (const vector& src) : _alloc(src._alloc)
		{
			
			_ptr =  this->_alloc.allocate(src._capacity);
			_capacity = src._capacity;
			_size = src._size;
			for (size_t i = 0; i < _size; i++)
				_ptr[i] = src[i];
		}

		
		//-----------DESTRUCTOR-------------

		~vector()
		{
			clear();
			_alloc.deallocate(_ptr, _capacity);
		}

		
		//-----------EQU OPERATOR-------------

		vector& operator=(const vector& src)
		{

			_ptr =  this->_alloc.allocate(src._capacity);
			_capacity = src._capacity;
			_size = src._size;
			for (size_t i = 0; i < this->_size; i++)
				_ptr[i] = src[i];
			return *this;

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
			if(n < 0 || n >= _size)
				throw (std::out_of_range("pouet"));
			return operator[](n);
		}
		const_reference at (size_type n) const
		{
			if(n < 0 || n >= _size)
				throw (std::out_of_range("pouet"));
			return operator[](n);
		}

		reference front()
		{
			return *(begin());
		}
		const_reference front() const
		{
			return *(begin());
		}

		reference back()
		{
			return *(end() - 1);
		}
		const_reference back() const
		{
			return *(end() - 1);
		}

		//----------MODIFIERS-----------

		template <class iterator>
		void assign(iterator first,  iterator last, typename ft::enable_if<!ft::is_integral<iterator>::value,iterator >::type* = NULL)
		{
			size_type n =  ft::distance(first,last);
			reserve(n);
			
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_ptr + i);
			_size = n;
			for (size_type i = 0; first != last;  i++,first++)
				_alloc.construct(_ptr + i, *first);
			
			return;
		}

		void assign (size_type n, const value_type& val)
		{
			reserve(n);
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_ptr + i);
			_size = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
			return;
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
			
			_alloc.destroy(_ptr + _size - 1);
			_size--;
			
		}

		void shiftToRight(size_type index, size_type n)
		{
			reserve(_size + n);
			iterator last = end();
			iterator first = begin();

			while( last != first + index)
			{
				_alloc.construct(last.base(), *(last - 1));
				last--;
			}
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type index = ft::distance(begin(), position);
			shiftToRight(index, 1);
			_alloc.construct(_ptr + index, val);
			_size++;
			position = iterator(_ptr + index);
			return position;
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type index = ft::distance(begin(), position);
			for (size_t i = 0; i < n; i++)
			{
				shiftToRight(index, 1);
				_alloc.construct(_ptr + index, val);
				_size++;
			}
			return;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last ,typename ft::enable_if<!ft::is_integral<InputIterator>::value,iterator >::type = NULL)
		{
			size_type index = ft::distance(begin(), position);
			size_type range = ft::distance(first, last);
			

			for (size_type i = 0; i < range; i++)
			{
				shiftToRight(index,1);
				_alloc.construct(_ptr + index, *(last - 1));
				last--;
				_size++;
			}
			return;
		}

		void shiftToLeft(size_type index, size_type n)
		{
			reserve(_size - n);
			iterator last = end();
			iterator first = begin();
			iterator curentPos = first + index;

			while( curentPos != last - 1 )
			{
				_alloc.construct(curentPos.base(), *(curentPos + 1));
				curentPos++;
			}
		}

		iterator erase(iterator position)
		{
			size_type index = ft::distance(begin(), position);
			shiftToLeft(index,1);
			_size--;
			position = iterator(_ptr + index);
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			size_type index = ft::distance(begin(), first);
			size_type range = ft::distance(first, last);
			
			for (size_type i = 0; i < range; i++)
			{
				shiftToLeft(index,1);
				_size--;
			}
			return iterator(_ptr + index);
		}

		void swap (vector& x)
		{
			(void)x;
			return;
		}

		void clear()
		{
			
			for (size_t i = 0; i < _size; i++)
			{
				_alloc.destroy(_ptr + i);
			}
			_size = 0;
			return;
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
		const_iterator begin() const
		{
			return const_iterator(_ptr);
		}

		iterator end() 
		{
			return iterator(_ptr + _size);
		}

		const_iterator end() const
		{
			return const_iterator(_ptr + _size);
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

		//----------CAPACITY-----------

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			
			return _alloc.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{
			if(n == _size)
				return;
			if(n < _size)
			{
				for (size_type i = 0; i < n; i++)
					_alloc.destroy((begin() + _size + i + 1).base());
				_size = n;
				return;
			}

			while(_size != n)
			{
				insert(end(),val);
			}
			return;
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
			if (_size !=0)
			{
				_alloc.deallocate(_ptr,_size);
			}
			
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


	//----------NON MEMBER FUNCS-----------


	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& left, const ft::vector<T, Alloc>& right)
	{
		if (left.size() != right.size())
			return (false);
		typename ft::vector<T>::const_iterator first1 = left.begin();
		typename ft::vector<T>::const_iterator first2 = right.begin();
		while (first1 != left.end())
		{
			if (first2 == right.end() || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& right)
	{
		return (!(lhs == right));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& right)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), right.begin(), right.end()));
	}


	template <class T, class Alloc>
	bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& right)
	{
		return (!(right < lhs));
	}


	template <class T, class Alloc>
	bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& right)
	{
		return (right < lhs);
	}


	template <class T, class Alloc>
	bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& right)
	{
		return (!(lhs < right));
	}

	template<typename T, typename Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T,Alloc> temp = x;
		x = y;
		y = temp;
	}
}
#endif