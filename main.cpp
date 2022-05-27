/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:10:55 by oronda            #+#    #+#             */
/*   Updated: 2022/05/21 23:45:01 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "vector.hpp"
#include <vector>
#include <iostream>
//#include <vector>

int main(int argc, char const *argv[])
{
	 
	// {
	// 	std::vector<int> vec;
	// 	vec.push_back(10);
	// 	vec.push_back(11);
	// 	vec.push_back(12);
	// 	vec.push_back(13);
	// 	std::cout <<  "capacity = " << vec.capacity() << std::endl;
	// 	std::cout <<  "size = " << vec.size() << std::endl;

	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// }

	// {
	// 	ft::vector<int> vec;
	// 	vec.push_back(10);
	// 	vec.push_back(11);
	// 	vec.push_back(12);
	// 	vec.push_back(13);
	// 	std::cout <<  "capacity = " << vec.capacity() << std::endl;
	// 	std::cout <<  "size = " << vec.size() << std::endl;

	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// }
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	{
		std::vector<std::string> vec;
		std::vector<int>::iterator
		vec.push_back("10");
		vec.push_back("11");
		vec.push_back("12");
		vec.push_back("13");
		std::cout <<  "capacity = " << vec.capacity() << std::endl;
		std::cout <<  "size = " << vec.size() << std::endl;

		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << std::endl;
	}

	{
		ft::vector<std::string> vec;
		vec.push_back("10");
		vec.push_back("11");
		vec.push_back("12");
		vec.push_back("13");
		std::cout <<  "capacity = " << vec.capacity() << std::endl;
		std::cout <<  "size = " << vec.size() << std::endl;

		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << std::endl;
	}

	return 0;
}
