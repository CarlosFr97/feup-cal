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
#include <map>
using namespace std;

class Freguesia {
private:
	string nome;
	int ID;



public:
	std::multimap<int, int> IDNosRuas;
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
	 * Adiciona ao multimap os ids de nos e ruas
	 * @param idRua inteiro que representa a key
	 * * @param idNo inteiro que representa o value
	 */
	void setIDRuaNo(int idRua, int idNo);
	/**
	 * Funcao que retorna o multimap que representao os Nos que pertencem a cada rua
	 * @return a variavel IDnos do objeto
	 */
	multimap<int, int> getIDRuaNo();
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
