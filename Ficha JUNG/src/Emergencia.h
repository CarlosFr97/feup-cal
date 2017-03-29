/*
 * Emergencia.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */


#ifndef SRC_EMERGENCIA_H_
#define SRC_EMERGENCIA_H_

#include <vector>
#include <Veiculo.h>
#include "No.h"
#include <sstream>
#include <iostream>
#include "graphviewer.h"


class Emergencia {
private:
	vector<Veiculo> INEM;
	vector<Veiculo> bombeiros;
	vector<Veiculo> policia;
	vector<Rua> ruas;
	vector<No> hospitais;
	Graph<No> myGraph;

public:
	Emergencia();
	void readFiles();
	void readNos();
	void readArestas();
	void readRuas();
	virtual ~Emergencia();
	No findNo(int id);
};

#endif /* SRC_EMERGENCIA_H_ */
