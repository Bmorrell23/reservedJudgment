#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <string>
#include <vector>

class Activity
{
    public:

        Activity();
        Activity(const std::string& name, const std::string& description,
              const std::string& score, const std::string& tags);
        ~Activity() {}

        void setName(const std::string& name);
        void setDescription(const std::string& description);
        void setScore(const std::string& score);
        void setTag(const std::vector<std::string>& tag);
        std::string name() const;
        std::string description() const;
        std::string score() const;
        std::vector<std::string> tags() const;
        std::string info() const;
    private:
        std::string name_;
        std::string description_;
        std::string score_;
        std::vector<std::string> tags_;
};

std::string substrBefore(const std::string& s, size_t index );
std::string substrAfter(const std::string& s, size_t index);

#endif //ACTIVITY_H
