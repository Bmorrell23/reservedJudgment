#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie
{
	public:
		Movie();
		Movie(const std::string& name, const std::string& description, const std::string& score);
		void setName(const std::string& name);
		void setDescription(const std::string& description);
		void setScore(double score);
		std::string name() const;
		std::string description() const;
		std::string score() const;

	private:
		std::string name_;
		std::string description_;
		std::string score_;
};

#endif //MOVIE_H
