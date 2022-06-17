

#include "BST.hpp"
#include <iostream>
#include "map.hpp"


int main(int argc, char const *argv[])
{
    //ft::BST<std::string> bst;
    ft::map<std::string, int> pouet;
     pouet.insert(ft::make_pair("xouic", 2));
     pouet.insert(ft::make_pair("prout", 1));
	 pouet.insert(ft::make_pair("coucou", 3));
	 pouet.insert(ft::make_pair("zemour", 5));
	 pouet.insert(ft::make_pair("asef", 10));

    ft::map<std::string, int>::iterator it = pouet.begin();
	ft::map<std::string, int>::iterator ite = pouet.end();

    std::cout << it->m_value.first << " " << it->m_value.second << std::endl;
	
	    std::cout << ite->m_value.first << " " << ite->m_value.second << std::endl;

	
    
	
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



