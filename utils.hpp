/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:10:41 by oronda            #+#    #+#             */
/*   Updated: 2022/05/21 15:34:57 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft{

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



#endif

}