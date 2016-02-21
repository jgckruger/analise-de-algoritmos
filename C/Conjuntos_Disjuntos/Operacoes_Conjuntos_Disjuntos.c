#include <cstdio>

#define NUM_ELEMENTOS 100

/*
Algoritmo para conjuntos disjuntos
Operações MakeSet, FindSet e Union/Merge.

Essa abordagem consiste em criar uma árvore para cada conjunto e ir concatenando elas (as ligando).

Já estão aplicadas as duas heurísticas Union by Rank e Path Compression.
*/

int p[NUM_ELEMENTOS];
// Define a árvore, sendo que o índice seria um identificador para o conjunto, e o valor para quem o elemento aponta.

int ordem[NUM_ELEMENTOS];
// Define o rank(altura) da árvore, possibilitando melhoras na eficiêcia do algoritmo(Heurística Path Compression).


void MakeSet(int x) // Operação MakeSet. Cria um conjunto.
{
     p[x]=x; // Faz com que o elemento x aponte para si mesmo.
     ordem[x]=0; // Define a altura da árvore (0).
}

int FindSet(int x) // Operação FindSet. Retorna a raiz da árvore(o conjunto a que pertence tal elemento).
{
    if(x!=p[x]) // Se não for raiz (não apontar para si mesmo).
        p[x] = FindSet(p[x]); // Chamada recursiva, faz com que na busca, otimize a árvore fazendo o elemento apontar para a raiz.
    return p[x]; // Retorna raiz da árvore.
}

void Link(int x,int y) // Liga um elemento em outro.
{
    if(ordem[x] > ordem[y]) // Se conjunto 1 é maior com que o conjunto 2.
    {
        p[y] = x; // Faz com que o conjunto 2 aponte para o conjunto 1.
     }
    else // Se não (Conjunto 2 maior ou igual ao conjunto 1).
    {
        p[x] = y; // Conjunto 1 aponta para o conjunto 2).
        if(ordem[x]==ordem[y]) // Se são da mesma altura.
            ordem[y]++; // Aumenta em 1 a altura da árvore 2.
     }
}

void Union(int x,int y) // Operação de união. Une dois conjuntos em um só.
{
     Link(FindSet(x),FindSet(y)); // Liga o líder do conjunto menor no líder conjunto maior.
}

/*
bool SameSet(int x,int y) // Função com finalidade de ver se estão no mesmo conjunto. Apenas para C++(tipo bool).
{
    if(FindSet(x)==FindSet(y)) // Se possuem o mesmo líder.
        return true;
    else                       // Se estão em conjuntos diferentes.
        return false;
}
*/

int SameSet(int x,int y) // Função com finalidade de ver se estão no mesmo conjunto. C e C++.
{
    if(FindSet(x)==FindSet(y)) // Se possuem o mesmo líder.
        return 1;
    else                       // Se estão em conjuntos diferentes.
        return 0;
}


/*
    Material estudado:

http://www.facom.ufms.br/~marco/analise2007/aula16_4.pdf
http://user.das.ufsc.br/~camponog/Disciplinas/DAS-9003/slides_CLR/l12-union-find.pdf
http://www.ic.unicamp.br/~zanoni/mo637/aulas/conjuntosDisjuntos.pdf
http://marathoncode.blogspot.com.br/2012/07/pilha-umapilha-e-uma-das-varias.html
http://marathoncode.blogspot.com.br/2013/01/conjuntos-disjuntos.html
http://www.ime.usp.br/~coelho/algoritmos/aulas/material/aula22.pdf
http://professor.ufabc.edu.br/~leticia.bueno/classes/aed2/materiais/unionfind.pdf
http://www.fernandolobo.info/aed-II/teoricas/a23.print.pdf
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
https://en.wikipedia.org/wiki/Ackermann_function
*/
