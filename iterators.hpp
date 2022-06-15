#ifndef ITERATORS_HPP
# define ITERATORS_HPP


# include "utils.hpp"

namespace ft{

template <class T> 
class random_access_iterator :  public ft::iterator<ft::random_access_iterator_tag, T>
{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;

		random_access_iterator() : _ptr(NULL) {}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator& src) : _ptr(src._ptr) {}
		virtual ~random_access_iterator() {}

		// template<typename U>
  		// random_access_iterator(const random_access_iterator<const U>& src ) : _ptr(src.base()) {}

		// template<typename U>
		// random_access_iterator(const random_access_iterator<const U>& src  ) 
		// {
		// 	_ptr = const_cast<pointer>(src.base());
		// } 

		

		operator random_access_iterator<const T> () const
        { 
			return (random_access_iterator<const T>(this->_ptr));
		}

		

		
		random_access_iterator &operator=(const random_access_iterator& src)
		{
			_ptr = src._ptr;
			return *this;
		}

		pointer base() const
		{
			return _ptr;  
		}

		random_access_iterator& operator++() 
		{
			++_ptr;
			return *this;
		}

		random_access_iterator operator++(int) 
		{
			random_access_iterator temp(*this); 
			operator++(); 
			return temp;
		}

		random_access_iterator& operator--() 
		{
			--_ptr;
			return *this;
		}

		random_access_iterator operator--(int) 
		{
			random_access_iterator temp(*this); 
			operator--(); 
			return temp;
		}

		bool operator==(const random_access_iterator& src) const 
		{
			 return _ptr==src._ptr;
		}
		
		bool operator!=(const random_access_iterator& src) const 
		{
			return _ptr!=src._ptr;
		}

		reference operator*() const
		{
			return *_ptr;
		}
		

		random_access_iterator operator-(difference_type diff) const
		{
			return _ptr - diff;
		}

		random_access_iterator operator+( difference_type diff) const
		{
			return _ptr + diff;
		}

		random_access_iterator& operator+=( difference_type diff) 
		{
			_ptr += diff;
			return *this;
		}

		random_access_iterator& operator-=( difference_type diff) 
		{
			_ptr -= diff;
			return *this;
		}

		pointer operator->() const
		{
			return &(*_ptr);
		}

		reference operator[](difference_type diff) const
		{ 
			return *(_ptr + diff); 
		}
		
	private:
		pointer _ptr;
};


	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& src) 
	{ 
		return (random_access_iterator<T>(src.base()) + n);
	}

	template <typename T>
    typename random_access_iterator<T>::difference_type  operator+(const random_access_iterator<T> lhs, const random_access_iterator<T> rhs)
    {
        return (lhs.base() + rhs.base());
    }

	template <typename T>
	random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& src) 
	{ 
		return (random_access_iterator<T>(src.base()) - n);
	}

	template <typename T>
    typename random_access_iterator<T>::difference_type  operator-(const random_access_iterator<T> lhs, const random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

	template <class left, class right>
	typename right::difference_type operator-(const left& lhs, const right& rhs) 
	{
		return (lhs.base() - rhs.base()); 
	}
	
    template <typename T>
    bool operator<(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template<typename left, typename right>
    bool operator<(const ft::random_access_iterator<left> lhs, const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T>
    bool operator<=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template<typename left, typename right>
    bool operator<=(const ft::random_access_iterator<left> lhs, const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

	template <typename T>
    bool operator>(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template<typename left, typename right>
    bool operator>(const ft::random_access_iterator<left> lhs, const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() > rhs.base());
    }
   
    template <typename T>
    bool operator>=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template<typename left, typename right>
    bool operator>=(const ft::random_access_iterator<left> lhs, const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

	template <typename T>
    bool operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template<typename left, typename right>
    bool operator==(const ft::random_access_iterator<left> lhs,  const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() == rhs.base());
    }

	template <typename T>
    bool operator!=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }
    
    template<typename left, typename right>
    bool operator!=(const ft::random_access_iterator<left> lhs, const ft::random_access_iterator<right> rhs)
    {
        return (lhs.base() != rhs.base());
    }


	template <class Iterator>
    class reverse_iterator
    {
        public:

            typedef Iterator    													iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category 		iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type      		value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type     	difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer     			pointer;
            typedef typename ft::iterator_traits<Iterator>::reference   			reference;


			reverse_iterator() : _it() {}

			explicit reverse_iterator (iterator_type it): _it(it)  {}
			
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) { }

			virtual ~reverse_iterator() {}
			
			iterator_type base() const
            { 
				return (_it); 
			}

			reference operator*() const
            {
                iterator_type it = _it;
				--it;
                return *it;
            }
			reference operator[] (difference_type n) const 
			{
				return (base()[-n - 1]); 
			}

			pointer operator->() const 
			{ 
				return (&(this->operator*())); 
			}

			reverse_iterator operator+(difference_type n) const 
			{ 
				return (reverse_iterator(_it - n)); 
			}

			reverse_iterator operator-(difference_type n) const 
			{ 
				return (reverse_iterator(_it + n)); 
			}

			reverse_iterator& operator++()
            {
                --_it;
                return (*this);
            }
			reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
			
			reverse_iterator& operator--()
            {
                ++_it;
                return (*this);
            }

			reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

			reverse_iterator& operator+= (difference_type n)
            {
                _it -= n;
                return (*this);
            }

			reverse_iterator& operator-= (difference_type n)
            {
                _it += n;
                return (*this);
            }
			
		private:
			iterator_type _it;
	};

	
	template<class left, class right>
	bool operator==(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() == rhs.base()); 
	}

	template<class left, class right>
	bool operator!=(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() != rhs.base());
	}

	template<class left, class right>
	bool operator<(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() > rhs.base()); 
	}

	template<class left, class right>
	bool operator<=(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() >= rhs.base()); 
	}

	template<class left, class right>
	bool operator>(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() < rhs.base()); 
	}

	template<class left, class right>
	bool operator>=(const ft::reverse_iterator<left>& lhs, const ft::reverse_iterator<right>& rhs)
	{ 
		return (lhs.base() <= rhs.base()); 
	}


	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ 
		return (rev_it + n); 
	}

	
	template<class Iterator>
 	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ 
		return (rhs.base() - lhs.base()); 
	}

	template<class left, class right>
 	typename reverse_iterator<right>::difference_type operator-(const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
	{ 
		return (rhs.base() - lhs.base()); 
	}
		

	// template <class T>
	// class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	// {  
	// 	public :
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;

	// 	private:
	// 		pointer _ptr;
	// };
	




	
};

#endif





