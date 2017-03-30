/*
 * No.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */

#ifndef SRC_NO_H_
#define SRC_NO_H_

class No {
private:
    int id;
    long x;
    long y;
public:
    No(){};
	No(int id, long x, long y);
	virtual ~No();
	int getID();
	int getX();
	int getY();
	bool operator==(No no1) const ;
};

#endif /* SRC_NO_H_ */
