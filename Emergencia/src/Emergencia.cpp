
#include "Emergencia.h"
#include "Rua.h"
#include "Graph.h"

using namespace std;

Emergencia::Emergencia(bool FloydWarshall) {
	ID_ARESTA_GERAL = 1;
	gv = new GraphViewer(600, 600, false);
	isFloydWarshall = FloydWarshall;
	tempoinicial = 0;
	tempofinal = 0;
	tempointermedio = 0;
}

Emergencia::~Emergencia() {

}

Vertex<No>* Emergencia::findNo(int id) {

	vector<Vertex<No>*> vertices = myGraph.getVertexSet();
	for (unsigned int i = 0; i < vertices.size(); i++) {
		if (vertices.at(i)->getInfo().getID() == id)
			return vertices.at(i);

	}

	return NULL;

}

void Emergencia::readFiles() {

	ifstream inFile;
	std::string line;

	long long int idNo = 0;
	float X = 0;
	float Y = 0;
	char token;

	//Ler o ficheiro nosNormals.txt
	inFile.open("nos.txt");

	if (!inFile) {
		cerr << "Unable to open file nos.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;
		No n(idNo, X, Y);
		myGraph.addVertex(n);

	}

	inFile.close();

	//Ler o ficheiro hospitalNos.txt
	inFile.open("hospitais.txt");

	if (!inFile) {
		cerr << "Unable to open file hospitais.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		hospitais.push_back(n);

	}

	inFile.close();

	//Ler o ficheiro inemNos.txt
	inFile.open("INEM.txt");

	if (!inFile) {
		cerr << "Unable to open file INEM.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		INEM.push_back(v);

	}

	inFile.close();

	//Ler o ficheiro bombeirosNos.txt
	inFile.open("bombeiros.txt");

	if (!inFile) {
		cerr << "Unable to open file bombeiros.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		bombeiros.push_back(v);

	}

	inFile.close();

	//Ler o ficheiro policiaNos.txt
	inFile.open("policia.txt");

	if (!inFile) {
		cerr << "Unable to open file policia.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		Veiculo v(n);
		policia.push_back(v);

	}

	inFile.close();

	string nomeRua, twoWays;
	int NoID, idRua;

	//Ler o ficheiro ruas.txt
	inFile.open("ruas.txt");

	if (!inFile) {
		cerr << "Unable to open file ruas.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idRua >> token;
		getline(linestream, nomeRua, ';');
		getline(linestream, twoWays, ';');

		Rua r(idRua, nomeRua, ((twoWays == "True") ? true : false));
		do {
			linestream >> NoID >> token;
			r.setNoID(NoID);
		} while (token == ',');
		ruas.push_back(r);

		for (int i = 0; i < r.getNosID().size() - 1; i++) {

			Vertex<No>* v1 = findNo(r.getNosID().at(i));
			Vertex<No>* v2 = findNo(r.getNosID().at(i + 1));
			No no1 = v1->getInfo();
			No no2 = v2->getInfo();

			double weight = sqrt(
					pow((no2.getX() - no1.getX()), 2)
					+ pow((no2.getY() - no1.getY()), 2));

			myGraph.addEdge(ID_ARESTA_GERAL, no1, no2, weight);

			ID_ARESTA_GERAL++;
		}

		if (twoWays == "True") {

			for (int i = r.getNosID().size() - 1; i > 0; i--) {

				Vertex<No>* v1 = findNo(r.getNosID().at(i));
				Vertex<No>* v2 = findNo(r.getNosID().at(i - 1));
				No no1 = v1->getInfo();
				No no2 = v2->getInfo();

				double weight = sqrt(
						pow((no2.getX() - no1.getX()), 2)
						+ pow((no2.getY() - no1.getY()), 2));

				myGraph.addEdge(ID_ARESTA_GERAL, no1, no2, weight);

				ID_ARESTA_GERAL++;
			}
		}

	}

	inFile.close();

	//Ler o ficheiro freguesias.txt
	inFile.open("freguesias.txt");

	if (!inFile) {
		cerr << "Unable to open file freguesias.txt";
		exit(1);   // call system to stop
	}

	string nomeFreguesia;
	int idFreguesia;

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idFreguesia >> token;
		getline(linestream, nomeFreguesia, ';');

		Freguesia f(idFreguesia, nomeFreguesia);
		do {
			linestream >> NoID >> token;
			f.setNoID(NoID);
		} while (token == ',');



		freguesias.push_back(f);

	}

	inFile.close();

	if (isFloydWarshall == true) {
		tempoinicial = GetMilliCount();
		myGraph.floydWarshallShortestPath();
		tempointermedio = GetMilliSpan(tempoinicial);
	}

}

