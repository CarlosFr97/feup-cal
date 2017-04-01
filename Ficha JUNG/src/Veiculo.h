/*
 * Veiculo.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */




#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include "No.h"

using namespace std;

class Veiculo {
private:
	bool disponivel;
	No local;

public:
	Veiculo(No local);
	virtual ~Veiculo();
	No getLocal() const ;


};

#endif /* SRC_VEICULO_H_ */
