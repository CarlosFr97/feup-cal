/*
 * menu.cpp
 *
 *  Created on: 28/03/2017
 *      Author: up201503344
 */

#include "menu.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Retrieves a handle for the standard input, standard output, or standard error device
COORD CursorPosition; // Defines the coordinates of a character cell in a console screen buffer used in gotoXY


void menu_principal(Emergencia &em)

{

	int menu_item = 0; //usada para saber qual e o caso do switch que esta a apontar
	int 	x = 10; //usada para saber a linha que a seta esta apontar
	bool running = true;
	system("CLS");//cleans cmd




	gotoXY(18, 10); cout << "->";

	while (running)
	{
		gotoXY(18, 8); cout << "Central de Atendimento de Urgencias:";
		gotoXY(20, 10);  cout << "1) Realizar chamada";
		gotoXY(20, 11);  cout << "2) Sair";

		system("pause>nul"); // the >nul bit causes it to print no message

		if (!GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(0x31) && !GetAsyncKeyState(0x32) )// se for clicado uma tecla diferente das setas (cima e baixo) e enter, nao faz nada
		{
			continue;
		}

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed and
		{
			gotoXY(18, x); cout << "  ";//limpa seta
			x++;
			gotoXY(18, x); cout << "->";//seta aponta para a proxima linha do menu
			menu_item++;//faz com que este valor seja coerente com a linha que esta apontar
			continue;

		}
		else if (GetAsyncKeyState(VK_DOWN) && x == 11) // se precionar para baixo na ultima linha do menu, volta a primeira linha do mesmo
		{
			gotoXY(18, x); cout << "  ";//"limpa" a seta
			x = 10;//posicao em x da pos inicial
			gotoXY(18, x); cout << "->"; // mete a seta nessa pos inicial
			menu_item = 0;//atribui o caso 0 do switch para a primeira linha como e suposto
			continue;

		}

		else if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "->";//seta aponta para a linha anterior
			menu_item--;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x == 10)//se precionar para cima na primeira linha do menu a seta passa a apontar para a ultima linha do mesmo
		{
			gotoXY(18, x); cout << "  ";
			x = 11;//pos em x da pos final do menu (defenido nos couts)
			gotoXY(18, x); cout << "->";//mete seta nessa posicao
			menu_item = 1; // menu_item correspondente a ultima linha do menu
			continue;


		}
		else if (GetAsyncKeyState(0x31))
		{
			gotoXY(18, x); cout << "  ";
			x = 10;
			gotoXY(18, x); cout << "->";
			menu_item = 0;
			continue;
		}
		else if (GetAsyncKeyState(0x32))
		{
			gotoXY(18, x); cout << "  ";
			x = 11;
			gotoXY(18, x); cout << "->";
			menu_item = 1;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			//dependendo da posicao da seta no menu, ao carregar enter vera o valor do menu_item correspondente a essa linha e executa a opcao escolhida

			switch (menu_item) {

			case 0: {

				/*int noid,bomb,pol,inem;

						gotoXY(20, 16);//para que o proximo cout nao sobreponha o menu
						cout << "A chamar:     ";
						gotoXY(20,17);
						cout << "No local: ";
						cin >> noid;
						gotoXY(20,17);
						cout << "Bombeiros?: ";
						cin >> bomb;
						gotoXY(20,17);
						cout << "                           ";
						gotoXY(20,17);
						cout << "Policia?: ";
						cin >> pol;
						gotoXY(20,17);
						cout << "                           ";
						gotoXY(20,17);
						cout << "Inem?: ";
						cin >> inem;

						em.getCall(noid,pol,bomb,inem);
						Sleep(5000);
						em.resetGV();*/
				tipoEmergencia(em);

				break;
			}


			case 1: {
				gotoXY(20, 16);//para que o proximo cout nao sobreponha o menu
				cout << "A sair da linha de atendimento!";
				Sleep(3);
				running = false;//de forma a sair do while
				break;
			}




			}

		}

	}

	gotoXY(20, 17);// para que a mensagem de fechar o programa "Press any key to continue..." se encontra uma linha apos o cout apresentado ao querer sair do programa
	exit(0);//fecha o programa

}



