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

void Freguesia::setIDRuaNo(int idRua, int idNo){
	IDNosRuas.insert(pair<int, int> (idRua, idNo));
}

Freguesia::~Freguesia() {
	// TODO Auto-generated destructor stub
}

multimap<int, int> Freguesia::getIDRuaNo(){
	return IDNosRuas;
}

string Freguesia::getNome()
{
	return this->nome;
}



