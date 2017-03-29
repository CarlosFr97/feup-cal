/*
 * Rua.h
 *
 *  Created on: 29/03/2017
 *      Author: up201503344
 */

#ifndef SRC_RUA_H_
#define SRC_RUA_H_

#include <string>

using namespace std;


class Rua {
private:
	string nome;
	int ID;
	vector<int> IDnos;
	bool twoways;
public:
	Rua(long ID, string nome);
	virtual ~Rua();
	void setNo(int IDno);
};

#endif /* SRC_RUA_H_ */
