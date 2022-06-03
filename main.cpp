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



template<class T>
void print(T& x, std::string name = "")
{
	std::cout << name << " capacity = " << x.capacity() << std::endl;
	std::cout << name << " size = " << x.size() << std::endl;

	for (size_t i = 0; i < x.size(); i++)
		std::cout << x[i] << std::endl;
}

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	// std::cout <<  "/////////// INT PUSH POP //////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<int> vec;
	// 	vec.push_back(10);
	// 	vec.push_back(11);
	// 	vec.push_back(12);
	// 	vec.push_back(13);
	// 	vec.pop_back();
	// 	print(vec, "vec");
		
	// }
	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	ft::vector<int> vec;
	// 	vec.push_back(10);
	// 	vec.push_back(11);
	// 	vec.push_back(12);
	// 	vec.push_back(13);
	// 	vec.pop_back();
	// 	print(vec, "vec");
	// }
	// //////////////////////////////////////////////////////////////////////////////////////////////////////

	// std::cout <<  "///////////// STRING PUSH POP/////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<std::string> vec;
	// 	vec.push_back("coucou");
	// 	vec.push_back("c'est");
	// 	vec.push_back("moi");
	// 	vec.push_back("toto");
	// 	vec.pop_back();
	// 	print(vec);
	// }

	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	ft::vector<std::string> vec;
	// 	vec.push_back("coucou pouet pouet");
	// 	vec.push_back("c'est");
	// 	vec.push_back("moi");
	// 	vec.push_back("toto");
	// 	vec.pop_back();
	// 	print(vec);
		
	// }

	// std::cout <<  "/////////// FILL CONSTRUCTOR //////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<int> vec(5,10);
	// 	vec.push_back(11);
	// 	std::cout <<  "capacity = " << vec.capacity() << std::endl;
	// 	std::cout <<  "size = " << vec.size() << std::endl;
	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// 	std::cout << "begin = "<< *(vec.begin()) << std::endl;
	// 	std::cout << "end -1  = "<< *(vec.end() -1) << std::endl;
	// }
	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	ft::vector<int> vec(5,10);
	// 	vec.push_back(11);
	// 	std::cout <<  "capacity = " << vec.capacity() << std::endl;
	// 	std::cout <<  "size = " << vec.size() << std::endl;
	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// 	std::cout << "begin = "<< *(vec.begin()) << std::endl;
	// 	std::cout << "end -1  = "<< *(vec.end() -1) << std::endl;
		
	// }

	// std::cout <<  "/////////// INT COPY CONSTRUCTOR //////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<int> vec(5,10);
	// 	std::vector<int> vec2(vec); // COPY
	// 	vec.push_back(1);
	// 	vec2.push_back(2);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	ft::vector<int> vec(5,10);
	// 	ft::vector<int> vec2(vec); // COPY
	// 	vec.push_back(1);
	// 	vec2.push_back(2);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }

	// std::cout <<  "///////////// STRING COPY CONSTRUCTOR /////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<std::string> vec;
	// 	vec.push_back("coucou");
	// 	vec.push_back(" c'est");
	// 	vec.push_back(" moi");
	// 	vec.push_back(" toto");
	// 	std::vector<std::string> vec2(vec);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }

	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	std::vector<std::string> vec;
	// 	vec.push_back("coucou");
	// 	vec.push_back(" c'est");
	// 	vec.push_back(" moi");
	// 	vec.push_back(" toto");
	// 	std::vector<std::string> vec2(vec);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }

	// std::cout <<  "/////////// FILL CONSTRUCTOR //////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<int> vec;
	// 	for (size_t i = 1; i < 5; i++)
	// 		vec.push_back(i);
	// 	print(vec,"vec");
	// 	std::vector<int>::iterator iteratorBegin = vec.begin();
	// 	std::vector<int>::iterator iteratorEnd = vec.end();
	// 	std::vector<int> vec2(iteratorBegin,iteratorEnd);
	// 	print(vec2,"vec2");
	// }
	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	ft::vector<int> vec;
	// 	for (size_t i = 1; i < 5; i++)
	// 		vec.push_back(i);
	// 	print(vec,"vec");
	// 	ft::vector<int>::iterator iteratorBegin = vec.begin();
	// 	ft::vector<int>::iterator iteratorEnd = vec.end();
	// 	ft::vector<int> vec2(iteratorBegin,iteratorEnd);
	// 	print(vec2,"vec2");
	// }

	// std::cout <<  "///////////// STRING RANGE CONSTRUCTOR /////////// " << std::endl;
	// {
	// 	std::cout <<  "** ORIGINAL **" << std::endl;
	// 	std::vector<std::string> vec;
	// 	vec.push_back("coucou");
	// 	vec.push_back("c'est");
	// 	vec.push_back("moi");
	// 	vec.push_back("toto");
	// 	std::vector<std::string>::iterator iteratorBegin = vec.begin();
	//  	std::vector<std::string>::iterator iteratorEnd = vec.end();
	// 	std::vector<std::string> vec2(iteratorBegin,iteratorEnd);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }

	// {
	// 	std::cout <<  "** FT **" << std::endl;
	// 	ft::vector<std::string> vec;
	// 	vec.push_back("coucou");
	// 	vec.push_back("c'est");
	// 	vec.push_back("moi");
	// 	vec.push_back("toto");
	// 	ft::vector<std::string>::iterator iteratorBegin = vec.begin();
	//  	ft::vector<std::string>::iterator iteratorEnd = vec.end();
	// 	ft::vector<std::string> vec2(iteratorBegin,iteratorEnd);
	// 	print(vec, "vec");
	// 	print(vec2, "vec2");
	// }

	//INSERT single element 

	// ft::vector<int> vec(6);

	// for (unsigned long int i = 1; i < vec.size(); ++i)
	// 	vec[i] = i ;
	// print(vec);
	// vec.insert(vec.end() - 3 , 0);
	// print(vec);

	//INSERT fill 
	// ft::vector<int> vec(5);

	// for (unsigned long int i = 1; i < vec.size(); ++i)
	// 	vec[i] = i ;
	// print(vec);
	// vec.insert(vec.end() - 2,  3, -1);
	// print(vec);

	//range  
	// ft::vector<int> vec(5);

	// for (unsigned long int i = 1; i < vec.size(); ++i)
	// 	vec[i] = i ;
	
	// vec.insert(vec.end() -1 , -1);
	// print(vec);
	// std::vector<int> anothervector (2,400);
	// vec.insert(vec.begin() +  2, anothervector.begin(),anothervector.end());
	// print(vec);

	ft::vector<int> vec(10);
	ft::vector<int> vec2;

	for (unsigned long int i = 0; i < vec.size(); ++i)
		vec[i] = (vec.size() - i) * 3;
	print(vec);

	vec.push_back(21);
	vec.push_back(42);
	vec.push_back(21);
	vec.push_back(42);


	vec2.insert(vec2.begin() + 2, vec.begin(), vec.end());
	vec.clear();
	print(vec2);

	print(vec);
	

	return 0;
}


