#include "Rational.h"


Rational:: Rational(int m_Numerator, int m_Denominator)
{
  SetRational(m_Numerator, m_Denominator);
}
Rational::Rational(const Rational& r)
{
  *this = r;
}

Rational:: ~Rational()
{

}




Rational& Rational::operator=(const Rational& r)
{
  if (this != &r) // zapobiegamy samoprzypisaniu 
  {
    if (GetNumerat() != r.GetNumerat() || GetDenominat() != r.GetDenominat())
    {
      m_Numerator = r.GetNumerat();
      m_Denominator = r.GetDenominat();
    }
  }
  return *this;
}


/*
zdefiniowaæ operatory wejœcia (wczytujemy dwie liczby przedzielone bia³ym znakiem) i
wyjœcia (wypisaæ w postaci <licznik>/<mianownik> Np. 2/5)
*/

// input/output
istream& operator >> (istream& in, Rational& r)
{
  int num;
  int denum;
  in >> num >> denum;
  r.SetRational(num, denum);
  return in;
}
 ostream& operator << (ostream& out, const Rational& r)
{
   out << r.m_Numerator << '/' << r.m_Denominator << endl;
   return out;
}

 

 const  Rational operator + (const Rational& r1, const Rational& r2)
{
   Rational res(r1);
   return res += r2;
}
 const  Rational operator - (const Rational& r1, const Rational& r2)
{
   Rational res(r1);
   return res -= r2;
}
 const  Rational operator * (const Rational& r1, const Rational& r2)
{
   Rational res(r1);
   return res *= r2;
}
const Rational operator / (const Rational& r1, const Rational& r2)
{
  Rational res(r1);
  return res /= r2;
}



// sprowadzamy do wspolnego mianownika jesli s¹ ró¿ne 
Rational& Rational::operator +=(const Rational& r)
{
  int licznik_1 = this->GetNumerat();
  int mianownik_1 = this->GetDenominat();
  int licznik_2 = r.GetNumerat();
  int mianownik_2 = r.GetDenominat();
  // jesli mianowniki rozne to mnozymy licznik1 * mianownik2 i licznik2 * mianownik1, mianownik1 * mianownik2 i mianownik2 * mianownik1
  if (mianownik_1 != mianownik_2)
  {
    licznik_1 *= mianownik_2;
    licznik_2 *= mianownik_1;
    mianownik_1 *= mianownik_2;
   // mianownik_2 = mianownik_1;
  }

  // teraz uzywamy nwd zeby skrocic ulamek
  int nwd = getNwd((licznik_1 + licznik_2), mianownik_1);
  this->SetRational((licznik_1 + licznik_2) / nwd, mianownik_1 / nwd);
  return *this;

}

// sprowadzamy do wspolnego mianownika jesli s¹ rózne 
Rational& Rational::operator -=(const Rational& r)
{
  int licznik_1 = this->GetNumerat();
  int mianownik_1 = this->GetDenominat();
  int licznik_2 = r.GetNumerat();
  int mianownik_2 = r.GetDenominat();
  // jesli mianowniki rozne to mnozymy licznik1 * mianownik2 i licznik2 * mianownik1, mianownik1 * mianownik2 i mianownik2 * mianownik1
  if (mianownik_1 != mianownik_2)
  {
    licznik_1 *= mianownik_2;
    licznik_2 *= mianownik_1;
    mianownik_1 *= mianownik_2;
   // mianownik_2 = mianownik_1;
  }

  // teraz uzywamy nwd zeby skrocic ulamek
  int nwd = getNwd((licznik_1 - licznik_2), mianownik_1);
  this->SetRational((licznik_1 - licznik_2) / nwd, mianownik_1 / nwd);
  return *this;

}

// mnozymy licznik * licznik i mianownik * mianownik i pozniej sprwoasdzamy do wspolnego mian uzywajac nwd
Rational& Rational :: operator *=(const Rational& r)
{
  int licznik = GetNumerat() * r.GetNumerat();
  int mianownik = GetDenominat() * r.GetDenominat();

  int nwd = getNwd(licznik, mianownik);
  SetRational(licznik / nwd, mianownik / nwd);
  return *this;
}

// pierszy ulamek mnozymy * odwrotnosc drugiego czyli w drugim ulamku zamieniamy licznik  zmianownikiem 
Rational& Rational::operator /=(const Rational& r)
{
  int licznik = GetNumerat() * r.GetDenominat();
  int mianownik = GetDenominat() * r.GetNumerat();

  int nwd = getNwd(licznik, mianownik);
  SetRational(licznik / nwd, mianownik / nwd);
  return *this;
}
