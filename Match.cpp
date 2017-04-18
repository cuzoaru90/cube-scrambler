/*
 *  Match.cpp
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/11/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#include "Match.h"
#include "Cube.h"
#include <iostream>


Match::Match(char x, int y)
{

	letterOfWord = x;
	matchingCube = y;
	
}

void Match::showMatches()
{
	
std::cout << letterOfWord << " " << matchingCube <<  "\n";
		
	
}