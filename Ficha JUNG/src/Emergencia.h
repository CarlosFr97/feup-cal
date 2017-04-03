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
	vector<Vertex<No>*> hospitais;
	Graph<No> myGraph;
	int ID_ARESTA_GERAL;
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
	Emergencia();
	void readFiles();
	void readNos();
	void readArestas();
	void readRuas();
	void getCall(GraphViewer *gv,int noID,int polFlag,int bombFlag,int inemFlag);
	void displayGraph(GraphViewer *gv);
	virtual ~Emergencia();
	Vertex<No>* findNo(int id);
	No findINEM(Vertex<No>* localizacao);
	No findBomb(Vertex<No>* localizacao);
	No findPolicia(Vertex<No>* localizacao);
	void drawPath(GraphViewer *gv,vector<Edge<No>> &edgepath,string color);
	void drawNodes(GraphViewer *gv,vector<No> no,string color);
	void colorNodes(GraphViewer *gv) const;

};

#endif /* SRC_EMERGENCIA_H_ */
