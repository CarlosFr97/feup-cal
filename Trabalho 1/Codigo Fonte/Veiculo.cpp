/*
 * Veiculo.cpp
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#include "Veiculo.h"

Veiculo::Veiculo(No local) : disponivel(0){
	this->local=local;

}

Veiculo::~Veiculo() {
	// TODO Auto-generated destructor stub
}

No Veiculo::getlocalNode() const
{
	return this->local;
}

void Veiculo::setlocalNode(No novoLocal){
	this->local = novoLocal;
}


unsigned int Veiculo::getDisponibilidade() const
{
	return disponivel;
}

void Veiculo::setDisponibilidade(unsigned int value)
{
	this->disponivel = value;
}

void Veiculo::decDisponibilidade(){
	if(disponivel > 0)
		disponivel--;
}
