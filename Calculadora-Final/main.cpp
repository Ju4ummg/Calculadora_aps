#include "CalculatorTests.hpp"

#include "DisplayLucio.hpp"
#include "KeyboardLucio.hpp"
#include "KeyLucio.hpp"
#include "CpuLucio.hpp"

#include <iostream>

int main() {

  try{
  Display* display1 = new DisplayLucio();

  Cpu* cpu1 = new CpuLucio();

  Key* keyOne = new KeyDigitLucio("1", Digit::ONE);
  Key* keyOperator = new KeyOperatorLucio("+", Operator::SUM);
  Key* keyControl = new KeyControlLucio("CE", Control::CLEAR_ERROR);

  Keyboard* keyboard1 = new KeyboardLucio();

  /* Build Calculator */
  cpu1->setDisplay(display1);
  keyboard1->setCpu(cpu1);
  
  keyboard1->addKey(keyOne);
  keyboard1->addKey(keyOperator);
  keyboard1->addKey(keyControl);
  
  // /* Testing... */
    keyboard1->findKey("1")->press();
    keyboard1->findKey("+")->press();
    keyboard1->findKey("1")->press();
    keyboard1->findKey("=")->press();
  
  CalculatorTests::pause();
  CalculatorTests::setPauseAfterTests(true);

  CalculatorTests::testDisplay(display1);
  CalculatorTests::testKeyboard(keyboard1);


   
  // display1->showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();
 // display1->mostrarDigitos();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();


 // display1->Display::showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();
// display1->showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();


  // Calculator calculator1;

  // calculator1.getKeyboard().getKey("1").press();
  // calculator1.getKeyboard().getKey("+").press();
  // calculator1.getKeyboard().getKey("1").press();
  // calculator1.getKeyboard().getKey("=").press();
  }catch(const char* bolinha){
    std::cout << bolinha;
  }
}