/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author: Blake Noble Morrell
 * Description:  Takes in data from a given file, stores data, prints to file
 * Date: 10-20-2018
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"


Executive::Executive(std::string fileName)
{
  browserfile = fileName;
  movieName = " ";
  description = " ";
  rating = " ";
}

void Executive::runMenus()
{

  std::ifstream inFile;
  inFile.open(browserfile);

  std::string line = " ";
  //int firstcomma = 0;

  while(!inFile.eof())
  {
    getline(inFile, line);
    if(line != "")
    {
      std::size_t firstbreak = line.find("'description'");
      movieName = line.substr(10, (firstbreak - 13));
      std::cout << movieName << "\n";

      std::size_t secondbreak = line.find("'score'");

      description = line.substr((firstbreak + 16),(secondbreak - (firstbreak + 19)));

      rating = line.substr(secondbreak + 9, 3);
      std::cout << rating << "\n" << description << "\n";
    }

  }
}

Executive::~Executive()
{

}
