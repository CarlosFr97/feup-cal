/*
 * Rua.cpp
 *
 *  Created on: 29/03/2017
 *      Author: up201503344
 */

#include "Rua.h"

Rua::Rua(int ID, string nome, bool twoWays) {
	this->ID=ID;
	this->nome=nome;
	this->twoways=twoWays;

}

void Rua::setAresta(int IDaresta){
	IDarestas.push_back(IDaresta);
}

Rua::~Rua() {
	// TODO Auto-generated destructor stub
}

