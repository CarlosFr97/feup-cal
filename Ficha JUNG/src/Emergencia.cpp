/*
 * Emergencia.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Carlos Freitas
 */

#include "Emergencia.h"

Emergencia::Emergencia() {
	// TODO Auto-generated constructor stub

}

Emergencia::~Emergencia() {
	// TODO Auto-generated destructor stub
}

void readFiles(){

    GraphViewer *gv = new GraphViewer(1000, 1000, false);

    gv->createWindow(1000, 1000);
    
    
    gv->defineEdgeColor("blue");
    gv->defineVertexColor("yellow");
    
    ifstream inFile;
    
    //Ler o ficheiro nos.txt
    inFile.open("nos.txt");
    
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    
    std::string   line;

    long long int idNo=0;
    float X=0;
    float Y=0;
    float xfinal, yfinal;
    
    while(std::getline(inFile, line))
    {
        std::stringstream linestream(line);
        std::string         data;
        
        linestream >> idNo;
        std::getline(linestream, data, ';'); //get degrees value
        std::getline(linestream, data, ';');
        
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> X;
        std::getline(linestream, data, '\n');  // read up-to the first ; (discard ;).
        linestream >> Y;
        xfinal = (180+Y)*(1000/360);
        yfinal = (90-X)*(1000/180);
        
        gv->addNode(idNo,xfinal,yfinal);
        
        gv->rearrange();
        
    }
    
    inFile.close();

}


int main()
{
    readFiles();
    getchar();
    return 0;
}
