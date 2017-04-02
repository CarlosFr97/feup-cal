/*
 * main.cpp
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#include "Emergencia.h"

int main()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);
	Emergencia emergencia;
	emergencia.readFiles();
	emergencia.displayGraph(gv);
	emergencia.getCall(gv,20,1,1,1);

	getchar();
	return 0;
}




