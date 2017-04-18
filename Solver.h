/*
 *  Solver.h
 *  c++
 *
 *  Created by Chuk Uzoaru on 11/10/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#ifndef SOLVER_H
#define SOLVER_H

#include "Cube.h"
#include <vector>

class Solver
{
private:
	
	
	
public:
	
	bool letterMatched;
	
	Solver();
	void loopThroughCube(char x, Cube y);
	
};

#endif