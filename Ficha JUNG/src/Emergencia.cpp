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

void readFiles(){
    
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


        
    }
    
    inFile.close();

}


int main()
{
    readFiles();
    getchar();
    return 0;
}
