#include "KeyboardLucio.hpp"


void KeyboardLucio::addKey(Key *key) {
  for (int i = 0; i < keysCount; i++) {
    if (key == this->keys[i]) {
      throw "ERROR: Duplicated Key";
    }
  }
  this->keys[this->keysCount++] = key;
  key->setKeyboard(this); /* Connect this keyboard with new key */
}

void KeyboardLucio::removeKey(Key *key) {
  int index = -1;
  for (int i = 0; i < keysCount; i++) {
    if (key == this->keys[i]) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = index; i < keysCount - 1; i++) {
      this->keys[i] = this->keys[i + 1];
    }
    this->keysCount--;
  } else {
    throw "ERROR: Key not found";
  }
}

#include "cstring"
Key *KeyboardLucio::findKey(Symbol symbol) {
  for (char i = 0; i < this->keysCount; i++)
    if (strcmp(symbol, this->keys[i]->getSymbol()) == 0)
      return this->keys[i];

  throw "Key not found!";
}

void KeyboardLucio::setCpu(Cpu *cpu) { this->cpu = cpu; }

Cpu *KeyboardLucio::getCpu() { return this->cpu; }