void Emergencia::getCall(int noID, int polFlag, int bombFlag, int inemFlag,
		bool gotoHospital) {

	if (!myGraph.stronglyConnectedComponents()) {
		cout << "Nao e possivel calcular a sua chamada por invalidade do mapa"
				<< endl;
		getchar();
		return;
	}

	tempoinicial = GetMilliCount();

	No localizacao;
	gv->setVertexIcon(noID, "ajuda1.png");
	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
		if (myGraph.getVertexSet()[i]->getInfo().getID() == noID)
			localizacao = myGraph.getVertexSet()[i]->getInfo();
	}

	vector<Edge<No> > pathedgesPolicia;
	vector<Edge<No> > pathedgesBombeiros;
	vector<Edge<No> > pathedgesINEM;
	vector<Edge<No> > pathHospital;
	vector<No> pathnodes;
	vector<vector<Edge<No> > > pathsPolicia;
	vector<vector<Edge<No> > > pathsBombeiros;
	vector<vector<Edge<No> > > pathsINEM;
	while (inemFlag > 0) {

		No INEMAssistencia = findElement(myGraph.getVertex(localizacao),
				pathnodes, 'I');
		if (pathnodes.size() > 0) {

			cout << "A ambulancia do INEM seguira o seguinte caminho: ";
			for (unsigned int i = 0; i < pathnodes.size(); i++)
				cout << pathnodes[i].getID() << " ";
			cout << endl;
			pathedgesINEM = myGraph.getEdges(pathnodes);
			pathsINEM.push_back(pathedgesINEM);

		} else
			cout << "Na sua localizaçao ja existe ambulancias\n";
		inemFlag--;

	}
	pathnodes.clear();
	while (bombFlag > 0) {
		No BombAssistencia = findElement(myGraph.getVertex(localizacao),
				pathnodes, 'B');
		if (pathnodes.size() > 0) {
			cout << "O camiao dos bombeiros seguira o seguinte caminho: ";
			for (unsigned int i = 0; i < pathnodes.size(); i++)
				cout << pathnodes[i].getID() << " ";
			cout << endl;
			pathedgesBombeiros = myGraph.getEdges(pathnodes);
			pathsBombeiros.push_back(pathedgesBombeiros);
		} else
			cout << "Na sua localizacao ja existe uns bombeiros\n" << endl;
		bombFlag--;
	}

	pathnodes.clear();
	while (polFlag > 0) {
		No PoliciaAssistencia = findElement(myGraph.getVertex(localizacao),
				pathnodes, 'P');
		if (pathnodes.size() > 0) {
			cout << "O carro da policia seguira o seguinte caminho: ";
			for (unsigned int i = 0; i < pathnodes.size(); i++)
				cout << pathnodes[i].getID() << " ";
			cout << endl;
			pathedgesPolicia = myGraph.getEdges(pathnodes);
			pathsPolicia.push_back(pathedgesPolicia);
		} else
			cout << "Na sua localizacao ja existe policias\n" << endl;
		polFlag--;
	}
	if (gotoHospital) {
		pathHospital = moveToHospital(myGraph.getVertex(localizacao));
		if (pathHospital.size() == 0)
			cout << "Na sua localizacao ja existe um hospital\n" << endl;
	}

	tempofinal = GetMilliSpan(tempoinicial) + tempointermedio;
	cout << endl << "Tempo Final: " << tempofinal << endl;
	for (unsigned int i = 0; i < pathsINEM.size(); i++)
		this->drawPath(pathsINEM[i], "green", "INEM.png");
	for (unsigned int i = 0; i < pathsBombeiros.size(); i++)
		this->drawPath(pathsBombeiros[i], "red", "bombeiro.png");
	for (unsigned int i = 0; i < pathsPolicia.size(); i++)
		this->drawPath(pathsPolicia[i], "blue", "policia.png");
	if (pathHospital.size() > 0) {
		drawPath(pathHospital, "green", "INEM.png");
	}

}

