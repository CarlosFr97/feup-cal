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
	No(int id, long latitude, long longitude);
	virtual ~No();
	int getID();
};

#endif /* SRC_NO_H_ */
