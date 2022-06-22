

#include "BST.hpp"
#include <iostream>
#include "map.hpp"
#include "utils.hpp"

#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

int main(int argc, char const *argv[])
{
    
     ft::map<int , std::string> mp;
    
    
    ft::pair<ft::map<int , std::string>::iterator ,bool>  p =  mp.insert( ft::pair<int,std::string>(42, "lol"));
    // std::cout << p.first.f << p.second << std::endl;
    printPair(p.first);

	// mp.insert( ft::pair<int,std::string>(42, "mdr"));
	// mp.insert( ft::pair<int,std::string>(50, "mdr2"));
	// mp.insert( ft::pair<int,std::string>(35, "funny"));

    // mp.print2D();
	// //   pouet.insert(ft::pair<int,int>(25, 1));
	// //  pouet.insert(ft::pair<int,int>(75, 2));
	// //  pouet.insert(ft::pair<int,int>(10, 0));
	// //  pouet.insert(ft::pair<int,int>(20, 0));
    // //  pouet.insert(ft::pair<int,int>(20, 1));

   
    
   

    //  ft::map<int , std::string>::iterator  it = mp.begin();
	//  ft::map<int , std::string>::iterator ite = mp.end();
    // // ft::map<int, int>::const_iterator cit = pouet.begin();
	// // ft::map<int, int>::const_iterator cite = pouet.end();

    // for (; it != ite; ++it)
    // {
    //     std::cout << it->first << " | "<< it->second << std::endl;
    // }
    
    // mp.print2D();

    //  ft::map<char , double> pouet;
    // pouet['a'] = 2.3;
	// pouet['b'] = 1.4;
	// pouet['c'] = 0.3;
	// pouet['d'] = 4.2;
    
    //  ft::map<char , double>::iterator itp = pouet.begin();
	//    ft::map<char , double>::iterator itep = pouet.end();
    // // ft::map<int, int>::const_iterator cit = pouet.begin();
	// // ft::map<int, int>::const_iterator cite = pouet.end();

    // for (; itp != itep; ++itp)
    // {
    //     std::cout << itp->first << " | "<< itp->second << std::endl;
    // }
     
    // ft::pair<int,int> tmp = ft::make_pair(100, 10);
    // tmp.first = 200;
   
    // std::cout << "itb: " << it->first <<  std::endl;
    // std::cout << "ite: " <<ite->first << std::endl;
    // std::cout << "citb: " <<cit->first <<  std::endl;
    // std::cout << "cite: " <<cite->first << std::endl << std::endl;

    // for (; it != ite; ++it)
	// 		std::cout << "- " << it->first << std::endl;

	//  pouet.print2D();
    // pouet.printinOrder();

	
    
	
    //ft::BST<std::string>::iterator it = bst.begin();
    
    // bst.insert("coucou");
    // bst.insert("pouic");
    // bst.insert("absolu");
    // bst.insert("abatre");
   
    // bst.inOrderTraversal();

    // std::cout << "Min value : " << bst.GetMin()->m_value << std::endl;
    // std::cout << "Max value : " << bst.GetMax()->m_value << std::endl;

     
    return 0;
}



