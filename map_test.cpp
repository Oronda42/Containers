

#include "BST.hpp"
#include <iostream>
#include "map.hpp"
#include "utils.hpp"

#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator iterator;

static int iter = 0;


int main(int argc, char const *argv[])
{
    
     //ft::map<std::string, int> pouet;
    
    //  pouet.insert(ft::pair<int,int>(50, 0));
	//   pouet.insert(ft::pair<int,int>(25, 1));
	//  pouet.insert(ft::pair<int,int>(75, 2));
	//  pouet.insert(ft::pair<int,int>(10, 0));
	//  pouet.insert(ft::pair<int,int>(20, 0));
    //  pouet.insert(ft::pair<int,int>(20, 1));
   

    // ft::map<int, int>::iterator it = pouet.begin();
	// ft::map<int, int>::iterator ite = pouet.end();
    // ft::map<int, int>::const_iterator cit = pouet.begin();
	// ft::map<int, int>::const_iterator cite = pouet.end();

    
     
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



