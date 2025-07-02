//Mateusz Paszyński
#include <iostream>
using namespace std;
int main()
{
    int dane;
    cin >> dane;
    int rozmiar, first, dlugosc, przesuniecie ;
    int l_ciag,cunt, pomoc, pomocnik;
    int i, id_pierwszego, y, n, j, k, id_pary, prz2, poczatek, ile_przesunac, poprzednik, ilezamian, resztki, r, aktualna_wartosc, dlugoscugosc_iteracji, id, idk , m ;
    char c;
    bool lp;
    while( dane )
    {
        dane = dane - 1;
        cin >> rozmiar;
        int tab [ rozmiar ];
        i = rozmiar;
        while ( i )
        {
            cin >> tab [ rozmiar - i ];
            i = i - 1 ;
        }
        i = rozmiar;
        while ( i )
        {
            cout << tab [ rozmiar - i ]<<" ";
            i = i - 1 ;
        }
        cout<<endl;
        c = '0';
        while (c != 'F')
        {
            cin >> c;
            if ( c == 'R')
            {
                cin >> id_pierwszego >> dlugosc;
                if ( dlugosc != 0 )
                {

                    if ( id_pierwszego < 0 )
                    {
                        id_pierwszego = id_pierwszego % rozmiar;
                        id_pierwszego = rozmiar + id_pierwszego;
                    }
                    id_pierwszego = id_pierwszego % rozmiar ;
                    l_ciag = rozmiar / dlugosc;
                    cunt = 0;
                    while(l_ciag)
                    {
                        j = dlugosc / 2;
                        first = (id_pierwszego + (cunt * dlugosc)) % rozmiar;
                        n  = 0 ;
                        while ( j )
                        {
                            y = ( first + dlugosc - 1 - 2 * n ) % rozmiar;
                            first = first % rozmiar ;
                            pomoc = tab [ first ];
                            tab [ first ] = tab [ y ];
                            tab [ y ] = pomoc;
                            first = first + 1;
                            j = j - 1;
                            n = n + 1;
                        }
                        l_ciag = l_ciag - 1;
                        cunt = cunt + 1 ;
                    }
                }
            }
            if( c == 'C')
            {
                cin >> first >> dlugosc;
                if( dlugosc != 0){
                if (first < 0 )
                    {
                        first = first % rozmiar;
                        first = rozmiar + first;
                    }

                    first = first % rozmiar;
                    ilezamian = rozmiar / ( dlugosc * 2 );
                    cunt = 1;
                    poczatek = first;
                    while(ilezamian)
                    {
                        k = dlugosc % rozmiar;
                        first = (poczatek + (dlugosc * (cunt - 1) ))% rozmiar ;
                        id_pary = ( poczatek + dlugosc * cunt ) % rozmiar;
                        while ( k )
                        {
                            first = first % rozmiar;
                            id_pary = id_pary % rozmiar;
                            pomocnik = tab [ first];
                            tab [ first ] = tab [ id_pary ];
                            tab [ id_pary ] = pomocnik;
                            if ( k != 1)
                            {
                               first = first + 1;
                            id_pary = id_pary + 1;
                            }

                            k = k - 1;
                        }
                        cunt = cunt + 2;
                        ilezamian = ilezamian - 1;
                    }


            }
            }
            if( c == 'M')
            {
                cin >> first >> dlugosc >> przesuniecie;
                if ( dlugosc < 0)
                {
                    dlugosc = 0 - dlugosc;
                }
                if ( dlugosc > rozmiar)
                {
                    dlugosc = rozmiar;
                }

                if ( dlugosc != 0 && przesuniecie != 0)
                {
                    first = first % rozmiar ;
                    if ( first < 0)
                    {
                        first = rozmiar + first ;
                    }
                    prz2 = przesuniecie;
                    przesuniecie = przesuniecie % dlugosc;

                    resztki = rozmiar % dlugosc;

                    if ( przesuniecie < 0 )
                    {
                        przesuniecie = dlugosc + przesuniecie;
                    }
                    przesuniecie = przesuniecie % dlugosc;
                    l_ciag = rozmiar / dlugosc;
                    poczatek = first ;
                    cunt = 0 ;

                    while(l_ciag)
                    {
                        ile_przesunac = przesuniecie;
                        while ( ile_przesunac )
                        {
                            first = (poczatek + (dlugosc * cunt)) % rozmiar;
                            aktualna_wartosc = tab[first];
                            dlugoscugosc_iteracji = dlugosc;
                            while(dlugoscugosc_iteracji)
                            {
                                poprzednik = aktualna_wartosc;
                                first = first + 1 ;
                                if  ( (dlugoscugosc_iteracji == 1))
                                {
                                    first = (poczatek + (dlugosc * cunt)) % rozmiar;
                                }
                                if ( first == rozmiar)
                                {
                                    first = 0;
                                }
                                aktualna_wartosc = tab[first];
                                tab[first] = poprzednik;
                                dlugoscugosc_iteracji = dlugoscugosc_iteracji - 1;
                            }

                            ile_przesunac = ile_przesunac - 1;
                        }
                        l_ciag = l_ciag - 1;
                        cunt =  cunt + 1;
                    }

                    first = poczatek - resztki;
                    if ( first < 0)
                    {
                        first = rozmiar + first ;
                    }

                    if ( resztki !=0)
                    {
                        prz2 = prz2 % resztki;
                    }
                    r = resztki;

                    if ( prz2 < 0 )
                    {
                        prz2 = resztki + prz2;
                    }

                    ile_przesunac = prz2;

                    int start = first;
                    if ( resztki !=0 )
                    {
                        while ( ile_przesunac )
                    {
                        first = start;
                        resztki = r;
                        aktualna_wartosc = tab[ first ];
                        while ( resztki )
                        {
                            poprzednik = aktualna_wartosc;
                            first = first + 1 ;
                            if ( first == rozmiar)
                            {
                                first = 0;
                            }
                            if ( resztki == 1)
                            {
                                first = poczatek - r;
                                if ( first < 0)
                                {
                                    first = rozmiar + first ;
                                }
                            }

                            aktualna_wartosc = tab [ first ];
                            tab[ first ] = poprzednik;
                            resztki = resztki - 1;
                        }
                        ile_przesunac = ile_przesunac - 1;
                    }}
                }
            }
            if ( c == 'S')
            {
                cin >> first >> dlugosc;

                if ( dlugosc != 0)
                {
                    lp = 0;
                    first = first % rozmiar ;
                    if ( first < 0)
                    {
                        first = rozmiar + first ;
                    }
                    poczatek = first;
                    if ( dlugosc < 0 )
                    {
                        lp = 1;
                        dlugosc = 0 - dlugosc ;
                    }
                    if ( dlugosc > rozmiar )
               {
                   dlugosc = rozmiar ;
               }
                    l_ciag = rozmiar / dlugosc;
                    resztki = rozmiar % dlugosc;
                    cunt = 0;

                    while(l_ciag)
                    {
                        id = (poczatek + (dlugosc * cunt)) % rozmiar;
                        idk = id + 1;
                        idk = idk % rozmiar ;
                        n = 0;
                        m = 0;
                        while ( n < dlugosc )
                        {
                            id = (poczatek + (dlugosc * cunt)) % rozmiar;
                            idk = id + 1;
                            idk = idk % rozmiar ;
                            m  = 0;
                            while ( m < dlugosc - 1  )
                            {
                                pomocnik = tab [ id ];
                                if ( lp == 1 )
                                {
                                    if ( tab [ id ] < tab [ idk ])
                                    {
                                        tab [ id ] = tab [ idk ];
                                        tab [ idk ] = pomocnik ;
                                    }
                                }
                                else if ( tab [ id ] > tab [ idk ])
                                {
                                    tab [ id ] = tab [ idk ];
                                    tab [ idk ] = pomocnik ;
                                }
                                id = id + 1;
                                idk = idk + 1;
                                if ( idk == rozmiar)
                                {
                                    idk = 0;
                                }
                                if ( id == rozmiar )
                                {
                                    id = 0;
                                }
                                m = m + 1;
                            }
                            n = n + 1;
                        }
                        l_ciag = l_ciag - 1;
                        cunt = cunt + 1;
                    }
                    n = 0;
                    r = resztki;
                    while ( n < resztki )
                        {
                            id = (poczatek - resztki) % rozmiar;
                            if ( id < 0 )
                            {
                                id = rozmiar + id;
                            }
                            idk = id + 1;
                            idk = idk % rozmiar ;
                            m = 0;
                            while ( m < resztki - 1  )
                            {
                                pomocnik = tab [ id ];
                                if ( lp == 1 )
                                {
                                    if ( tab [ id ] < tab [ idk ])
                                    {
                                        tab [ id ] = tab [ idk ];
                                        tab [ idk ] = pomocnik ;
                                    }
                                }
                                else if ( tab [ id ] > tab [ idk ])
                                {
                                    tab [ id ] = tab [ idk ];
                                    tab [ idk ] = pomocnik ;
                                }
                                id = id + 1;
                                idk = idk + 1;
                                if ( idk == rozmiar)
                                {
                                    idk = 0;
                                }
                                if ( id == rozmiar )
                                {
                                    id = 0;
                                }
                                m = m + 1;
                            }
                            n = n + 1;
                        }
                }
            }
        }
        i = rozmiar;
        while ( i )
        {
            cout << tab [ rozmiar - i ] << " ";
            i = i - 1 ;
        }
        cout << endl;
    }
    return 0;
}
