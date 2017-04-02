/*
 * Veiculo.cpp
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#include "Veiculo.h"

Veiculo::Veiculo(Vertex<No>* local) : disponivel(true){
	this->local=local;

}

Veiculo::~Veiculo() {
	// TODO Auto-generated destructor stub
}

No Veiculo::getlocalNode() const
{
	return this->local->getInfo();
}

Vertex<No>* Veiculo::getLocal() const
{
	return this->local;
}

bool Veiculo::getDisponibilidade() const
{
	return disponivel;
}

void Veiculo::setDisponibilidade(bool value)
{
	this->disponivel = value;
}
