/*
 *  cube.cpp
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/9/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */


#include "Cube.h"
#include <iostream>

Cube::Cube(char sides [])
{
	setSides(sides);
	
}

void Cube::setSides(char x [])
{
	for (int i = 0; i < 6; i++) {
		sides[i] = x[i];
	}
	
}

void Cube::showSides()
{

	for (int i = 0; i < 6; i++) {
		std::cout << sides[i] << " ";
		
	}
	
}