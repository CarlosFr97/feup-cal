Caso queira compilar o codigo, basta usar os ficheiros .cpp e .h que se encontram na pasta Codigo Fonte,no entanto, isso não é necessário
visto que já fornecemos o executavel do projeto pronto a rodar. Psra correr o programa, basta rodar o executavel Emergencia.exe que se encontra na pasta
Executavel - Emergencia. Note que nessa mesma pasta esta contido ficheiros de txts,imagens png ,e um jar, este elementos sao necessário estar no mesmo diretorio
do executavel com o nome dado como se encontra em Executavel-Emergencia (ex: ajuda1.png, ruas.txt os ficheiros necessitam de ter este nome para o programa os reconhecer)
de forma o programa conseguir interpretar o grafo que se baseia.

//INVALIDO PARA ESTA VERSAO
Note que na pasta Ficheiros de leitura para além de existir os ficheiros de texto que se encontram na pasta do executavel (ruas.txt,hospitais.txt,etc) existem outros
ficheiros com uma numeracao diferente(ruas4.txt,etc). Estes ficheiros representam outros grafos que foram estudados  na execucao do programa meramente para o teste 
de tempo de execucao (um grafo de 100 nos,outro de 500 e mais um  de 1000). Se quiser,por alguma razao, verificar o programa a rodar esses grafos e necessario copiar os ficheiros
txt que representa esse mesmo grafo (2,3 ou 4) e metelos junto com o executavel sem a numeracao ou seja, para as ruas4.txt  rodar com o executavel tem de se chamar ruas.txt. 
Estes outros grafos como foram usados plenamente para teste nao representam de forma alguma um mapa real.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//UPDATE
Note que agora na pasta de Ficheiros de leitura apenas existe os ficheiros de texto que se encontram na pasta do executavel,mais um ficheiro chamado
ruas_naoconexo.txt este ficheiro representa uma versao nao conexa do grafo lido pelo programa, ao seja se quiser verificar se o programa de facto calcula a conetividade do grafo
a partir das componentes fortemente conexas, e necessario substituir o ficheiro ruas_naoconexo.txt na pasta do executavel pelo ficheiro ruas.txt (altere o nome de ruas_naoconexo.txt para apenas ruas.txt)
assim o programa desenha e interpreta um grafo nao conexo.

ATENCAO: O programa nao permite o uso de grafos nao conexos,ou seja, ele verifica que o grafo nao e conexo logo nao permite a realizaçao de chamadas as urgencias.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Por vezes, apos escolher o algoritmo a ser usado pode aparecer o erro "Client: connect() - Failed to connect. Unable to send". Este erro e um erro do GraphViewer por isso a unica solucao sera
reiniciar o programa.