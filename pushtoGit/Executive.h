/* -----------------------------------------------------------------------------
 *
 * File Name: Executive.h
 * Author: Blake Noble Morrell
 * KU ID: 2866535
 * Email Adress: blknm4598@ku.edu
 * Assignment:   EECS-268 Lab2
 * Description:  ___
 * Date: 9-18-2018
 *
 ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"


class Executive
{
public:

    //Constructor that handles only file intake
    Executive(std::string fileName);
    ~Executive();

    /** Runs a menu that handles file intake
     @pre  file must accessible through command line
     @post Called in main to execute entire program
     @param None  */
    void runMenus();

private:

  //input file read through command line.
  std::string browserfile;
  std::string movieName;
  std::string description;
  std::string rating;

};
#endif
