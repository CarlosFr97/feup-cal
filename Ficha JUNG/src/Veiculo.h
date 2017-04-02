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
	bool disponivel;
	Vertex<No>* local;

public:
	Veiculo( Vertex <No>* local);
	virtual ~Veiculo();
	No getlocalNode() const;
	Vertex<No>* getLocal() const;
	bool getDisponibilidade() const;
	void setDisponibilidade(bool value);


};

#endif /* SRC_VEICULO_H_ */