void tipoEmergencia(Emergencia &em)
{
	int menu_item = 0; //usada para saber qual e o caso do switch que esta a apontar
	int 	x = 10; //usada para saber a linha que a seta esta apontar
	bool running = true;
	system("CLS");//cleans cmd





	gotoXY(18, 10); cout << "->";

	while (running)
	{
		gotoXY(18, 8); cout << "Tipo de Urgencia:";
		gotoXY(20, 10);  cout << "1) Incendio";
		gotoXY(20, 11);  cout << "2) Crime";
		gotoXY(20,12);  cout << "3) Acidente";

		system("pause>nul"); // the >nul bit causes it to print no message

		if (!GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(0x31) && !GetAsyncKeyState(0x32) && !GetAsyncKeyState(0x33) )// se for clicado uma tecla diferente das setas (cima e baixo) e enter, nao faz nada
		{
			continue;
		}

		if (GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed and
		{
			gotoXY(18, x); cout << "  ";//limpa seta
			x++;
			gotoXY(18, x); cout << "->";//seta aponta para a proxima linha do menu
			menu_item++;//faz com que este valor seja coerente com a linha que esta apontar
			continue;

		}
		else if (GetAsyncKeyState(VK_DOWN) && x == 12) // se precionar para baixo na ultima linha do menu, volta a primeira linha do mesmo
		{
			gotoXY(18, x); cout << "  ";//"limpa" a seta
			x = 10;//posicao em x da pos inicial
			gotoXY(18, x); cout << "->"; // mete a seta nessa pos inicial
			menu_item = 0;//atribui o caso 0 do switch para a primeira linha como e suposto
			continue;

		}

		else if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "->";//seta aponta para a linha anterior
			menu_item--;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x == 10)//se precionar para cima na primeira linha do menu a seta passa a apontar para a ultima linha do mesmo
		{
			gotoXY(18, x); cout << "  ";
			x = 12;//pos em x da pos final do menu (defenido nos couts)
			gotoXY(18, x); cout << "->";//mete seta nessa posicao
			menu_item = 2; // menu_item correspondente a ultima linha do menu
			continue;


		}
		else if (GetAsyncKeyState(0x31))
		{
			gotoXY(18, x); cout << "  ";
			x = 10;
			gotoXY(18, x); cout << "->";
			menu_item = 0;
			continue;
		}
		else if (GetAsyncKeyState(0x32))
		{
			gotoXY(18, x); cout << "  ";
			x = 11;
			gotoXY(18, x); cout << "->";
			menu_item = 1;
			continue;
		}
		else if (GetAsyncKeyState(0x33))
		{
			gotoXY(18, x); cout << "  ";
			x = 12;
			gotoXY(18, x); cout << "->";
			menu_item = 2;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			//dependendo da posicao da seta no menu, ao carregar enter vera o valor do menu_item correspondente a essa linha e executa a opcao escolhida

			switch (menu_item) {

			case 0: {

				//int noid,bomb,pol,inem,hs;

				gotoXY(20, 16);//para que o proximo cout nao sobreponha o menu
				cout << "A chamar:     ";
				emLevel(em,1);
				running = false;

				system("CLS");
				break;
			}


			case 1: {

				gotoXY(20, 16);//para que o proximo cout nao sobreponha o menu
								cout << "A chamar:     ";
								emLevel(em,2);
								running = false;
								system("CLS");
				break;
			}

			case 2: {
				gotoXY(20, 16);//para que o proximo cout nao sobreponha o menu
				cout << "A chamar:     ";
				emLevel(em,3);
				running = false;
				system("CLS");
				break;
			}




			}

		}

	}

	gotoXY(20, 17);// para que a mensagem de fechar o programa "Press any key to continue..." se encontra uma linha apos o cout apresentado ao querer sair do programa
	return;

}

