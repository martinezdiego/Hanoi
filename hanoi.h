/*
 *  Diego Martinez
 *  diegomartinez6c@gmail.com
 * 
 *  Oscar Albornoz
 *  oalbornoz08@gmail.com
 */
#ifndef HANOI_H
#define HANOI_H

#include <iostream>
#include <cctype>
#include <stack>
#include <vector>

using namespace std;

class Hanoi
{
  public:
    explicit Hanoi(int);

    Hanoi(const Hanoi &);
    
    Hanoi(Hanoi &&);
    
    Hanoi & operator = (const Hanoi &);
    
    Hanoi & operator = (Hanoi &&);

    // retorna la cantidad de discos 
    int size() const;

    // verifica si se movieron todos los discos de src a dst
    bool areMovedAllDiscs() const;

    // imprime las torres
    void print();
    
    // mueve un disco entre las estacas 
    void move();

    // arropa la siguiente funcion
    void solve(); 

  private:
    vector<stack<int>> pegs;
    int height;

    // soluciona el puzzle de forma eficiente 
    void solve(int, int, int, int, int &);
};

#endif