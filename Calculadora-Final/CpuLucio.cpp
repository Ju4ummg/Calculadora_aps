#include "CpuLucio.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

Display *CpuLucio::getDisplay() { 
  return this->display;
}

void CpuLucio::setDisplay(Display *display) { 
  this->display = display;
}

void CpuLucio::receiveDigit(Digit digit) {
  if(this->display != nullptr) {
    if (this->operando2Count == 0 && this->operator_ != nullptr) {//limpa a tela quando o primeiro digito do segundo operando chega 
      this->display->clear();
    }
    this->display->add(digit);
  }
  if (this->operator_ == nullptr) {
    this->operando1[this->operando1Count++] = digit;
  } else {
    this->operando2[this->operando2Count++] = digit;
  }
  
}

void CpuLucio::receiveOperator(Operator operator_) { 
  this->operator_ = &operator_;
}

double CpuLucio::convertToDouble(Digit *operando) {
    double digitoOperando = 0;
    for (int i = 0; i < MAX_DIGIT; i++) {
      digitoOperando = digitoOperando * 10 + operando[i];
    }
    return digitoOperando;
}


Digit CpuLucio::convertIntToDigit(int value) {
  switch (value) {
    case 0: return ZERO;
    case 1: return ONE;
    case 2: return TWO;
    case 3: return THREE;
    case 4: return FOUR;
    case 5: return FIVE;
    case 6: return SIX;
    case 7: return SEVEN;
    case 8: return EIGHT;
    case 9: return NINE;
    default: throw "Invalid Int Value to Digit";
  }
}
  
void CpuLucio::convertToDigit(double value_, Digit* destino, int* destinoCont) {
  *destinoCont = 0;
  int value = value_;
  while (value > 0) {
    destino[*destinoCont++] = this->convertIntToDigit(value % 10);
    value /= 10;
  }
  std::reverse(destino, destino + *destinoCont);
}

void CpuLucio::showDigit(Digit *destino, int count){
  for(int i = count - 1; i >= 0; i--) {
    std::cout << destino[i];
  }
  std::cout << std::endl;
}

void CpuLucio::receiveControl(Control control) { 
  if (control == Control::EQUAL) {
    if (*operator_ == Operator::SUM) {
      resultado = convertToDouble(operando1) + convertToDouble(operando2);
    }
    if (*operator_ == Operator::DIVISION) {
      resultado = convertToDouble(operando1)/convertToDouble(operando2);
    }
    if (*operator_ == Operator::PERCENTAGE) {
      resultado = convertToDouble(operando1)/100;
    }
    if (*operator_ == Operator::SUBTRACTION) {
      resultado = convertToDouble(operando1) - convertToDouble(operando2);
    }
    if (*operator_ == Operator::MULTIPLICATION) {
      resultado = convertToDouble(operando1) * convertToDouble(operando2);
    }
    if (*operator_ == Operator::SQUARE_ROOT) {
      resultado = sqrt(convertToDouble(operando1));
    }
    
    Digit resultadoDigit[MAX_DIGIT];
    int resultadoCount;
    convertToDigit(resultado, resultadoDigit, &resultadoCount);

    // Exibir os dígitos do resultado
    showDigit(resultadoDigit, resultadoCount);

    //Limpar operandos
    this->operando1Count = 0;
    this->operando2Count = 0;
    this->operator_ = nullptr;
    }

  }
  
}