void emLevel(Emergencia &em,int typeFlag)
{
	int menu_item = 0; //usada para saber qual e o caso do switch que esta a apontar
	int 	x = 10; //usada para saber a linha que a seta esta apontar
	bool running = true;
	system("CLS");//cleans cmd





	gotoXY(18, 10); cout << "->";

	while (running)
	{
		gotoXY(18, 8); cout << "Tipo de Urgencia:";
		gotoXY(20, 10);  cout << "1) Nivel 1";
		gotoXY(20, 11);  cout << "2) Nivel 2";
		gotoXY(20,12);  cout << "3) Nivel 3";

		system("pause>nul"); // the >nul bit causes it to print no message

		if (!GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(0x31) && !GetAsyncKeyState(0x32) && !GetAsyncKeyState(0x33) )// se for clicado uma tecla diferente das setas (cima e baixo) e enter, nao faz nada
		{
			continue;
		}

		if (GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed and
		{
			gotoXY(18, x); cout << "  ";//limpa seta
			x++;
			gotoXY(18, x); cout << "->";//seta aponta para a proxima linha do menu
			menu_item++;//faz com que este valor seja coerente com a linha que esta apontar
			continue;

		}
		else if (GetAsyncKeyState(VK_DOWN) && x == 12) // se precionar para baixo na ultima linha do menu, volta a primeira linha do mesmo
		{
			gotoXY(18, x); cout << "  ";//"limpa" a seta
			x = 10;//posicao em x da pos inicial
			gotoXY(18, x); cout << "->"; // mete a seta nessa pos inicial
			menu_item = 0;//atribui o caso 0 do switch para a primeira linha como e suposto
			continue;

		}

		else if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "->";//seta aponta para a linha anterior
			menu_item--;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x == 10)//se precionar para cima na primeira linha do menu a seta passa a apontar para a ultima linha do mesmo
		{
			gotoXY(18, x); cout << "  ";
			x = 12;//pos em x da pos final do menu (defenido nos couts)
			gotoXY(18, x); cout << "->";//mete seta nessa posicao
			menu_item = 2; // menu_item correspondente a ultima linha do menu
			continue;


		}
		else if (GetAsyncKeyState(0x31))
		{
			gotoXY(18, x); cout << "  ";
			x = 10;
			gotoXY(18, x); cout << "->";
			menu_item = 0;
			continue;
		}
		else if (GetAsyncKeyState(0x32))
		{
			gotoXY(18, x); cout << "  ";
			x = 11;
			gotoXY(18, x); cout << "->";
			menu_item = 1;
			continue;
		}
		else if (GetAsyncKeyState(0x33))
		{
			gotoXY(18, x); cout << "  ";
			x = 12;
			gotoXY(18, x); cout << "->";
			menu_item = 2;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			//dependendo da posicao da seta no menu, ao carregar enter vera o valor do menu_item correspondente a essa linha e executa a opcao escolhida

			switch (menu_item) {

			case 0: {

				int noid;
				gotoXY(20,17);
				noid = chooseRua(em);
				switch(typeFlag)
				{
				case 1:
					em.getCall(noid,0,1,0, false);
					break;
				case 2:
					em.getCall(noid,1,0,0, false);
					break;
				case 3:
					em.getCall(noid,0,0,1, false);
					break;
				}
				Sleep(2000);
				em.resetGV();
				running = false;
				system("CLS");

				break;
			}


			case 1: {


				int noid;
				gotoXY(20,17);
				noid = chooseRua(em);
				switch(typeFlag)
				{
				case 1:
					em.getCall(noid,1,1,0, false);
					break;
				case 2:
					em.getCall(noid,1,0,1, false);
					break;
				case 3:
					em.getCall(noid,1,0,1, true);
					break;
				}
				Sleep(2000);
				em.resetGV();
				running = false;
				system("CLS");

				break;
			}

			case 2: {

				int noid;
				gotoXY(20,17);
				noid = chooseRua(em);
				switch(typeFlag)
				{
					case 1:
					{
					em.getCall(noid,1,2,1,true);
					break;
					}


					case 2:
					{
					em.getCall(noid,2,1,1, true);
						break;
					}

					case 3:
					{
					em.getCall(noid,1,1,2, true);
						break;
					}

				}
				Sleep(2000);
				em.resetGV();
				running = false;
				system("CLS");
				break;
			}




			}

		}

	}

	gotoXY(20, 17);// para que a mensagem de fechar o programa "Press any key to continue..." se encontra uma linha apos o cout apresentado ao querer sair do programa
	return;
}

