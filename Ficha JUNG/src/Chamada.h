/*
 * Chamada.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#ifndef SRC_CHAMADA_H_
#define SRC_CHAMADA_H_

#include <string>


class Chamada {
private:
	string tipoOcorrencia;
	int localidade;

public:
	Chamada();
	virtual ~Chamada();
};

#endif /* SRC_CHAMADA_H_ */
