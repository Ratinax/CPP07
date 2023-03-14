#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define WHITEENDL   std::endl << WHITE
# define BLACK			"\033[0m\033[30m"
# define RED			"\033[0m\033[31m"
# define GREEN			"\033[0m\033[32m"
# define YELLOW			"\033[0m\033[33m"
# define BLUE			"\033[0m\033[34m"
# define MAGENTA		"\033[0m\033[35m"
# define CYAN			"\033[0m\033[36m"
# define WHITE			"\033[0m\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

template <typename T>
class	Array
{
	private:
		T 			*_tab;
		unsigned	int _size;
	public:
		Array(){_tab = NULL; _size = 0;};

		Array(unsigned int nb) : _size(nb)
		{
			if (_size > 0)
				_tab = new (std::nothrow)T[nb];
			else
				_tab = NULL;
			if (_tab == NULL)
				_size = 0;
		};

		Array(Array const &other) : _size(other._size)
		{
			if (_size > 0)
				_tab = new (std::nothrow)T[_size];
			else
				_tab = NULL;
			if (_tab == NULL)
				_size = 0;
			for (int i = 0; i < _size; i++)
				_tab[i] = other._tab[i];
		};

		Array &operator=(Array const &other)
		{
			if (_size > 0)
				delete [] _tab;
			_size = other._size;
			if (_size > 0)
				_tab = new (std::nothrow)T[_size];
			else
				_tab = NULL;
			if (_tab == NULL)
				_size = 0;
			for (int i = 0; i < _size; i++)
				_tab[i] = other._tab[i];
			return (*this);
		};

		~Array()
		{
			if (_size > 0)
				delete [] _tab;
		};

		T &operator[](unsigned int n)
		{
			if (n < _size)
				return (_tab[n]);
			throw(std::range_error("Array index out of range"));
		};

		unsigned int	size()
		{
			return (_size);
		};
};

#endif
