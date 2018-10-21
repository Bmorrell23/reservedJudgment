#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <cstdlib>
#include "book.h"

class Generator
{
	public: 
		Generator(const std::vector<Book>& books);
		std::string generate() const;

	private:
		std::vector<Book> books_;
};

#endif //GENERATOR_H
