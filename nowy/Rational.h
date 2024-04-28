#pragma once
#include <iostream>

using namespace std;

/* 

Wykreowaæ now¹ aplikacjê konsolow¹ o nazwie RationalTest
Zdefiniowaæ klasê o nazwie Rational do reprezentacji u³amków (o sk³adowych
m_Numerator - licznik, m_Denominator – mianownik, oba typu int oraz metody
klasy:
 konstruktor z parametrami domyœlnymi (licznik 0, mianownik 1),
konstruktor kopiuj¹cy,
 operator podstawienia,
 SetNumerator( int Num ); SetDenominator( int Denum ); ustawiaj¹ce
odpowiednio sk³adow¹ licznika i sk³adow¹ mianownika.
 SetRational( int num, int denum ); ustawia u³amek
 GetNumerat(); GetDenominat(); zwracaj¹ce odpowiednio wartoœæ sk³adowej
licznika i sk³adowej mianownika.
 operator dodawania i odejmowania, mno¿enia i dzielenia u³amków:
 odpowiednie operatory += , -=, *= oraz /= (po wykonaniu operacji skróciæ jeœli to
mo¿liwe)
 Funkcje Value()zwracaj¹cej wartoœæ u³amka w postaci liczy rzeczywistej (double)
 Operator rzutowania na double
zdefiniowaæ operatory wejœcia (wczytujemy dwie liczby przedzielone bia³ym znakiem) i
wyjœcia (wypisaæ w postaci <licznik>/<mianownik> Np. 2/5)
W programie zdefiniowaæ u³amek 1/3 oraz wczytaæ dowolny drugi u³amek. Odpowiednio
obliczyæ sumê, ró¿nicê iloczyn, oraz iloraz. Obliczyæ wartoœæ funkcji Value() dla
otrzymanego wyniku.


*/
class Rational
{

  /* 
  Zdefiniowaæ klasê o nazwie Rational do reprezentacji u³amków (o sk³adowych
m_Numerator - licznik, m_Denominator – mianownik, oba typu int oraz metody
klasy:
 konstruktor z parametrami domyœlnymi (licznik 0, mianownik 1),*/
public: 
  Rational(int m_Numerator = 0, int m_Denominator = 1);
  Rational(const Rational& r);

  virtual ~Rational();


public: 
  /*
   SetNumerator(int Num); SetDenominator(int Denum); ustawiaj¹ce
    odpowiednio sk³adow¹ licznika i sk³adow¹ mianownika.
     SetRational(int num, int denum); ustawia u³amek
     GetNumerat(); GetDenominat(); zwracaj¹ce odpowiednio wartoœæ sk³adowej
    licznika i sk³adowej mianownika.

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
   operator dodawania i odejmowania, mno¿enia i dzielenia u³amków:
 odpowiednie operatory += , -=, *= oraz /= (po wykonaniu operacji skróciæ jeœli to
mo¿liwe)
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
    cerr << "Mianownik równy 0!" << endl;
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