//Mateusz Paszynski
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
struct Zestaw{
    int i;
    string s;
    char c;
    bool b1;
    unsigned char c1;
    float f1;
    bool b2;
    unsigned char c2;
    float f2;
    bool b3;
    unsigned char c3;
    float f3;
    bool b4;
    unsigned char c4;
    float f4;
    int suma;
};
void wczytaj(fstream& wej,Zestaw& zestaw){
        string smieci;
        int p1,p2,p3,p4;
        wej>>zestaw.i;
        getline(wej,smieci);
        getline(wej,zestaw.s);
        wej.get(zestaw.c);
        wej>>zestaw.b1>>p1>>zestaw.f1;
        getline(wej,smieci);
        wej>>zestaw.b2>>p2>>zestaw.f2;
        getline(wej,smieci);
        wej>>zestaw.b3>>p3>>zestaw.f3;
        getline(wej,smieci);
        wej>>zestaw.b4>>p4>>zestaw.f4;
        getline(wej,smieci);
        zestaw.c1 = p1;
        zestaw.c2 = p2;
        zestaw.c3 = p3;
        zestaw.c4 = p4;
        zestaw.suma=p1+p2+p3+p4;
        zestaw.suma=zestaw.suma%256;
}
void wypisz(fstream& wej1,Zestaw & zestaw){
            wej1<<zestaw.i<<endl<<zestaw.s<<endl<<zestaw.c<<endl;
            wej1<<zestaw.b1<<" "<<(int)zestaw.c1<<" "<<zestaw.f1<<endl;
            wej1<<zestaw.b2<<" "<<(int)zestaw.c2<<" "<<zestaw.f2<<endl;
            wej1<<zestaw.b3<<" "<<(int)zestaw.c3<<" "<<zestaw.f3<<endl;
            wej1<<zestaw.b4<<" "<<(int)zestaw.c4<<" "<<zestaw.f4<<endl;
}
bool czyjest(string plik,int szukana){
    fstream wej;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    do
    {
        int x,y;
        wej>>x>>y;
        if ( szukana == x)
        {
            wej.close();
            return 1;
        }
        if ( wej.eof())
        {
            break;
        }
    }
    while(true);
    {
        wej.close();
    }
        return 0;
}
void sortrazjeszcze(string plik,string plik1,int dane){
    fstream wej,wej1;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
    int x,y;
    int licz = 0;
    for ( int i =0;i<=dane;i++)
    {
            long long maxx=-9223372036854775806,maxy=0;
            wej.seekg(0,ios::beg);
            wej.seekp(0,ios::beg);
            for ( int j = 0;j<=dane;j++)
            {
                wej>>x>>y;
                if ( j==0)
                {
                    if( czyjest(plik1,x)==0)
                    {
                        maxx=x;
                        maxy=y;
                    }
                }
                if ( y>maxy && czyjest(plik1,x)==0)
                {
                    maxx=x;
                    maxy=y;
                }
            }
            wej1<<maxx<<" "<<maxy<<endl;
    }
wej.close();
wej1.close();
}
void SortInt ( string plik,string plik1,string plik2){
    fstream wej,wej1,wej2;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej2.open(plik2.c_str(),ios::trunc | fstream :: in | fstream :: out);
    string smieci;
    int p1,p2,p3,p4,dane=0;
    int licznik = 0;
    do
    {
        Zestaw zestaw,p;
        wczytaj(wej,zestaw);
        if ( wej.eof())
        {
            break;
        }
        if ( licznik == 0)
        {
            wypisz(wej1,zestaw);
        }
        else
        {
            wej1.close();
            wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
            for ( int i = 0;i<licznik;i++)
            {
                wczytaj(wej1,p);
                if ( zestaw.i < p.i)
                {
                    wej1.close();
                    wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
                    for ( int j = 0;j<i;j++)
                    {
                    Zestaw pod;
                    wczytaj(wej1,pod);
                    wypisz(wej2,pod);
                    }
                    wypisz(wej2,zestaw);
                    for ( int j = i;j<licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej1,pod);
                        wypisz(wej2,pod);
                    }
                    wej1.close();
                    wej1.open(plik1.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    wej2.close();
                    wej2.open(plik2.c_str(),fstream :: in | fstream :: out);
                    for ( int j=0;j<=licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej2,pod);
                        wypisz(wej1,pod);
                    }
                    wej2.close();
                    wej2.open(plik2.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    break;
                }
                if ( i==licznik-1 && zestaw.i>=p.i )
                {
                    wypisz(wej1,zestaw);
                }
            }
        }
        licznik++;
        dane++;
    }
    while(true);
    {
        wej.close();
    }
    wej2.close();
    wej.open(plik.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.close();
    wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
    for ( int i = 0;i<licznik;i++)
    {
        Zestaw podmiana;
        wczytaj(wej1,podmiana);
        wypisz(wej,podmiana);
    }
    wej1.close();
    wej.close();
}
void SymmetricDifference (string plik, string plik1,string plik2){
    fstream wej,wej1,wej2;
    wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
    wej2.open(plik2.c_str(),ios:: trunc | fstream :: in | fstream :: out);
    int p1,p2,p3,p4;
    int dane= 0;
    int num=-1;
    string smieci;
    do
    {
        Zestaw zestaw,p;
        wczytaj(wej1,zestaw);
        if ( wej1.eof())
        {
            break;
        }
        int po = 0;
        int licznik = 0 ;
        wej.open(plik.c_str(),fstream :: in | fstream :: out);
        do
        {
            wczytaj(wej,p);
            if ( wej.eof())
            {
                num=po;
                if ( num==licznik)
            {
                wej.close();
                wej.open(plik.c_str(),fstream :: in | fstream :: out);
                wej.seekg(0,ios::end);
                wej.seekp(0,ios::end);
                wypisz(wej,zestaw);
            }
                break;
            }
            if ( p.i == zestaw.i  && p.s == zestaw.s && p.c == zestaw.c &&p.b1 == zestaw.b1 && p.c1 ==zestaw.c1
                && p.f1 ==zestaw.f1 &&p.b2 == zestaw.b2 && p.c2 ==zestaw.c2 && p.f2 ==zestaw.f2 &&p.b3 == zestaw.b3
                && p.c3 ==zestaw.c3 && p.f3 ==zestaw.f3 &&p.b4 == zestaw.b4 && p.c4 ==zestaw.c4 && p.f4 ==zestaw.f4)
            {
                wypisz(wej2,p);
                break;
            }
            else licznik++;
            po++;
        }
        while(true);
        {
            wej.close();
        }
dane++;
    }
    while(true);
    {
        wej1.close();
    }
    wej2.close();
    wej1.open(plik1.c_str(),ios::trunc |fstream :: in | fstream :: out);
    wej2.open(plik2.c_str(),fstream :: in | fstream :: out);
    do
    {
        Zestaw z;
        wczytaj(wej2,z);
      if(wej2.eof())
      {
          break;
      }
      wypisz(wej1,z);
    }
    while(true);
    {
        wej2.close();
        wej1.close();
    }
}
int ReverseSortInt ( string plik,string plik1,string plik2){
    fstream wej,wej1,wej2;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.close();
    wej1.open(plik1.c_str(), fstream :: in | fstream :: out);
    wej2.open(plik2.c_str(),ios::trunc | fstream :: in | fstream :: out);
    string smieci;
    int p1,p2,p3,p4,dane=0;
    int licznik = 0;
    bool flaga=0;
    do
    {
        Zestaw zestaw,p;
        wczytaj(wej,zestaw);
        if ( wej.eof())
        {
            break;
        }
        if ( licznik == 0)
        {
            wypisz(wej1,zestaw);
            wej1.close();
            wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
        }
        else
        {
            wej1.close();
            wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
            for ( int i = 0;i<licznik;i++)
            {
                flaga=0;
                wczytaj(wej1,p);
                if ( zestaw.i >= p.i)
                {
                    wej1.close();
                    wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
                    for ( int j = 0;j<i;j++)
                    {
                    Zestaw pod;
                    wczytaj(wej1,pod);
                    wypisz(wej2,pod);
                    }
                    wypisz(wej2,zestaw);
                    for ( int j = i;j<licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej1,pod);
                        wypisz(wej2,pod);
                    }
                    wej1.close();
                    wej1.open(plik1.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    wej2.close();
                    wej2.open(plik2.c_str(),fstream :: in | fstream :: out);
                    for ( int j=0;j<=licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej2,pod);
                        wypisz(wej1,pod);
                    }
                    wej2.close();
                    wej2.open(plik2.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    break;
                }
                if ( i==licznik-1 && zestaw.i<p.i )
                {
                    wypisz(wej1,zestaw);
                }
            }
        }
        licznik++;
        dane++;
    }
    while(true);
    {
        wej.close();
    }
    wej2.close();
    wej.open(plik.c_str(),ios::trunc | fstream :: in | fstream :: out);
            wej1.close();
            wej1.open(plik1.c_str(),fstream :: in | fstream :: out);
    for ( int i = 0;i<licznik;i++)
    {
        Zestaw podmiana;
        wczytaj(wej1,podmiana);
        wypisz(wej,podmiana);
    }
    wej1.close();
    wej.close();
    return dane;
}
int sortcar( string plik,string plik1,string plik2){
    ReverseSortInt(plik,plik1,plik2);
    fstream wej,wej1,wej2;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.close();
    wej1.open(plik1.c_str(), fstream :: in | fstream :: out);
     wej2.open(plik2.c_str(),ios::trunc | fstream :: in | fstream :: out);
    string smieci;
    int p1,p2,p3,p4,dane=0;
    int licznik = 0;
    do
    {
        Zestaw zestaw,p;
        wczytaj(wej,zestaw);
        if ( wej.eof())
        {
            break;
        }
        if ( licznik == 0)
        {
            wypisz(wej1,zestaw);
            wej1.seekg(0,ios::beg);
            wej1.seekp(0,ios::beg);
        }
        else
        {
            wej1.seekg(0,ios::beg);
            wej1.seekp(0,ios::beg);
            for ( int i = 0;i<licznik;i++)
            {
                wczytaj(wej1,p);
                if ( zestaw.suma <= p.suma)
                {
                    wej1.seekg(0,ios::beg);
                    for ( int j = 0;j<i;j++)
                    {
                    Zestaw pod;
                    wczytaj(wej1,pod);
                    wypisz(wej2,pod);
                    }

                    wej2<<zestaw.i<<endl<<zestaw.s<<endl<<zestaw.c<<endl;
                    wej2<<zestaw.b1<<" "<<(int)zestaw.c1<<" "<<zestaw.f1<<endl;
                    wej2<<zestaw.b2<<" "<<(int)zestaw.c2<<" "<<zestaw.f2<<endl;
                    wej2<<zestaw.b3<<" "<<(int)zestaw.c3<<" "<<zestaw.f3<<endl;
                    wej2<<zestaw.b4<<" "<<(int)zestaw.c4<<" "<<zestaw.f4<<endl;
                    for ( int j = i;j<licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej1,pod);
                        wypisz(wej2,pod);
                    }
                    wej1.close();
                    wej1.open(plik1.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    wej2.seekg(0,ios::beg);
                    wej2.seekp(0,ios::beg);
                    for ( int j=0;j<=licznik ;j++)
                    {
                        Zestaw pod;
                    wczytaj(wej2,pod);
                    wypisz(wej1,pod);
                    }
                    wej2.close();
                    wej2.open(plik2.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    break;
                }
                if ( i==licznik-1 && zestaw.suma>p.suma )
                {
                wypisz(wej1,zestaw);
                }
            }
        }
        licznik++;
        dane++;
    }
    while(true);
    {
        wej.close();
    }
    wej2.close();
    wej.open(plik.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.seekg(0,ios::beg);
    wej1.seekp(0,ios::beg);
    for ( int i = 0;i<licznik;i++)
    {
        Zestaw podmiana;
        wczytaj(wej1,podmiana);
        wypisz(wej,podmiana);
    }
    wej1.close();
    wej.close();
    wej2.close();
    ReverseSortInt(plik,plik1,plik2);
    return dane;
}
void SortString ( string plik, string plik1, string plik2){
    fstream wej,wej1,wej2;
    wej.open(plik.c_str(),fstream :: in | fstream :: out);
    wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.close();
    wej1.open(plik1.c_str(), fstream :: in | fstream :: out);
     wej2.open(plik2.c_str(),ios::trunc | fstream :: in | fstream :: out);
    string smieci;
    int p1,p2,p3,p4,dane=0;
    int licznik = 0;
    do
    {
        Zestaw zestaw,p;
        wczytaj(wej,zestaw);
        if ( wej.eof())
        {
            break;
        }
        if ( licznik == 0)
        {
            wypisz(wej1,zestaw);
            wej1.seekg(0,ios::beg);
        }
        else
        {
            wej1.seekg(0,ios::beg);
            wej1.seekp(0,ios::beg);
            for ( int i = 0;i<licznik;i++)
            {
                wczytaj(wej1,p);
                if ( zestaw.s < p.s)
                {
                    wej1.seekg(0,ios::beg);
                    wej1.seekp(0,ios::beg);
                    for ( int j = 0;j<i;j++)
                    {
                    Zestaw pod;
                    wczytaj(wej1,pod);
                    wypisz(wej2,pod);
                    }
                    wypisz(wej2,zestaw);
                    for ( int j = i;j<licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej1,pod);
                    wypisz(wej2,pod);
                    }
                    wej1.close();
                    wej1.open(plik1.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    wej2.seekg(0,ios::beg);
                    wej1.seekp(0,ios::beg);
                    for ( int j=0;j<=licznik;j++)
                    {
                        Zestaw pod;
                        wczytaj(wej2,pod);
                        wypisz(wej1,pod);
                    }
                    wej2.close();
                    wej2.open(plik2.c_str(),ios::trunc |fstream :: in | fstream :: out);
                    break;
                }
                if ( i==licznik-1 && zestaw.s>=p.s )
                {
                wypisz(wej1,zestaw);
                }
            }
        }
        licznik++;
        dane++;
    }
    while(true);
    {
        wej.close();
    }
    wej2.close();
    wej.open(plik.c_str(),ios::trunc | fstream :: in | fstream :: out);
    wej1.seekg(0,ios::beg);
    wej1.seekp(0,ios::beg);
    for ( int i = 0;i<licznik;i++)
    {
        Zestaw podmiana;
        wczytaj(wej1,podmiana);
        wypisz(wej,podmiana);
    }
    wej1.close();
    wej.close();
}
void SortCount (string plik, string plik1, string plik2)
{
 int dane = sortcar(plik,plik1,plik2);
if (dane==1)
{
    return;
}
fstream wej,wej1,wej2;
wej.open(plik.c_str(),fstream :: in | fstream :: out);
wej1.open(plik1.c_str(),ios::trunc | fstream :: in | fstream :: out);
wej2.open(plik2.c_str(),ios::trunc | fstream :: in | fstream :: out);
wej2.close();
wej2.open(plik2.c_str(),fstream :: in | fstream :: out);
string smieci;
int p1,p2,p3,p4;
for ( int i = 0;i<dane;i++)
{
        Zestaw zestaw,p;
        wej>>zestaw.i;
        getline(wej,smieci);
        getline(wej,zestaw.s);
        wej.get(zestaw.c);
        wej>>zestaw.b1>>p1>>zestaw.f1>>zestaw.b2>>p2>>zestaw.f2>>zestaw.b3>>p3>>zestaw.f3>>zestaw.b4>>p4>>zestaw.f4;
        zestaw.c1 = p1;
        zestaw.c2 = p2;
        zestaw.c3 = p3;
        zestaw.c4 = p4;
        zestaw.suma=p1+p2+p3+p4;
        wej1<<zestaw.i<<" "<<zestaw.suma<<endl;
}
wej1.seekg(0,ios::beg);
wej1.seekp(0,ios::beg);
int x,y,org;
int cunt = 0;
int poprzedni,ile=0;
int ileorg=0;
do
{
        wej1>>x>>y;
        if ( wej1.eof())
        {
            wej2.close();
            wej2.open(plik2.c_str(),fstream :: in | fstream :: out);
            wej2.seekg(0,ios::end);
            wej2.seekp(0,ios::end);
            wej2<<poprzedni<<" "<<ile<<endl;
            break;
        }
        if ( cunt == 0)
        {
            poprzedni = x;
        }
        if ( x!=poprzedni)
        {
            wej2<<poprzedni<<" "<<ile<<endl;
            ileorg++;
            poprzedni=x;
            ile=0;
        }
        ile++;
        cunt++;
}
while(true);
{
    wej1.close();
}
wej1.close();
wej1.open(plik1.c_str(),ios::trunc|fstream ::in | fstream ::out);

wej2.close();

wej2.open(plik2.c_str(),fstream ::in | fstream ::out);

wej.seekg(0,ios::beg);
wej.seekp(0,ios::beg);
sortrazjeszcze(plik2,plik1,ileorg);
wej2.close();
wej2.open(plik2.c_str(),ios::trunc | fstream ::in | fstream ::out);
wej.seekg(0,ios::beg);
wej.seekp(0,ios::beg);
wej1.seekg(0,ios::beg);
wej1.seekp(0,ios::beg);
for ( int i =0;i<=ileorg;i++)
{
    int intt,moc;
    wej1>>intt>>moc;
    wej.seekg(0,ios::beg);
    wej.seekp(0,ios::beg);
    for ( int j = 0;j<dane;j++)
    {
        Zestaw zestaw;
        wej>>zestaw.i;
        getline(wej,smieci);
        getline(wej,zestaw.s);
        wej.get(zestaw.c);
        wej>>zestaw.b1>>p1>>zestaw.f1>>zestaw.b2>>p2>>zestaw.f2>>zestaw.b3>>p3>>zestaw.f3>>zestaw.b4>>p4>>zestaw.f4;
        zestaw.c1 = p1;
        zestaw.c2 = p2;
        zestaw.c3 = p3;
        zestaw.c4 = p4;
        zestaw.suma=p1+p2+p3+p4;

        if ( moc==0)
        {
            break;
        }

        else if (intt == zestaw.i)
        {
            moc--;
            wej2<<zestaw.i<<endl<<zestaw.s<<endl<<zestaw.c<<endl;
            wej2<<zestaw.b1<<" "<<(int)zestaw.c1<<" "<<zestaw.f1<<endl;
            wej2<<zestaw.b2<<" "<<(int)zestaw.c2<<" "<<zestaw.f2<<endl;
            wej2<<zestaw.b3<<" "<<(int)zestaw.c3<<" "<<zestaw.f3<<endl;
            wej2<<zestaw.b4<<" "<<(int)zestaw.c4<<" "<<zestaw.f4<<endl;
        }

    }
}
wej1.close();
wej.close();
wej2.seekg(0,ios::beg);
wej2.seekp(0,ios::beg);
wej.open(plik.c_str(),ios::trunc | fstream :: in | fstream ::out);
for ( int i = 0;i<dane;i++)
{
        Zestaw zestaw;
        wej2>>zestaw.i;
        getline(wej2,smieci);
        getline(wej2,zestaw.s);
        wej2.get(zestaw.c);
        wej2>>zestaw.b1>>p1>>zestaw.f1>>zestaw.b2>>p2>>zestaw.f2>>zestaw.b3>>p3>>zestaw.f3>>zestaw.b4>>p4>>zestaw.f4;
        zestaw.c1 = p1;
        zestaw.c2 = p2;
        zestaw.c3 = p3;
        zestaw.c4 = p4;
        zestaw.suma=p1+p2+p3+p4;
            wej<<zestaw.i<<endl<<zestaw.s<<endl<<zestaw.c<<endl;
            wej<<zestaw.b1<<" "<<(int)zestaw.c1<<" "<<zestaw.f1<<endl;
            wej<<zestaw.b2<<" "<<(int)zestaw.c2<<" "<<zestaw.f2<<endl;
            wej<<zestaw.b3<<" "<<(int)zestaw.c3<<" "<<zestaw.f3<<endl;
            wej<<zestaw.b4<<" "<<(int)zestaw.c4<<" "<<zestaw.f4<<endl;

}
wej.close();
wej1.close();
wej2.close();
}
/*int main ()
{
    string s1 = "dane.txt";
    string s2 = "pomoc.txt";
    string s3 = "pomoc2.txt";

    SortInt(s1,s2,s3);
    return 0;
}*/
