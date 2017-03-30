/*
 * No.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */

#include "No.h"

No::No(int id, long latitude, long longitude) {
	// TODO Auto-generated constructor stub

}

No::~No() {
	// TODO Auto-generated destructor stub
}

int No::getID(){
	return id;
}

bool No::operator==(No no1) const
		{
	return this->id == no1.getID();
		}
int No::getX(){
	return x;

}
int No::getY(){
	return y;

}
