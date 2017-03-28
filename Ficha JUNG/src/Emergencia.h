/*
 * Emergencia.h
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */


#ifndef SRC_EMERGENCIA_H_
#define SRC_EMERGENCIA_H_

#include <vector>
#include "No.h"
#include "Bombeiros.h"
#include "Policia.h"


class Emergencia {
private:
	vector<Bombeiros> bombeiros;
	vector<Policia> policia;
	vector<No> hospitais;
public:
	Emergencia();
	void readFiles();
	virtual ~Emergencia();
};

#endif /* SRC_EMERGENCIA_H_ */
