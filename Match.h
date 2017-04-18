/*
 *  Match.h
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/11/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#ifndef MATCH_H
#define MATCH_H

#include "Cube.h"
#include <vector>
#include <iostream>

class Match
{
private:
	
	
	
public:
	
	char letterOfWord;
	int matchingCube;
	
	Match(char x, int y);
	void showMatches();
	
};

#endif