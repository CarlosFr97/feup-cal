/*
 * Emergencia.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */


#ifndef SRC_EMERGENCIA_H_
#define SRC_EMERGENCIA_H_

#include <vector>
#include "Veiculo.h"
#include "No.h"
#include <sstream>
#include <iostream>
#include "graphviewer.h"
#include "Graph.h"
#include "Rua.h"
#include <math.h>
#include <fstream>



class Emergencia {
private:
	vector<Veiculo> INEM;
	vector<Veiculo> bombeiros;
	vector<Veiculo> policia;
	vector<Rua> ruas;
	vector<No> hospitais;
	Graph<No> myGraph;
	int ID_ARESTA_GERAL;

public:
	Emergencia();
	void readFiles();
	void readNos();
	void readArestas();
	void readRuas();
	void displayGraph();
	virtual ~Emergencia();
	Vertex<No>* findNo(int id);
	//static int ID_ARESTA_GERAL;
};

#endif /* SRC_EMERGENCIA_H_ */