void Emergencia::displayGraph() {

	gv->createWindow(600, 600);

	gv->defineEdgeColor("black");
	gv->defineVertexIcon("normal.png");
	gv->defineEdgeCurved(false);

	vector<Vertex<No>*> vertexSet = myGraph.getVertexSet();

	typename vector<Vertex<No>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<No>*>::const_iterator ite = vertexSet.end();

	for (; it != ite; it++) {

		No addno = (*it)->getInfo();

		gv->addNode(addno.getID(), (addno.getX() * 2) + 20,
				-(addno.getY() * 2) + 420);
		stringstream ss;
		ss << addno.getID();
		gv->setVertexLabel(addno.getID(), ss.str());
	}

	it = vertexSet.begin();
	ite = vertexSet.end();
	typename vector<Edge<No> >::iterator itEdges;
	typename vector<Edge<No> >::iterator iteEdges;

	for (; it != ite; it++) {

		vector<Edge<No> > edgesvec = (*it)->getAdj();
		itEdges = edgesvec.begin();
		iteEdges = edgesvec.end();
		for (; itEdges != iteEdges; itEdges++) {
			gv->addEdge((itEdges)->getID(), (*it)->getInfo().getID(),
					(itEdges)->getDest()->getInfo().getID(),
					EdgeType::DIRECTED);
		}

	}
	colorNodes();

	this->resetGV();
	this->writeRuas();
	gv->rearrange();

}

void Emergencia::colorNodes() {

	vector<Veiculo>::iterator it = this->INEM.begin();
	for (; it != INEM.end(); it++) {
		(*it).decDisponibilidade();
		if ((*it).getDisponibilidade() == 0)
			gv->setVertexIcon((*it).getlocalNode().getID(), "INEM.png");

	}
	it = this->policia.begin();
	for (; it != policia.end(); it++) {
		(*it).decDisponibilidade();
		if ((*it).getDisponibilidade() == 0)
			gv->setVertexIcon((*it).getlocalNode().getID(), "policia.png");

	}
	it = this->bombeiros.begin();
	for (; it != bombeiros.end(); it++) {
		(*it).decDisponibilidade();
		if ((*it).getDisponibilidade() == 0)
			gv->setVertexIcon((*it).getlocalNode().getID(), "bombeiro.png");

	}
	for (unsigned int i = 0; i < this->hospitais.size(); i++) {
		gv->setVertexIcon(hospitais.at(i).getID(), "hospital.png");
	}
	gv->rearrange();
}

