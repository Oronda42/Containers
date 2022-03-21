
#include <memory>


namespace ft{

	// ---------------    ITERATORS    --------------- //



	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& > 
	struct iterator
	{

		typedef Category	iterator_category;
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;

		
	};

	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& > 
	struct reverse_iterator
	{

		typedef Category	iterator_category;
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;

	};

	template <class T> 
	class vector_iterator : ft::iterator< std::random_access_iterator_tag, T>
	{
		vector_iterator(int* T) : p(x) 
		{

		}
		vector_iterator(const vector_iterator& rhs) : p(rhs.p) 
		{
		}
		vector_iterator& operator++()
		{
			++p;return *this;
		}
		vector_iterator operator++(int) 
		{
			vector_iterator tmp(*this);
			operator++(); 
		 	return tmp;
		}
		bool operator==(const vector_iterator& rhs) const 
		{
			return p == rhs.p;
		}
		bool operator!=(const vector_iterator& rhs) const 
		{
			return p!=rhs.p;
		}
		vector_iterator& operator*() 
		{
			return *p;
		}

		vector_iterator& begin()
		{
			
		}


	};



	// ---------------    ITERATOR TRAITS    --------------- //

	template <class Iterator> class iterator_traits
	{
		typedef Iterator::difference_type difference_type;
		typedef Iterator::value_type value_type;
		typedef Iterator::pointer pointer;
		typedef Iterator::reference reference;
		typedef Iterator::iterator_category iterator_category;
	};
	template <class T> class iterator_traits<T*>
	{
		typedef T::difference_type ptrdiff_t;
		typedef T::value_type T;
		typedef T::pointer T*;
		typedef T::reference T&;
		typedef T::iterator_category std::random_access_iterator_tag;
	};
	template <class T> class iterator_traits<const T*>
	{
		typedef T::difference_type ptrdiff_t;
		typedef T::value_type T;
		typedef T::pointer const T*;
		typedef T::reference const T&;
		typedef T::iterator_category std::random_access_iterator_tag;
	};


	// ---------------    VECTOR    --------------- //

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		typedef	T 											value_type;
		typedef	Alloc 										allocator_type;
		typedef	allocator_type::reference 					reference;
		typedef	allocator_type::const_reference 			const_reference;
		typedef allocator_type::pointer						pointer;
		typedef allocator_type::const_pointer				const_pointer;
		typedef	ft::vector_iterator<T>						iterator;
		typedef	ft::vector_iterator<const T> 				const_iterator;
		typedef	ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	ft::const_reverse_iterator<const iterator>	const_reverse_iterator;
		typedef	ft::iterator_traits::difference_type		difference_type;
		typedef difference_type								size_type;

		vector(){}
		~vector(){}
		vector& operator=(vector& rhs){}

		//ITERATORS
		iterator& begin(){return iterator.begin()}
		iterator& end(){return iterator.end()}
		iterator& rbegin(){return iterator.rbegin()}
		iterator& rend(){return iterator.rend()}
		
	};
}