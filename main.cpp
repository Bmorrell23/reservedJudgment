#include <iostream>
#include "movie.h"

int main()
{
	Movie m("James Bond", "Bad ass shit.", "7.5", { "Action" });
	
	std::cout << m.info() << std::endl;

	return 0;
}
