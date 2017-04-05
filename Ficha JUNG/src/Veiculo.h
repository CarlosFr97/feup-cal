/*
 * Veiculo.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */




#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include "Graph.h"
#include "No.h"

using namespace std;

class Veiculo {
private:
	unsigned int disponivel;
	No local;

public:
	Veiculo() {};
	Veiculo(No local);
	virtual ~Veiculo();
	No getlocalNode() const;
	void setlocalNode(No novoLocal);
	unsigned int getDisponibilidade() const;
	void setDisponibilidade(unsigned int value);
	void decDisponibilidade();


};

#endif /* SRC_VEICULO_H_ */