int chooseRua(Emergencia &em)
{
	int menu_item = 0, x = 10, x2 = 10,pagina = 0;
		bool running = true;
		bool mini_flag = false;
		bool ultima_pag = false;
		bool ultima_pag_2 = false;
		system("CLS");


		gotoXY(18, 10); cout << "->";
		while (running)
		{
			gotoXY(18, 8); cout << "Lista de ruas";

			if (mini_flag == false)
			{
				for (int i = 10; i < 21;i++)
				{
					gotoXY(20, i);
					cout << CLEAN_LINE;
				}
				if (ultima_pag == true)
				{
					for (int i = pagina; i < em.getRuas().size(); i++)
					{
						gotoXY(20, x2);
						cout << em.getRuas().at(i).getNome();
						x2++;
					}
				}
				else
				{
					for (int i = pagina; (i <= pagina + 9); i++)
					{
						gotoXY(20, x2);
						cout << em.getRuas().at(i).getNome();
						x2++;
					}
				}

			}
			system("pause>nul"); // the >nul bit causes it the print no message

			if (!GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
			{
				continue;
			}

			if (GetAsyncKeyState(VK_DOWN) && x != (x2-1)) //down button pressed
			{
				gotoXY(18, x); cout << "  ";
				x++;
				gotoXY(18, x); cout << "->";
				menu_item++;
				mini_flag = true;
				continue;

			}
			else if (GetAsyncKeyState(VK_DOWN) && x == (x2-1))
			{

					gotoXY(18, x); cout << "  ";
					x = 10;
					gotoXY(18, x); cout << "->";
					menu_item = pagina;
				mini_flag = true;
				continue;

			}

			else if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
			{
				gotoXY(18, x); cout << "  ";
				x--;
				gotoXY(18, x); cout << "->";
				menu_item--;
				mini_flag = true;
				ultima_pag = false;
				continue;
			}
			else if (GetAsyncKeyState(VK_UP) && x == 10)
			{
				gotoXY(18, x); cout << "  ";
				x = x2-1;
				gotoXY(18, x); cout << "->";
				mini_flag = true;
				ultima_pag = false;
				menu_item = pagina + 9;
				continue;


			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				/*if ((vc1.getMusicas().size() - pagina < 10) && (vc1.getMusicas().size() - pagina > 0))
				{
					ultima_pag = true;
					menu_item = pagina;
					mini_flag = false;
					x2 = 10;


				}*/
				if (pagina < em.getRuas().size())
				{
					if (pagina + 20 > em.getRuas().size())

					{
						if (ultima_pag_2 == false)
						{
							menu_item = em.getRuas().size() - 1;
							pagina += 10;
							x2 = 10;
							ultima_pag = true;
							mini_flag = false;
							ultima_pag_2 = true;
						}
						else
						{
							mini_flag = true;
						}
					}
					else
					{
						menu_item += 10;
						pagina += 10;
						x2 = 10;
						mini_flag = false;
						ultima_pag = false;
						ultima_pag_2 = false;
					}

				}
				else
					mini_flag = true;

			}
			else if (GetAsyncKeyState(VK_LEFT))
			{

				if (pagina >= 10)
				{
					pagina -= 10;
					menu_item -= 10;
					x2 = 10;
					ultima_pag = false;
					mini_flag = false;
					ultima_pag_2 = false;
				}
				else
					mini_flag = true;
			}


			else if (GetAsyncKeyState(VK_RETURN)) {
				system("CLS");
				return em.getRuas().at(menu_item).getRandNoID();
			}

		}
}

bool chooseAlgorithm()
{

	int menu_item = 0; //usada para saber qual e o caso do switch que esta a apontar
	int 	x = 10; //usada para saber a linha que a seta esta apontar
	bool running = true;
	system("CLS");//cleans cmd




	gotoXY(18, 10); cout << "->";

	while (running)
	{
		gotoXY(18, 8); cout << "Escolha de algoritmo:";
		gotoXY(20, 10);  cout << "1) Dijkstra Algorithm";
		gotoXY(20, 11);  cout << "2) Floyd-Warshall Algorithm";

		system("pause>nul"); // the >nul bit causes it to print no message

		if (!GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(0x31) && !GetAsyncKeyState(0x32) )// se for clicado uma tecla diferente das setas (cima e baixo) e enter, nao faz nada
		{
			continue;
		}

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed and
		{
			gotoXY(18, x); cout << "  ";//limpa seta
			x++;
			gotoXY(18, x); cout << "->";//seta aponta para a proxima linha do menu
			menu_item++;//faz com que este valor seja coerente com a linha que esta apontar
			continue;

		}
		else if (GetAsyncKeyState(VK_DOWN) && x == 11) // se precionar para baixo na ultima linha do menu, volta a primeira linha do mesmo
		{
			gotoXY(18, x); cout << "  ";//"limpa" a seta
			x = 10;//posicao em x da pos inicial
			gotoXY(18, x); cout << "->"; // mete a seta nessa pos inicial
			menu_item = 0;//atribui o caso 0 do switch para a primeira linha como e suposto
			continue;

		}

		else if (GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "->";//seta aponta para a linha anterior
			menu_item--;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x == 10)//se precionar para cima na primeira linha do menu a seta passa a apontar para a ultima linha do mesmo
		{
			gotoXY(18, x); cout << "  ";
			x = 11;//pos em x da pos final do menu (defenido nos couts)
			gotoXY(18, x); cout << "->";//mete seta nessa posicao
			menu_item = 1; // menu_item correspondente a ultima linha do menu
			continue;


		}
		else if (GetAsyncKeyState(0x31))
		{
			gotoXY(18, x); cout << "  ";
			x = 10;
			gotoXY(18, x); cout << "->";
			menu_item = 0;
			continue;
		}
		else if (GetAsyncKeyState(0x32))
		{
			gotoXY(18, x); cout << "  ";
			x = 11;
			gotoXY(18, x); cout << "->";
			menu_item = 1;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed
			//dependendo da posicao da seta no menu, ao carregar enter vera o valor do menu_item correspondente a essa linha e executa a opcao escolhida

			switch (menu_item) {

			case 0: {

				return false;
				break;
			}


			case 1: {
				return true;
				break;
			}




			}

		}

	}


}


// ---------------------- lOCALIZAR CURSOR

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

