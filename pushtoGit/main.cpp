/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Blake Noble Morrell
 * KU ID: 2866535
 * Email Adress: blknm4598@ku.edu
 * Assignment:   EECS-268 Lab2
 * Description:  ___
 * Date: 9-18-2018
 *
 ---------------------------------------------------------------------------- */
 #include <iostream>
 #include <fstream>
 #include "Executive.h"

 int main(int argc, char* argv[])
 {
   if(argc < 2)
   {
     std::cout << "Incorrect number of parameters!\n";
   }
   else
   {

      Executive exec(argv[1]);
      exec.runMenus();
   }

 return(0);
 }
