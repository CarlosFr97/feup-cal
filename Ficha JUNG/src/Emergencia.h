
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


public:
	Emergencia(bool FloydWarshall);
	void readFiles();
	void readNos();
	void readArestas();
	void readRuas();
	void getCall(int noID,int polFlag,int bombFlag,int inemFlag, bool gotoHospital);
	/**
	 * Verifica se o Grafo que representa o mapa do programa, e conexo
	 * @return true se for conexo,caso contrario retorna false
	 */
	bool VerificarConectividade();
	/**
	 * Cria a partir do Grafo myGraph uma representacao visual do mesmo atraves do GraphViewer
	 */
	void displayGraph();
	/**
	 * Destrutor de Emergencia
	 */
	virtual ~Emergencia();
	Vertex<No>* findNo(int id);
	No findElement(Vertex<No>* localizacao, vector<No> &pathnodes, char elementType);

	vector<Edge<No> > moveToHospital(Vertex<No>* localizacao);
	/**
	 * Apos ser demonstrado  percurso no GraphViewer feito por um veiculo e preciso atualizar o estado dos Nos do mesmo e voltar a meter as arestas
	 * como se encontravam originalmente
	 */
	void resetGV();
	void drawPath(vector<Edge<No> > &edgepath,string color,string icon);
	/**
	 * Pinta cada No do grafo do graphViewer com o respetivo icone que representa cada local de forma
	 * percetivel
	 */
	void colorNodes();
	void setFloydWarshall(bool value);
	vector<Rua> getRuas();
	/**
	 * Desenha em cada aresta do grafo representado no graphviewer o nome da rua a que pertence
	 */
	void writeRuas();

};

#endif /* SRC_EMERGENCIA_H_ */
