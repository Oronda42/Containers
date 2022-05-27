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
		enum { __value = 0 };
		typedef false_type type;
	};

  
  template<>
    struct is_integral<bool>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<char>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<signed char>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned char>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

# ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    struct is_integral<wchar_t>
    {
      enum { __value = 1 };
      typedef true_type type;
    };
# endif

#ifdef _GLIBCXX_USE_CHAR8_T
  template<>
    struct is_integral<char8_t>
    {
      enum { __value = 1 };
      typedef true_type type;
    };
#endif

// #if __cplusplus >= 201103L
//   template<>
//     struct is_integral<char16_t>
//     {
//       enum { __value = 1 };
//       typedef true_type type;
//     };

//   template<>
//     struct is_integral<char32_t>
//     {
//       enum { __value = 1 };
//       typedef true_type type;
//     };
// #endif

  template<>
    struct is_integral<short>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned short>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<int>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned int>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<long>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned long>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<long long>
    {
      enum { __value = 1 };
      typedef true_type type;
    };

  template<>
    struct is_integral<unsigned long long>
    {
      enum { __value = 1 };
      typedef true_type type;
    };



#endif

}