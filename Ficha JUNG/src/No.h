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
    long latitude;
    long longitude;
public:
	No(int id, long latitude, long longitude);
	virtual ~No();
};

#endif /* SRC_NO_H_ */
