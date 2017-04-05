/*
 * Rua.h
 *
 *  Created on: 29/03/2017
 *      Author: up201503344
 */

#ifndef SRC_RUA_H_
#define SRC_RUA_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;


class Rua {
private:
	string nome;
	int ID;
	//devia ser vector<int> IDarestas e nao dos nos

	vector<int> IDnos;
	bool twoways;

public:

	Rua(int ID, string nome, bool twoWays);
	virtual ~Rua();
	void setNoID(int IDnos);
	vector<int> getNosID();
	int getRandNoID();
};

#endif /* SRC_RUA_H_ */
