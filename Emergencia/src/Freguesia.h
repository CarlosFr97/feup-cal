/*
 * Freguesia.h
 *
 *  Created on: 14/05/2017
 *      Author: Rui Quaresma
 */

#ifndef SRC_FREGUESIA_H_
#define SRC_FREGUESIA_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Freguesia {
private:
	string nome;
	int ID;
	vector<int> IDnos;

public:

	/**
	 * Construtor de um objeto do tipo freguesia. Uma freguesia e caraterizada por um nome especifico e um ID, para cada freguesia,
	 * e guardados identificadores de todos os nos que representam essa freguesia.
	 * @param ID identificador de uma rua
	 * @param nome que representa a rua
	 */
	Freguesia(int ID, string nome);
	/**
	 * Destrutor default de uma Rua
	 */
	virtual ~Freguesia();
	/**
	 * Adiciona ao vetor de identificadores de nos com o valor dado como parametro
	 * @param IDnos inteiro a ser adicionado ao vetor IDnos
	 */
	void setNoID(int IDnos);
	/**
	 * Funcao que retorna o vetor que representao os Nos que pertencem a rua
	 * @return a variavel IDnos do objeto
	 */
	vector<int> getNosID();
	/**
	 * Devolve o nome da rua
	 * @return a variavel nome do objeto
	 */
	string getNome();
	/**
	 *Retorna,aleatoriamente um identificador de um no que pertence a rua
	 *@return o valor aleatorio do vetor nosID
	 */
	int getRandNoID();
};




#endif /* SRC_FREGUESIA_H_ */
