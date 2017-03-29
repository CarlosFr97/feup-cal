/*
 * Emergencia.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */


#ifndef SRC_EMERGENCIA_H_
#define SRC_EMERGENCIA_H_

#include <vector>
#include "No.h"
#include "graphviewer.h"


class Emergencia {
private:
	vector<Veiculo> INEM;
	vector<Veiculo> bombeiros;
	vector<Veiculo> policia;
	vector<No> hospitais;
	Graph<No> myGraph;

public:
	Emergencia();
	void readFiles();
	virtual ~Emergencia();
};

#endif /* SRC_EMERGENCIA_H_ */
