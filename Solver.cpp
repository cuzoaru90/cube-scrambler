/*
 *  Solver.cpp
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/10/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#include "Solver.h"
#include <iostream>


Solver::Solver()
{
    ;
}

void Solver::loopThroughCube(char x, Cube y)
{
	
	for (int i = 0; i < 6; i++)
		if ( x == y.sides[i] )
		{
			letterMatched = true;
			break;
		}
	
}


