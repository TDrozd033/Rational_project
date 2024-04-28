
#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
  Rational r1(1, 3);
  cout << "r1 = " << r1 << endl;

  Rational r2;
  cout << "Wprowadz  r2: ";
  cin >> r2;
  cout << "r2 = " << r2 << endl << endl;

  //suma
  Rational sum = r1 + r2;
  cout << "r1 + r2 = " << sum << endl;
  cout << "Wartosc double: " << sum.Value() << endl << endl;

  //roznica
  Rational sub = r1 - r2;
  cout << "r1 - r2 = " << sub << endl;
  cout << "Wartosc double: " << sub.Value() << endl << endl;
  //mnozenie
  Rational mul = r1 * r2;
  cout << "r1 * r2 = " << mul << endl;
  cout << "Wartosc double: " << mul.Value() << endl << endl;

  //dzielenie
  Rational div = r1 / r2;
  cout << "r1 / r2 = " << div << endl;
  cout << "Wartosc double: " << div.Value() << endl << endl;
  return 0;
}



