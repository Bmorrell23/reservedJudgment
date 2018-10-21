#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <vector>

class Activity 
{
	public:
		virtual ~Activity() {}
		
		virtual void setName(const std::string& name) = 0;
		virtual void setDescription(const std::string& description) = 0;
		virtual void setScore(const std::string& score) = 0;
		virtual void setTag(const std::vector<std::string>& tag) = 0;
		virtual std::string name() const = 0;
		virtual std::string description() const = 0;
		virtual std::string score() const = 0;
		virtual std::vector<std::string> tags() const = 0;
		virtual std::string info() const = 0;
};

#endif //ACTIVITY_H
