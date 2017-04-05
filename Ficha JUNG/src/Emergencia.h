
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
#include <stdio.h>
#include <iostream>
#include "graphviewer.h"
#include "Graph.h"
#include "Rua.h"
#include <math.h>
#include <fstream>
#include <algorithm>
#include "utils.h"



class Emergencia {

private:
	vector<Veiculo> INEM;
	vector<Veiculo> bombeiros;
	vector<Veiculo> policia;
	vector<Rua> ruas;
	vector<No> hospitais;
	Graph<No> myGraph;
	GraphViewer *gv;
	bool isFloydWarshall;
	int ID_ARESTA_GERAL;
	int tempoinicial;
	int tempofinal;
	short tempointermedio;
	/*tipos emergencia:
	 *
	 * 1 - assalto/acidente rodoviario simples/desentendimentos ou similares - Veiculos: Carro Policia
	 * 2 - Veiculos: Carro Policia + INEM
	 * 3 - Veiculos: Carro Bombeiros
	 * 4 - Veiculos: INEM simples
	 * 5 - Veiculos: INEM hospital
	 * 6 - Veiculos: Carro Policia + INEM + Carro Bombeiros
	 *
	 *
	 */

public:
	Emergencia(bool FloydWarshall);
	void readFiles();
	void readNos();
	void readArestas();
	void readRuas();
	void getCall(int noID,int polFlag,int bombFlag,int inemFlag, bool gotoHospital);
	bool VerificarConectividade();
	void displayGraph();
	virtual ~Emergencia();
	Vertex<No>* findNo(int id);
	No findElement(Vertex<No>* localizacao, vector<No> &pathnodes, char elementType);
	//No findINEM(Vertex<No>* localizacao, vector<No> &pathnodes);
	//No findBomb(Vertex<No>* localizacao);
	//No findPolicia(Vertex<No>* localizacao);
	vector<Edge<No> > moveToHospital(Vertex<No>* localizacao);
	void resetGV();
	void drawPath(vector<Edge<No> > &edgepath,string color,string icon);
	void colorNodes();
	void setFloydWarshall(bool value);

};

#endif /* SRC_EMERGENCIA_H_ */
