/*
 * No.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */

#ifndef SRC_NO_H_
#define SRC_NO_H_

#include <iostream>

class No {
private:
    int id;
    int x;
    int y;
public:
    No(){};
	No(int id, int x, int y);
	virtual ~No();
	int getID() const;
	bool operator==(const No &no1) const;
	bool operator<(const No &no1) const;
	int getX() const;
	int getY() const;
};

#endif /* SRC_NO_H_ */
