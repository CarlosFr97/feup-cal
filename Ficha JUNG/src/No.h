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
    int x;
    int y;
public:
    No(){};
	No(int id, long latitude, long longitude);
	virtual ~No();
	int getID();
	bool operator==(No no1) const;
	int getX();
	int getY();
};

#endif /* SRC_NO_H_ */
