#pragma once

#include "CalculatorInterfaces.hpp"
#include <cmath>
#define MAX_DIGIT 8

class CpuLucio: public Cpu{
  private:
    Display* display;

    Digit operando1[MAX_DIGIT];
    Digit operando2[MAX_DIGIT];
    int operando1Count = 0;
    int operando2Count = 0;

    Operator* operator_ = nullptr;

    Digit operando[MAX_DIGIT];
    double resultado = 0;
    int digitoOperando = 0;
    double convertToDouble(Digit*);
    void convertToDigit(double, Digit*, int*);
    Digit convertIntToDigit(int);
    void showDigit(Digit*, int);

  public:
    Display* getDisplay();
    void setDisplay(Display*);

    void receiveDigit(Digit);
    void receiveOperator(Operator);
    void receiveControl(Control);
};