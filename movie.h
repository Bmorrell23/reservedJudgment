#ifndef MOVIE_H
#define MOVIE_H

class Movie
{
	public:
		Movie();
		Movie(const std::string& name, const std::string& description, double score);
		void setName(const std::string& name);
		void setDescription(const std::string& description);
		void setScore(double score);
		std::string name() const;
		std::string description() const;
		double score() const;

	private:
		std::string name_;
		std::string description_;
		double score_;
};

#endif //MOVIE_H
