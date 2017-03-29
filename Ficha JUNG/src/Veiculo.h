/*
 * Veiculo.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */




#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>

using namespace std;

class Veiculo {
private:
	bool disponivel;
	No local;

public:
	Veiculo(No local);
	virtual ~Veiculo();


};

#endif /* SRC_VEICULO_H_ */
