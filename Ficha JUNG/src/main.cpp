/*
 * main.cpp
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#include "Emergencia.h"
#include "Menu.h"

int main()
{
	//GraphViewer *gv = new GraphViewer(600, 600, false);
	Emergencia emergencia(true);
	emergencia.readFiles();
	emergencia.displayGraph();
	menu_principal(emergencia);
	//emergencia.getCall(20,1,1,1);



	getchar();
	return 0;
}




