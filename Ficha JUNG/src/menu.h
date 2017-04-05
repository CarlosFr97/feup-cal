/*
 * menu.h
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdio>
#include <algorithm>
#include "Emergencia.h"
#include <string>

#define CLEAN_LINE "                                                                                 "
using namespace std;

void menu_principal(Emergencia &em);
void tipoEmergencia(Emergencia &em);
void emLevel(Emergencia &em,int typeFlag);
int chooseRua(Emergencia &em);
bool chooseAlgorithm();
void gotoXY(int x,int y);



#endif /* SRC_MENU_H_ */
