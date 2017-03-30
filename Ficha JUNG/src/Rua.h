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

using namespace std;


class Rua {
private:
	string nome;
	int ID;
	//devia ser vector<int> IDarestas e nao dos nos

	vector<int> IDarestas;
	bool twoways;

public:

	Rua(int ID, string nome, bool twoWays);
	virtual ~Rua();
	void setAresta(int IDaresta);
};

#endif /* SRC_RUA_H_ */
