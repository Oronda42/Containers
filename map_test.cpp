

#include "BST.hpp"
#include <iostream>
#include "map.hpp"


int main(int argc, char const *argv[])
{
    //ft::BST<std::string> bst;
    ft::map<std::string, int> pouet;
    
    pouet.insert(ft::make_pair("50", 0));
	pouet.insert(ft::make_pair("25", 1));
	pouet.insert(ft::make_pair("75", 2));
	pouet.insert(ft::make_pair("10", 0));
	pouet.insert(ft::make_pair("20", 0));
    pouet.insert(ft::make_pair("20", 1));
   

    ft::map<std::string, int>::iterator it = pouet.begin();
	ft::map<std::string, int>::iterator ite = pouet.end();
    ++it;
    --ite;

   
     std::cout << it->m_value.first <<  std::endl;
	 std::cout << ite->m_value.first << std::endl << std::endl;

	pouet.print2D();
    pouet.printinOrder();

	
    
	
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



