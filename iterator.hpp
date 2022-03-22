
#include <memory>

namespace ft {


template < 
class Category, 
class T, 
class Distance = std::ptrdiff_t, 
class Pointer = T*, 
class Reference = T& > 
struct iterator
{
	
	typedef Category	iterator_category;
	typedef	T			value_type;
	typedef	Distance	difference_type;
	typedef	Pointer		pointer;
	typedef	Reference	reference;
	
};

template < 
class Category, 
class T, 
class Distance = std::ptrdiff_t, 
class Pointer = T*, 
class Reference = T& > 
struct reverse_iterator
{

	typedef Category	iterator_category;
	typedef	T			value_type;
	typedef	Distance	difference_type;
	typedef	Pointer		pointer;
	typedef	Reference	reference;

	// TODO

};

template <class T> 
class random_iterator : ft::iterator< std::random_access_iterator_tag, T>
{

	random_iterator(T* ptr) : _ptr(ptr)
	{
	}

	// random_iterator(const random_iterator& rhs) : p(rhs.p) 
	// {
	// }
	// vector_iterator& operator++()
	// {
	// 	++p;return *this;
	// }
	// vector_iterator operator++(int) 
	// {
	// 	vector_iterator tmp(*this);
	// 	operator++(); 
	//  	return tmp;
	// }
	// bool operator==(const vector_iterator& rhs) const 
	// {
	// 	return p == rhs.p;
	// }
	// bool operator!=(const vector_iterator& rhs) const 
	// {
	// 	return p!=rhs.p;
	// }
	// vector_iterator& operator*() 
	// {
	// 	return *p;
	// }

	
	private :
		T* _ptr;

};


// template <class Iterator> class iterator_traits
// {
// 	typedef typename Iterator::difference_type difference_type;
// 	typedef typename Iterator::value_type value_type;
// 	typedef typename Iterator::pointer pointer;
// 	typedef typename Iterator::reference reference;
// 	typedef typename Iterator::iterator_category iterator_category;
// };
// template <class T> class iterator_traits<T*>
// {
// 	typedef typename T::difference_type ptrdiff_t;
// 	typedef typename T::value_type T;
// 	typedef typename T::pointer T*;
// 	typedef typename T::reference T&;
// 	typedef typename T::iterator_category std::random_access_iterator_tag;
// };
// template <class T> class iterator_traits<const T*>
// {
// 	typedef T::difference_type ptrdiff_t;
// 	typedef T::value_type T;
// 	typedef T::pointer const T*;
// 	typedef T::reference const T&;
// 	typedef T::iterator_category std::random_access_iterator_tag;
// };


}