No Emergencia::findElement(Vertex<No>* localizacao, vector<No> &pathnodes,
		char elementType) {

	vector<Veiculo>* auxvector;
	switch (elementType) {
	case 'B':
		auxvector = &bombeiros;
		break;
	case 'P':
		auxvector = &policia;
		break;
	case 'I':
		auxvector = &INEM;
		break;
	};

	Veiculo* veicFinal;
	int distAtual;
	int distMinima = INT_MAX;

	if (!(isFloydWarshall)) {
		for (unsigned int i = 0; i < (*auxvector).size(); i++) {
			if ((*auxvector)[i].getDisponibilidade() == 0) {
				myGraph.dijkstraShortestPath((*auxvector)[i].getlocalNode());
				distAtual = localizacao->getDist();
				if (distAtual < distMinima) {
					distMinima = distAtual;
					veicFinal = &(*auxvector)[i];
					if (!((*auxvector)[i].getlocalNode()
							== localizacao->getInfo()))
						pathnodes = myGraph.getPath(
								(*auxvector)[i].getlocalNode(),
								localizacao->getInfo());
				}
			}

		}

	} else {

		for (unsigned int i = 0; i < (*auxvector).size(); i++) {
			if ((*auxvector)[i].getDisponibilidade() == 0) {
				distAtual =
						myGraph.getfloydWarshallweight(
								myGraph.getVertex(
										(*auxvector)[i].getlocalNode())->getVectorPos(),
										localizacao->getVectorPos());
				if (distAtual < distMinima) {
					distMinima = distAtual;
					veicFinal = &(*auxvector)[i];
				}
			}
		}
		if (!((*veicFinal).getlocalNode() == localizacao->getInfo()))
			pathnodes = myGraph.getfloydWarshallPath(
					(*veicFinal).getlocalNode(), localizacao->getInfo());
	}

	(*veicFinal).setDisponibilidade(3);
	if (pathnodes.size() > 0)
		(*veicFinal).setlocalNode(pathnodes[pathnodes.size() - 1]);
	return (*veicFinal).getlocalNode();

}

void Emergencia::drawPath(vector<Edge<No> > &edgepath, string color,
		string icon) {

	for (unsigned int i = 0; i < edgepath.size(); i++) {
		gv->setVertexIcon(edgepath.at(i).getDest()->getInfo().getID(), icon);

		gv->setEdgeColor(edgepath.at(i).getID(), color);
		gv->setEdgeThickness(edgepath.at(i).getID(), 5);
		gv->rearrange();
		Sleep(1000);
		gv->setVertexIcon(edgepath.at(i).getDest()->getInfo().getID(),
				"normal.png");
		gv->rearrange();
	}

}

vector<Edge<No> > Emergencia::moveToHospital(Vertex<No>* localizacao) {
	int distmin = INT_MAX;
	No nofinal;
	Vertex<No>* aux;
	vector<No> nodestopaint;
	vector<Edge<No> > edgestopaint;
	if (!isFloydWarshall) {
		myGraph.dijkstraShortestPath(localizacao->getInfo());
		for (unsigned int i = 0; i < this->hospitais.size(); i++) {
			aux = myGraph.getVertex(hospitais.at(i));
			if (aux->getDist() < distmin) {
				distmin = aux->getDist();
				nofinal = hospitais.at(i);
			}
		}
		if (distmin != 0) {
			cout
			<< "Posteriormente a ambulancia seguira o seguinte caminho em direcao ao hospital: ";
			nodestopaint = myGraph.getPath(localizacao->getInfo(), nofinal);
			for (unsigned int i = 0; i < nodestopaint.size(); i++)
				cout << nodestopaint[i].getID() << " ";
			cout << endl;

		} else {
			cout << "Na sua localizacao ja existe um hospital\n";
		}
	} else {

		int weight;
		for (unsigned int i = 0; i < this->hospitais.size(); i++) {
			weight = myGraph.getfloydWarshallweight(localizacao->getVectorPos(),
					myGraph.getVertex(hospitais[i])->getVectorPos());
			if (weight < distmin) {
				distmin = weight;
				nofinal = hospitais.at(i);
			}
		}
		if (distmin != 0) {
			cout
			<< "Posteriormente a ambulancia seguira o seguinte caminho em direcao ao hospital: ";
			nodestopaint = myGraph.getfloydWarshallPath(localizacao->getInfo(),
					nofinal);
			for (unsigned int i = 0; i < nodestopaint.size(); i++)
				cout << nodestopaint[i].getID() << " ";
			cout << endl;

		} else {
			cout << "Na sua localizacao ja existe um hospital\n";
		}

	}
	if (distmin != 0)
		edgestopaint = myGraph.getEdges(nodestopaint);
	return edgestopaint;
}

