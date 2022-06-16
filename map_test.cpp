

#include "BST.hpp"
#include <iostream>
#include "map.hpp"


int main(int argc, char const *argv[])
{
    //ft::BST<std::string> bst;
    ft::map<std::string, int> pouet;
     pouet.insert(ft::make_pair("pouic", 1));
    // pouet.insert(ft::make_pair("pouet", 2));

    ft::map<std::string, int>::iterator it = pouet.begin();

    std::cout << it->m_value.first << " " << it->m_value.second << std::endl;
    
	
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



