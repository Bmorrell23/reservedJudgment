#include "movie.h"

Movie::Movie()
	: name_("")
	, description_("")
	, score_(0)
{

}

Movie::Movie(const std::string& name, const std::string& description, const std::string& score)
	: name_(name)
	, description_(description)
	, score_(score)
{

}

void Movie::setName(const std::string& name)
{
	name_ = name;
}

void Movie::setDescription(const std::string& description)
{
	description_ = description;
}

void Movie::setScore(double score)
{
	score_ = score;
}

std::string Movie::name() const
{
	return name_;
}

std::string Movie::description() const
{
	return description_;
}

std::string Movie::score() const
{
	return score_;
}
