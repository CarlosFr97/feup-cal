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
	emergencia.getCall(gv,11,1,0,0);
	//emergencia.displayGraph(gv);


	getchar();
	return 0;
}




