/*
 *  cube.h
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/9/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */
#include <iostream>

#ifndef CUBE_H
#define CUBE_H

class Cube
{
private:
	
    Cube() { }; // private default constructor
	
public:
	
	char sides[6];
	
    Cube(char sides []);
	
    void setSides(char x []);
	
	void showSides();
};

#endif