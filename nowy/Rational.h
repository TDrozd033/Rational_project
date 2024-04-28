#pragma once
#include <iostream>

using namespace std;

/* 

Wykreowa� now� aplikacj� konsolow� o nazwie RationalTest
Zdefiniowa� klas� o nazwie Rational do reprezentacji u�amk�w (o sk�adowych
m_Numerator - licznik, m_Denominator � mianownik, oba typu int oraz metody
klasy:
 konstruktor z parametrami domy�lnymi (licznik 0, mianownik 1),
konstruktor kopiuj�cy,
 operator podstawienia,
 SetNumerator( int Num ); SetDenominator( int Denum ); ustawiaj�ce
odpowiednio sk�adow� licznika i sk�adow� mianownika.
 SetRational( int num, int denum ); ustawia u�amek
 GetNumerat(); GetDenominat(); zwracaj�ce odpowiednio warto�� sk�adowej
licznika i sk�adowej mianownika.
 operator dodawania i odejmowania, mno�enia i dzielenia u�amk�w:
 odpowiednie operatory += , -=, *= oraz /= (po wykonaniu operacji skr�ci� je�li to
mo�liwe)
 Funkcje Value()zwracaj�cej warto�� u�amka w postaci liczy rzeczywistej (double)
 Operator rzutowania na double
zdefiniowa� operatory wej�cia (wczytujemy dwie liczby przedzielone bia�ym znakiem) i
wyj�cia (wypisa� w postaci <licznik>/<mianownik> Np. 2/5)
W programie zdefiniowa� u�amek 1/3 oraz wczyta� dowolny drugi u�amek. Odpowiednio
obliczy� sum�, r�nic� iloczyn, oraz iloraz. Obliczy� warto�� funkcji Value() dla
otrzymanego wyniku.


*/
class Rational
{

  /* 
  Zdefiniowa� klas� o nazwie Rational do reprezentacji u�amk�w (o sk�adowych
m_Numerator - licznik, m_Denominator � mianownik, oba typu int oraz metody
klasy:
 konstruktor z parametrami domy�lnymi (licznik 0, mianownik 1),*/
public: 
  Rational(int m_Numerator = 0, int m_Denominator = 1);
  Rational(const Rational& r);

  virtual ~Rational();


public: 
  /*
   SetNumerator(int Num); SetDenominator(int Denum); ustawiaj�ce
    odpowiednio sk�adow� licznika i sk�adow� mianownika.
     SetRational(int num, int denum); ustawia u�amek
     GetNumerat(); GetDenominat(); zwracaj�ce odpowiednio warto�� sk�adowej
    licznika i sk�adowej mianownika.

    */

  void SetNumerator(int Num);
  void SetDenominator(int Denum);
  void SetRational(int num, int denum);

  int GetNumerat()const;
  int GetDenominat()const;
  //--assignment
  Rational& operator = (const Rational& r);


  // input/output
  friend istream& operator >> (istream& in, Rational& r);
  friend ostream& operator << (ostream& out, const Rational& r);

  /*
   operator dodawania i odejmowania, mno�enia i dzielenia u�amk�w:
 odpowiednie operatory += , -=, *= oraz /= (po wykonaniu operacji skr�ci� je�li to
mo�liwe)
*/
  friend const Rational operator + (const Rational& r1, const Rational& r2);
  friend const Rational operator - (const Rational& r1, const Rational& r2);
  friend const Rational operator * (const Rational& r1, const Rational& r2);
  friend const Rational operator / (const Rational& r1, const Rational& r2);


  Rational& operator +=(const Rational& r);
  Rational& operator -=(const Rational& r);
  Rational& operator *=(const Rational& r);
  Rational& operator /=(const Rational& r);

  double Value()const;

  operator double() const;
private:

  int getNwd(int x, int y);



private:

 //licznik
  int m_Numerator;
  //mianownik
  int m_Denominator;



};



// ---------INLINE FUNCTIONS------------

inline void Rational:: SetNumerator(int Num)
{
  m_Numerator = Num;
}
inline void Rational::SetDenominator(int Denum)
{
  if (!Denum)
  {
    cerr << "Mianownik r�wny 0!" << endl;
  }
  m_Denominator = Denum;
}
inline void Rational::SetRational(int num, int denum)
{
  m_Numerator = num;
  m_Denominator = denum;
}

inline int Rational::GetNumerat()const
{
  return m_Numerator;
}
inline int Rational:: GetDenominat()const
{
  return m_Denominator;
}

inline double Rational :: Value()const
{
  double res = (double)GetNumerat();
  double temp = (double)GetDenominat();
  return res / temp;

}

inline Rational:: operator double() const
{
  return Value();

}


inline int Rational::getNwd(int x, int y)
{
  while (y) 
  {
    int r = x % y;
     x = y;
    y = r;
  }

  return x;
}