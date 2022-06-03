
#include <memory>

namespace ft{

	template <class Iterator>
	struct iterator_traits 
	{
		typedef typename Iterator::difference_type		difference_type; 
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	// template <class T>
	// struct iterator_traits<T*> 
	// {
	// 	typedef ptrdiff_t	difference_type; 
	// 	typedef T			value_type;
	// 	typedef T*			pointer;
	// 	typedef T&			reference;
	// 	typedef typename ft::random_access_iterator_tag	iterator_category; 
	// };

	// template <class T>
	// struct iterator_traits<const T*>
	// {
	// 	typedef ptrdiff_t	difference_type;
	// 	typedef T			value_type;
	// 	typedef T*			pointer;
	// 	typedef T&			reference;
	// 	typedef typename ft::random_access_iterator_tag	iterator_category;
	// };
	
  struct input_iterator_tag {};
  struct output_iterator_tag {};
  struct forward_iterator_tag : public input_iterator_tag {};
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};


template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

template <class T> 
class random_access_iterator :  public ft::iterator<ft::random_access_iterator_tag, T>
{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;

		random_access_iterator() : _ptr(NULL) {}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator& src) : _ptr(src._ptr) {}
		virtual ~random_access_iterator() {}

		template<typename U>
  		random_access_iterator(random_access_iterator<U>);

		pointer base() const
		{
			return _ptr; 
		}

		random_access_iterator &operator=(const random_access_iterator& src)
		{
			_ptr = src._ptr;
			return *this;
		}

		random_access_iterator& operator++() 
		{
			++_ptr;
			return *this;
		}

		random_access_iterator operator++(int) 
		{
			random_access_iterator temp(*this); 
			operator++(); 
			return temp;
		}

		random_access_iterator& operator--() 
		{
			--_ptr;
			return *this;
		}

		random_access_iterator operator--(int) 
		{
			random_access_iterator temp(*this); 
			operator--(); 
			return temp;
		}

		bool operator==(const random_access_iterator& src) const 
		{
			 return _ptr==src._ptr;
		}
		
		bool operator!=(const random_access_iterator& src) const 
		{
			return _ptr!=src._ptr;
		}

		reference operator*() const
		{
			return *_ptr;
		}
		

		random_access_iterator operator-(difference_type diff) const
		{
			return _ptr - diff;
		}

		random_access_iterator operator+( difference_type diff)
		{
			return _ptr + diff;
		}

		difference_type operator-(random_access_iterator it)
		{
			return _ptr - it.base();
		}

		difference_type operator+(random_access_iterator it)
		{
			return _ptr + it.base();
		}

		random_access_iterator& operator+=( difference_type diff)
		{
			_ptr += diff;
			return *this;
		}

		random_access_iterator& operator-=( difference_type diff)
		{
			_ptr -= diff;
			return *this;
		}

		pointer operator->() const
		{
			return &(*_ptr);
		}

		reference operator[](difference_type diff) const
		{ 
			return *(_ptr + diff); 
		}
		
	private:
		pointer _ptr;
};

	// random_access_iterator() :  _ptr(NULL)
	// {
	// }
	// random_access_iterator(pointer ptr) : _ptr(ptr)
	// {
	// }

	// random_access_iterator(const random_access_iterator& src)
	// {
	// 	*this = src;
	// }

	// ~random_access_iterator(){}

	// random_access_iterator& operator++()
	// {
	// 	++_ptr;
	// 	return *this;
	// }
	// random_access_iterator operator++(int) 
	// {
	// 	random_access_iterator tmp(*this);
	// 	operator++(); 
	//  	return tmp;
	// }
	// bool operator==(const random_access_iterator& src) const 
	// {
	// 	return _ptr == src._ptr;
	// }
	// bool operator!=(const random_access_iterator& src) const 
	// {
	// 	return _ptr!=src._ptr;
	// }

	// random_access_iterator& operator*() 
	// {
	// 	return *_ptr;
	// }

	// reference operator[](difference_type n)
	// {
	// 	return _ptr[n];
	// }

	// private :
	// 	T* _ptr;
};





