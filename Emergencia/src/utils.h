/*
 * time.h
 *
 *  Created on: 04/04/2017
 *      Author: up201503344
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_


#include <time.h>
#include <sys/timeb.h>
#include <sstream>

#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "No.h"
#include <stdio.h>
#include <fstream>
#include <string>

/**
 *
 */
int GetMilliCount();
/**
 *
 */
int GetMilliSpan(int nTimeStart);

vector<string> splitString(string rua);

string concatenateStrings(vector<string> vec, int num, int first_pos);

#endif /* SRC_UTILS_H_ */
