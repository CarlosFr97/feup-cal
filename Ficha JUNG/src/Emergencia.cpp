/*
 * Emergencia.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */

#include "Emergencia.h"

Emergencia::Emergencia() {

}

Emergencia::~Emergencia() {

}

No Emergencia::findNo(int id){

	vector< Vertex<No>* > vertices = myGraph.getVertexSet();
	for (unsigned int i = 0; i < vertices.size(); i++){
		if(vertices.at(i)->getInfo().getID()==id)
			return vertices.at(i);

	}

}

void Emergencia::readFiles(){

	ifstream inFile;
	std::string line;

	long long int idNo=0;
	float X=0;
	float Y=0;
	char token;

	//Ler o ficheiro nosNormals.txt
	inFile.open("nos.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idNo>>token>>X>>token>>Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);


	}

	inFile.close();

	//Ler o ficheiro hospitalNos.txt
	inFile.open("hospitais.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idNo>>token>>X>>token>>Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		hospitais.push_back(n);


	}

	inFile.close();

	//Ler o ficheiro inemNos.txt
	inFile.open("INEM.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idNo>>token>>X>>token>>Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		INEM.push_back(n);


	}

	inFile.close();

	//Ler o ficheiro bombeirosNos.txt
	inFile.open("bombeiros.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idNo>>token>>X>>token>>Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		bombeiros.push_back(n);


	}

	inFile.close();

	//Ler o ficheiro policiaNos.txt
	inFile.open("policia.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idNo>>token>>X>>token>>Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		policia.push_back(n);


	}

	inFile.close();

	int idRua=0;
	int idAresta=0;
	int idNo1=0, idNo2=0;

	//Ler o ficheiro arestas.txt
	inFile.open("arestas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idAresta>>token>>idNo1>>token>>idNo2;

		/*
		No n(idNo, X, Y);

		myGraph.addEdge(n);
		 */


	}

	inFile.close();

	string nomeRua,twoWays;


	//Ler o ficheiro ruas.txt
	inFile.open("ruas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}


	while(getline(inFile, line))
	{

		std::stringstream linestream(line);

		linestream >> idRua>>token;
		getline(linestream, nomeRua, ';');
		linestream>>twoWays>>token;
		Rua r(idRua, nomeRua, (twoWays.compare("True") ? true : false));
		while(token!='\n'){
			linestream>>idNo>>token;
			r.setNo(idNo);
		}

		ruas.push_back(r);


	}

	inFile.close();

}



