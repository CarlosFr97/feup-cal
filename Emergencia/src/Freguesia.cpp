/*
 * Freguesia.cpp
 *
 *  Created on: 14/05/2017
 *      Author: Rui Quaresma
 */


#include "Freguesia.h"

Freguesia::Freguesia(int ID, string nome) {
	this->ID=ID;
	this->nome=nome;

}

void Freguesia::setNoID(int IDno){
	IDnos.push_back(IDno);
}

Freguesia::~Freguesia() {
	// TODO Auto-generated destructor stub
}

vector<int> Freguesia::getNosID(){
	return IDnos;
}

string Freguesia::getNome()
{
	return this->nome;
}

int Rua::getRandNoID(){
	srand(time(NULL));

	return IDnos[rand()%IDnos.size()];
}



