/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:10:41 by oronda            #+#    #+#             */
/*   Updated: 2022/06/24 16:50:12 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

namespace ft{


    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};


    template <class Iterator>
    struct iterator_traits 
    {
      typedef typename Iterator::difference_type		difference_type; 
      typedef typename Iterator::value_type			    value_type;
      typedef typename Iterator::pointer				    pointer;
      typedef typename Iterator::reference			    reference;
      typedef typename Iterator::iterator_category	iterator_category;
    };
    
    template <class T>
    struct iterator_traits<T*> 
    {
      typedef std::ptrdiff_t	difference_type; 
      typedef T			value_type;
      typedef T*			pointer;
      typedef T&			reference;
      typedef typename ft::random_access_iterator_tag	iterator_category; 
    };

    template <class T>
    struct iterator_traits<const T*>
    {
      typedef std::ptrdiff_t	difference_type;
      typedef T			value_type;
      typedef const T*			pointer;
      typedef const T&			reference;
      typedef typename ft::random_access_iterator_tag	iterator_category;
    };

    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
      typedef Category	iterator_category;
      typedef T			value_type;
      typedef Distance	difference_type;
      typedef Pointer		pointer;
      typedef Reference	reference;
    };

	
	template <bool Flag, class T, class F>
	struct is_const;

	template <class T, class F>
	struct is_const<true, T, F>
	{
		typedef T type;
	};

	template <class T, class F>
	struct is_const<false, T, F>
	{
		typedef F type;
	};

  


	template<bool, typename>
	struct enable_if 
	{ };

	template<typename T>
	struct enable_if<true, T>
	{ typedef T type; };

  

	struct false_type
	{};

	struct true_type
	{};

	template<typename T>
	struct is_integral
	{
		enum { value = 0 };
		typedef false_type type;
	};

  template<>
    struct is_integral<bool>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<char>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<signed char>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned char>
    {
      enum { value = 1 };
      typedef true_type type;
    };

# ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    struct is_integral<wchar_t>
    {
      enum { value = 1 };
      typedef true_type type;
    };
# endif

#ifdef _GLIBCXX_USE_CHAR8_T
  template<>
    struct is_integral<char8_t>
    {
      enum { value = 1 };
      typedef true_type type;
    };
#endif

// #if __cplusplus >= 201103L
//   template<>
//     struct is_integral<char16_t>
//     {
//       enum { value = 1 };
//       typedef true_type type;
//     };

//   template<>
//     struct is_integral<char32_t>
//     {
//       enum { value = 1 };
//       typedef true_type type;
//     };
// #endif

  template<>
    struct is_integral<short>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned short>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<int>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned int>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<long>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned long>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<long long>
    {
      enum { value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned long long>
    {
      enum { value = 1 };
      typedef true_type type;
    };

    template<class iterator> 
    typename ft::iterator_traits<iterator>::difference_type  distance (iterator first, iterator last)
    {
      typename ft::iterator_traits<iterator>::difference_type result = 0;
      while (first != last)
      {
        first++;
        result++;
      }
      return (result);
    }

    
	template <class iterator1, class iterator2>
	bool lexicographical_compare (iterator1 first1, iterator1 last1, iterator2 first2, iterator2 last2)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2); 
	}

  template <class T1, class T2> 
  struct pair
  {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(), second() { }

        template<class U, class V> 
        pair (const pair<U,V>& src) : first(src.first), second(src.second){}

        pair (const first_type& a, const second_type& b) : first(a), second(b){}

        pair& operator= (const pair& src)
        {
            first = src.first;
            second = src.second;
            return (*this);
        };

  };

  template <class T1, class T2>
  bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return x.first == y.first && x.second == y.second; 
  }

  template <class T1, class T2>
  bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return !(x == y); 
  }

  template <class T1, class T2>
  bool operator<(const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second); 
  }

  template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return !(y < x); 
  }

  template <class T1, class T2>
  bool operator>(const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return y < x; 
  }

  template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& x, const pair<T1,T2>& y)
  { 
    return !(x < y); 
  }

    // template <typename Tkey, typename Tvalue>
    // std::ostream	&operator<<(std::ostream &os, pair<Tkey, Tvalue> const &src)
    // {
    //     std::cout << "key = " << src.first << ", value = " << src.second << " ";
    //     return (os);
    // };

  template <class T1,class T2>
  ft::pair<T1,T2> make_pair (T1 x, T2 y)
  {
    return (pair<T1,T2>(x,y));
  }

  template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
}
#endif