void Emergencia::resetGV() {

	vector<Vertex<No>*> vertexSet = myGraph.getVertexSet();
	typename vector<Vertex<No>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<No>*>::const_iterator ite = vertexSet.end();
	typename vector<Edge<No> >::iterator itEdges;
	typename vector<Edge<No> >::iterator iteEdges;

	for (; it != ite; it++) {

		vector<Edge<No> > edgesvec = (*it)->getAdj();
		itEdges = edgesvec.begin();
		iteEdges = edgesvec.end();
		for (; itEdges != iteEdges; itEdges++) {
			gv->setEdgeColor(itEdges->getID(), "black");
			gv->setEdgeThickness(itEdges->getID(), 1);
		}

	}

	vector<Vertex<No>*> aux = myGraph.getVertexSet();
	for (unsigned int i = 0; i < aux.size(); i++) {
		gv->setVertexIcon(aux.at(i)->getInfo().getID(), "normal.png");
	}
	this->colorNodes();

	gv->rearrange();
}

vector<Rua> Emergencia::getRuas() {
	return this->ruas;
}

void Emergencia::writeRuas() {
	vector<No> path;
	for (unsigned int i = 0; i < ruas.size(); i++) {
		for (unsigned int a = 0; a < ruas.at(i).getNosID().size(); a++) {
			No n = No(ruas.at(i).getNosID().at(a));
			path.push_back(n);
		}
		vector<Edge<No> > aux = myGraph.getEdges(path);
		path.clear();
		for (unsigned int a = 0; a < aux.size(); a++) {
			gv->setEdgeLabel(aux.at(a).getID(), ruas.at(i).getNome());
		}
		aux.clear();
	}

}

bool Emergencia::verificarConetividade() {
	return myGraph.stronglyConnectedComponents();
}

string Emergencia::verificarRuaExata(string rua_utilizador) {
	string ret = "";
	bool encontrou = false;
	for (unsigned int i = 0; i < ruas.size(); i++) {
		if (pesquisaExata(rua_utilizador, ruas.at(i).getNome())) {
			encontrou = true;
			ret += encontraVeiculos(ruas.at(i)) + "\n";

		}
	}
	if(!encontrou)
		ret = "lugar desconhecido";
	return ret;
}


bool Emergencia::pesquisaExata(string rua_utilizador, string rua_grafo) {
	//Percorrer todas as strings em rua grafo, e analisar cada uma com  o algoritmo
	//se o numero de carateres matched for igual à length da rua do user, entao encontrou a palavra k se procurava
	//faz se break e retorna true
	vector<string> splited_rua_grafo = splitString(rua_grafo);
	vector<string> splited_rua_utilizador = splitString(rua_utilizador);

	for(int i = 0 ; (i + splited_rua_utilizador.size()) < splited_rua_grafo.size() ; i++ ){
		string text = concatenateStrings(splited_rua_grafo, splited_rua_utilizador.size(), i);
		string pattern = concatenateStrings(splited_rua_utilizador, splited_rua_utilizador.size(), 0);
		if(KMP(pattern, text))
			return true;

	}
	return false;
}



string Emergencia::encontraVeiculos(Rua rua) {
	string ret = rua.getNome() + " - ";
	for (unsigned int i = 0; i < INEM.size(); i++) {
		for (unsigned int a = 0; a < rua.getNosID().size(); a++) {
			if (INEM.at(i).getlocalNode().getID() == rua.getNosID().at(a)) {
				ret += "INEM, ";
				break;
			}
		}
	}

	for (unsigned int i = 0; i < bombeiros.size(); i++) {
		for (unsigned int a = 0; a < rua.getNosID().size(); a++) {
			if (bombeiros.at(i).getlocalNode().getID() == rua.getNosID().at(a)) {
				ret += "Bombeiro, ";
				break;
			}
		}
	}

	for (unsigned int i = 0; i < policia.size(); i++) {
		for (unsigned int a = 0; a < rua.getNosID().size(); a++) {
			if (policia.at(i).getlocalNode().getID() == rua.getNosID().at(a)) {
				ret += "Policia, ";
				break;
			}
		}
	}
	return ret;
}

vector<string> Emergencia::verificarRuaAproximada(string rua_utilizador)
{
	vector<string> ret;
	return ret;
}

