#include "activity.h"

Activity::Activity()
	: name_("")
	, description_("")
	, score_("")
	, tags_()
{

}

Activity::Activity(const std::string& name, const std::string& description, 
			  const std::string& score, const std::string& tags)
	: name_(name)
	, description_(description)
	, score_(score)
	, tags_()
{
	size_t spaceIndex = tags.find(" ");
	std::string tag   = "";
	std::string line  = tags;

	while(spaceIndex != std::string::npos)
	{
		tag = substrBefore(line, spaceIndex);
		line = substrAfter(line, spaceIndex);
		tags_.push_back(tag);
		spaceIndex = line.find(" ");
	}
}

void Activity::setName(const std::string& name)
{
	name_ = name;
}

void Activity::setDescription(const std::string& description)
{
	description_ = description;
}

void Activity::setScore(const std::string& score)
{
	score_ = score;
}

void Activity::setTag(const std::vector<std::string>& tags)
{
	tags_ = tags;
}

std::string Activity::name() const
{
	return name_;
}

std::string Activity::description() const
{
	return description_;
}

std::string Activity::score() const
{
	return score_;
}

std::vector<std::string> Activity::tags() const
{
	return tags_;
}

std::string Activity::info() const
{
	std::string rval = name_;
	rval += " ";
	rval += description_;
	rval += " ";
	rval += score_;
	rval += " ";
	
	for(auto s : tags_)
		rval = rval + " " + s;

	return rval;
	
}

std::string substrBefore(const std::string& s, size_t index)
{
	std::string rval = "";

	for(size_t i = 0; i < index; ++i)
		rval += s[i];

	return rval;
}

std::string substrAfter(const std::string& s, size_t index)
{
	std::string rval = "";

	for(size_t i = index + 1; i < s.size(); ++i)
		rval += s[i];

	return rval;
}
