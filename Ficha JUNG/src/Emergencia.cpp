#include "Emergencia.h"
#include "Rua.h"
#include "Graph.h"


using namespace std;

Emergencia::Emergencia() {
	ID_ARESTA_GERAL = 1;
	gv = new GraphViewer(600, 600, false);
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
		cerr << "Unable to open file datafile.txt";
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
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idNo >> token >> X >> token >> Y;

		No n(idNo, X, Y);

		myGraph.addVertex(n);
		hospitais.push_back(myGraph.getVertex(n));

	}

	inFile.close();

	//Ler o ficheiro inemNos.txt
	inFile.open("INEM.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
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
		cerr << "Unable to open file datafile.txt";
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
		cerr << "Unable to open file datafile.txt";
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

	int idRua = 0;
	int idAresta = 0;
	int idNo1 = 0, idNo2 = 0;

	//Ler o ficheiro arestas.txt
	inFile.open("arestas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	while (getline(inFile, line)) {

		std::stringstream linestream(line);

		linestream >> idAresta >> token >> idNo1 >> token >> idNo2;

		Vertex<No>* v1 = findNo(idNo1);
		Vertex<No>* v2 = findNo(idNo2);
		No no1 = v1->getInfo();
		No no2 = v2->getInfo();

		double weight = sqrt(
				pow((no2.getX() - no1.getX()), 2)
						+ pow((no2.getY() - no1.getY()), 2));

		/*cout << "Id Aresta: " << idAresta << "   no1: " << no1.getID()
		 << "   no2: " << no2.getID() << endl;*/
		myGraph.addEdge(idAresta, no1, no2, weight);

		ID_ARESTA_GERAL++;

	}

	inFile.close();

	string nomeRua, twoWays;
	int NoID;

	//Ler o ficheiro ruas.txt
	inFile.open("ruas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
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

}

void Emergencia::getCall(int noID,int polFlag,int bombFlag,int inemFlag) {
	
	int tempoInicial = GetMilliCount();
	if(VerificarConectividade())
		cout<<"E conexo"<<endl;
	else
		cout<<"Não e conexo"<<endl;
	No localizacao;
	gv->setVertexIcon(noID,"ajuda.png");
	for(unsigned int i=0; i<myGraph.getVertexSet().size(); i++)
	{
		if(myGraph.getVertexSet()[i]->getInfo().getID() == noID)
			localizacao = myGraph.getVertexSet()[i]->getInfo();
	}


	vector< Edge<No> > pathedges;


	if(inemFlag)
	{

		No INEMAssistencia = findINEM(myGraph.getVertex(localizacao));
		vector<No> INEMPath= myGraph.getPath(INEMAssistencia, localizacao,pathedges);
		//this->drawNodes(INEMPath,"INEM.png");
		this->drawPath(pathedges,"green");

		for(int i=0; i<pathedges.size(); i++)
			{
				cout<<"INEM: "<<pathedges[i].getDest()->getInfo().getID();
			}
	}
	pathedges.clear();
	if(bombFlag)
	{
		No BombAssistencia = findBomb(myGraph.getVertex(localizacao));
		if(!(BombAssistencia == localizacao))
		{
			vector<No> BombPath = myGraph.getPath(BombAssistencia, localizacao,pathedges);
			//this->drawNodes(BombPath,"bombeiros.png");
			this->drawPath(pathedges,"red");

			for(unsigned int i=0; i<pathedges.size(); i++)
			{
				cout<<"Bombeiros: "<<pathedges[i].getDest()->getInfo().getID();
			}
		}
		else
			cout<<"Na sua localizacao já existe uns bombeiros"<<endl;

	}

	pathedges.clear();
	if(polFlag)
	{
		No PoliciaAssistencia = findPolicia(myGraph.getVertex(localizacao));
		 vector<No> PoliciaPath= myGraph.getPath(PoliciaAssistencia, localizacao,pathedges);
		// this->drawNodes(PoliciaPath,"policia.png");
		 this->drawPath(pathedges,"blue");


		for(unsigned int i=0; i<pathedges.size(); i++)
		{
			cout<<"Policia: "<<pathedges[i].getDest()->getInfo().getID();
		}
	}


	/*if(polFlag != 0)
	{
		vector< Edge<No> > edgestopaint;
		vector<No> pathPolicia = myGraph.getPath(policiaAssistencia->getInfo(), localizacao, edgestopaint);
			for(unsigned int i=0; i< pathPolicia.size(); i++)
			{
				cout<<"ID Policia NO: "<<pathPolicia[i].getID() << endl;
			}
		//this->drawPath(gv,findNo(policiaAssistencia->getInfo().getID()),"blue");
	}

	if(bombFlag != 0)
	{
		vector< Edge<No> > edgestopaint;
		vector<No> pathINEM = myGraph.getPath(INEMAssistencia->getInfo(),localizacao, edgestopaint);
			for(unsigned int i = 0; i < pathINEM.size();i++)
			{
				cout << "ID INEM NO: " << pathINEM[i].getID()<< endl;
			}
			//this->drawPath(gv,INEMAssistencia,"green");

	}*/


		//vector<No> pathBomb = myGraph.getPath(localizacao,policiaAssistencia->getInfo(), edgestopaint);
			/*for(unsigned int i = 0; i < pathBomb.size();i++)
			{
				cout << "ID Bombeiros NO: " << pathBomb[i].getID() << endl;;

			}
			for(int i=0; i<edgestopaint.size(); i++)
			{
				cout<<"Aresta: "<<edgestopaint[i].getDest()->getInfo().getID()<<endl;
			}*/
			//this->drawPath(gv,bombAssistencia,"red");

	int tempoFinal = GetMilliSpan(tempoInicial);


}

bool Emergencia::VerificarConectividade()
{
	vector< Vertex<No>* > vertexSet = myGraph.getVertexSet();
	typename vector<Vertex<No>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<No>*>::const_iterator ite = vertexSet.end();

	vector<No> vertexLigados;
	for(; it!= ite; it++)
	{
		vertexLigados = myGraph.bfs((*it));
		if(vertexLigados.size() != 37)
			return false;
	}
	return true;
}

void Emergencia::displayGraph() {

	//TODO delete
	cout << "display" << endl;

	gv->createWindow(600, 600);

	gv->defineEdgeColor("black");
	gv->defineVertexColor("white");
	gv->defineEdgeCurved(true);

	vector<Vertex<No>*> vertexSet = myGraph.getVertexSet();

	typename vector<Vertex<No>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<No>*>::const_iterator ite = vertexSet.end();

	for (; it != ite; it++) {

		No addno = (*it)->getInfo();

		gv->addNode(addno.getID(), (addno.getX() * 2) + 20,
				-(addno.getY() * 2) + 420);
		stringstream ss;
		ss<<addno.getID();
		gv->setVertexLabel(addno.getID(),ss.str());
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
	gv->rearrange();

}


void Emergencia::colorNodes() const {
	vector<Veiculo>::const_iterator it = this->INEM.begin();
	for (; it != INEM.end(); it++) {
		if((*it).getDisponibilidade())
		gv->setVertexIcon((*it).getlocalNode().getID(), "INEM.png");
	}
	it = this->policia.begin();
	for (; it != policia.end(); it++) {
		if((*it).getDisponibilidade())
		gv->setVertexIcon((*it).getlocalNode().getID(), "policia.png");
	}
	it = this->bombeiros.begin();
	for (; it != bombeiros.end(); it++) {
		if((*it).getDisponibilidade())
		gv->setVertexIcon((*it).getlocalNode().getID(), "bombeiro.png");
		//gv->setVertexIcon((*it).getLocal().getID(),"icon.gif");
	}
	for(unsigned int i = 0 ; i < this->hospitais.size();i++)
	{
		gv->setVertexIcon(hospitais.at(i)->getInfo().getID(),"hospital.png");
	}

}

No Emergencia::findINEM(Vertex<No>* localizacao) {

	int posicaofinal = 0;
	int distAtual;
	int distMinima = INT_MAX;

	for (unsigned int i = 0; i < INEM.size(); i++) {
			if (INEM[i].getDisponibilidade()) {
				myGraph.dijkstraShortestPath(INEM[i].getlocalNode());
				distAtual = localizacao->getDist();
				if (distAtual < distMinima) {
					distMinima = distAtual;
					posicaofinal = i;
				}
			}
		}
		INEM[posicaofinal].setDisponibilidade(false);
		return INEM[posicaofinal].getlocalNode();

}

void Emergencia::drawPath( vector<Edge<No> > &edgepath,string color)
{
	//bool findEnd = false;
/*
	for(int i=0; i<myGraph.getVertexSet().size(); i++)
	{
		if(myGraph.getVertexSet()[i]->path == NULL)
			cout<<myGraph.getVertexSet()[i]->getInfo().getID()<<" Null"<<endl;
	}*/

	for(unsigned int i = 0; i < edgepath.size();i++)
	{
		gv->setEdgeColor(edgepath.at(i).getID(),color);
		//Sleep(2000);
		//gv->setEdgeColor(edgepath.at(i).getID(),"black");
	}


	/*do{
		if(aux->path == NULL)
		{
			break;
		}
		for(unsigned int i = 0; i <aux->getAdj().size(); i++)
		{
			cout << "ENTROU";
			if(aux->getAdj().at(i).getDest() == aux->path)
			{

				gv->setEdgeColor(aux->getAdj().at(i).getID(),color);
				aux = aux->getAdj().at(i).getDest();
				break;
			}
		}
	}while(!findEnd);


	gv->rearrange();*/

}

void Emergencia::drawNodes(vector<No> nos,string color)
{
	for(unsigned int i = 0; i < nos.size();i++)
	{

		if(i == nos.size()-1)
		{
			gv->setVertexIcon(nos.at(i).getID(),color);
			break;
		}
		gv->setVertexIcon(nos.at(i).getID(),color);
		Sleep(1000);
		gv->setVertexColor(nos.at(i).getID(),"white");



	}
	gv->rearrange();
}
No Emergencia::findBomb(Vertex<No>* localizacao){
	int posicaofinal = 0;
	int distAtual;
	int distMinima = INT_MAX;

		for (unsigned int i = 0; i < bombeiros.size(); i++) {
			if (bombeiros[i].getDisponibilidade()) {
				myGraph.dijkstraShortestPath(bombeiros[i].getlocalNode());
				distAtual = localizacao->getDist();
				if (distAtual < distMinima) {
					distMinima = distAtual;
					posicaofinal = i;
				}
			}
		}
		bombeiros[posicaofinal].setDisponibilidade(false);
	return bombeiros[posicaofinal].getlocalNode();
}

No Emergencia::findPolicia(Vertex<No>* localizacao) {
	int posicaofinal = 0;
		int distAtual;
		int distMinima = INT_MAX;
		for (unsigned int i = 0; i < policia.size(); i++) {
			if (policia[i].getDisponibilidade()) {
				myGraph.dijkstraShortestPath(policia[i].getlocalNode());
				distAtual = localizacao->getDist();
				if (distAtual < distMinima) {
					distMinima = distAtual;
					posicaofinal = i;
				}
			}
		}
		policia[posicaofinal].setDisponibilidade(false);
		return policia[posicaofinal].getlocalNode();


}

void Emergencia::resetGV()
{

	//gv->defineVertexIcon("INEM.png");

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
				gv->setEdgeColor(itEdges->getID(),"black");
			//	stringstream ss;
				//ss << itEdges->getWeight();
				//gv->setEdgeLabel(itEdges->getID(),ss.str());
			}

		}
}





