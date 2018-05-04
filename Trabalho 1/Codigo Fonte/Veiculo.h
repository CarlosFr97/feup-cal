/*
 * Veiculo.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */




#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include "Graph.h"
#include "No.h"

using namespace std;

class Veiculo {
private:
	unsigned int disponivel;
	No local;

public:

	/**
	 * Construtor default de um veiculo
	 */
	Veiculo() {};
	/**
	 * Um veiculo e representado unicamente pelo local em que se encontra (No especifico).Cada veiculo pode
	 * em qualquer altura se encontrar disponivel ou nao
	 * @param local No que representa o local onde se encontra o veiculo
	 */
	Veiculo(No local);
	/**
	 * Destrutor de um Veiculo
	 */
	virtual ~Veiculo();
	/**
	 * Retorna o local onde se encontra o veiculo
	 * @return o No local que representa o local do veiculo
	 */
	No getlocalNode() const;
	/**
	 * Altera o local do veiculo para o dado como parametro
	 * @param novoLocal o novo local onde se vai encontrar o veiculo
	 */
	void setlocalNode(No novoLocal);
	/**
	 * Retorna o valor que representa o numero de turnos que o veiculo ainda se vai encontrar indisponivel
	 * @return o valor de disponibilidade do Veiculo
	 */
	unsigned int getDisponibilidade() const;

	/**
	 * Altera o numero de turnos indisponiveis do veiculo para o dado como parametro
	 * @param value novo valor disponivel do objeto
	 */
	void setDisponibilidade(unsigned int value);
	/**
	 * Decrementa em um valor o numero de turnos em que o veiculo se encotrar indisponivel
	 */
	void decDisponibilidade();


};

#endif /* SRC_VEICULO_H_ */
