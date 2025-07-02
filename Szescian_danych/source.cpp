//Mateusz Paszynski
#include <iostream>
using namespace std;
long long int rek ( long long int tab[32][32], long long int dlugosc,long long int znak,long long int suma)
{
    if (dlugosc == 2)
    {
        suma = tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
        return suma;
    }

    long long int flaga = 0;
    long long int x = 0;
    long long y = 0;
    for ( long long int i = 0; i<dlugosc; i++)
    {
        for ( long long int j = i+1; j<dlugosc; j++)
        {
            y=0;
            x = 0;
            if ( flaga==0)
            {
                for ( long long int m = 0; m<dlugosc; m++)
                {
                    if ( tab[m][i]!=0 && tab[m][j]!=0)
                    {
                        if ( tab[m][i]==tab[m][j])
                        {
                            x++;
                        }
                    }
                    if ( tab[m][i]==0){y++;}
                }
            }
            if ( x == dlugosc )
            {
                return 0;
            }
            if (y == dlugosc)
            {
                return 0;
            }
        }
    }
    if ( flaga==0)
    {
        for ( long long int i = 0; i<dlugosc; i++)
        {
            for ( long long int j = i+1; j<dlugosc; j++)
            {y=0;
                x = 0;
                for ( long long int m = 0; m<dlugosc; m++)
                {
                    if ( tab[i][m]!=0 && tab[j][m]!=0)
                    {
                        if ( tab[i][m]==tab[j][m])
                        {
                            x++;
                        }

                    }if ( tab[i][m]==0){y++;}

                }
                if ( x == dlugosc )
                {
                    return 0;
                }
                if (y == dlugosc)
            {
                return 0;
            }
            }
        }
    }
    long long int D[dlugosc-1][dlugosc-1];
    for ( long long int i = 0; i < dlugosc ; i++)
    {
        znak = 1;
        if ( i%2==1)
        {
            znak = 0 - znak;
        }
        long long int D[32][32];
        for ( long long int j = 1 ; j<dlugosc; j++)
        {
            flaga =0;
            for ( long long int m = 0 ; m<dlugosc-1; m++)
            {
                if ( m == i)flaga=1;

                D[j-1][m]=tab[j][m+flaga];
            }
        }
        if ( tab[0][i]!=0)
        {
            suma += znak*tab[0][i]*rek(D,dlugosc-1,znak,0);
        }
    }
    return suma;
}
int main()
{
    long long int l,v,p,e,h,w,d,r,i;
    char k;
    long long int dlugosc;
    cin>>dlugosc;
    long long int tab[32][32][32];
    for ( long long int panel = 0; panel < dlugosc ; panel ++ )
    {
        for ( long long int wiersz = 0 ; wiersz < dlugosc ; wiersz++)
        {
            for (long long int kolumna = 0 ; kolumna < dlugosc ; kolumna++)
            {
                cin>>tab[wiersz][kolumna][panel];
            }
        }
    }
    char operacja = '0';
    while ( operacja != 'E')
    {
        cin>>operacja;
        long long int pwiersz,kwiersz,ppanel,kpanel,pkolumna,kkolumna,suma;
        long long int pomoc,pomoc2;
        if ( operacja == 'T')
        {
            cin>>l>>v>>p>>e;
            suma = 0;
            if ( l >= ( (dlugosc ) / 2 ) )
            {
                pwiersz = l - e ;
                kwiersz = l;
            }
            else
            {
                pwiersz = l ;
                kwiersz = l + e;
            }
            if ( v >= ( (dlugosc ) / 2 ) )
            {
                pkolumna = v - e ;
                kkolumna = v;
            }
            else
            {
                pkolumna = v ;
                kkolumna = v + e;
            }
            if ( p >= ( (dlugosc ) / 2 ) )
            {
                ppanel = p - e ;
                kpanel = p;
            }
            else
            {
                ppanel = p ;
                kpanel = p + e;
            }
            if ( pwiersz < 0 ) pwiersz=0 ;
            if ( kwiersz >= dlugosc)kwiersz=dlugosc - 1 ;
            if ( pkolumna < 0)pkolumna=0;
            if ( kkolumna >= dlugosc )kkolumna=dlugosc - 1  ;
            if ( ppanel < 0 )ppanel = 0;
            if ( kpanel >= dlugosc )kpanel = dlugosc - 1;
            for ( long long int i = ppanel ; i <= kpanel; i++)
            {
                for(long long int j = pwiersz; j <= kwiersz; j++)
                {
                    for ( long long int m = pkolumna; m <= kkolumna; m++)
                    {
                        pomoc = 0;
                        pomoc2 = i - p;
                        if ( pomoc2 < 0 ) pomoc2 = 0 - pomoc2;
                        pomoc += pomoc2;
                        pomoc2 = m - v;
                        if ( pomoc2 < 0 ) pomoc2 = 0 - pomoc2;
                        pomoc += pomoc2;
                        pomoc2 = j - l;
                        if ( pomoc2 < 0 ) pomoc2 = 0 - pomoc2;
                        pomoc += pomoc2;

                        if ( pomoc < 0 ) pomoc = 0 - pomoc;
                        if ( pomoc <=e)
                            suma+=tab[j][m][i];
                    }
                }
            }
            cout<<suma<<endl;
        }
        if ( operacja == 'C')
        {
            cin>>l>>v>>p>>h>>w>>d;
            suma = 0;

            if ( l >= ( (dlugosc ) / 2 ) )
            {
                pwiersz = l - h ;
                kwiersz = l;
            }
            else
            {
                pwiersz = l ;
                kwiersz = l + h;
            }
            if ( v >= ( (dlugosc ) / 2 ) )
            {
                pkolumna = v - w ;
                kkolumna = v;
            }
            else
            {
                pkolumna = v ;
                kkolumna = v + w;
            }
            if ( p >= ( (dlugosc ) / 2 ) )
            {
                ppanel = p - d ;
                kpanel = p;
            }
            else
            {
                ppanel = p ;
                kpanel = p + d;
            }
            if ( pwiersz < 0 ) pwiersz=0 ;
            if ( kwiersz >= dlugosc)kwiersz=dlugosc - 1 ;
            if ( pkolumna < 0)pkolumna=0;
            if ( kkolumna >= dlugosc )kkolumna=dlugosc - 1  ;
            if ( ppanel < 0 )ppanel = 0;
            if ( kpanel >= dlugosc )kpanel = dlugosc - 1;
            for ( long long int i = ppanel ; i <= kpanel; i++)
            {
                for(long long int j = pwiersz; j <= kwiersz; j++)
                {
                    for ( long long int m = pkolumna; m <= kkolumna; m++)
                    {
                        suma+=tab[j][m][i];
                    }
                }
            }
            cout<<suma<<endl;
        }
        if ( operacja == 'O')
        {
            cin>>l>>v>>p>>r;
            suma = 0;
            if ( l >= ( (dlugosc ) / 2 ) )
            {
                pwiersz = l - r ;
                kwiersz = l;
            }
            else
            {
                pwiersz = l ;
                kwiersz = l + r;
            }
            if ( v >= ( (dlugosc ) / 2 ) )
            {
                pkolumna = v - r ;
                kkolumna = v;
            }
            else
            {
                pkolumna = v ;
                kkolumna = v + r;
            }
            if ( p >= ( (dlugosc ) / 2 ) )
            {
                ppanel = p - r ;
                kpanel = p;
            }
            else
            {
                ppanel = p ;
                kpanel = p + r;
            }
            if ( pwiersz < 0 ) pwiersz=0 ;
            if ( kwiersz >= dlugosc)kwiersz=dlugosc - 1 ;
            if ( pkolumna < 0)pkolumna=0;
            if ( kkolumna >= dlugosc )kkolumna=dlugosc - 1  ;
            if ( ppanel < 0 )ppanel = 0;
            if ( kpanel >= dlugosc )kpanel = dlugosc - 1;
            for ( long long int i = ppanel ; i <= kpanel; i++)
            {
                for(long long int j = pwiersz; j <= kwiersz; j++)
                {
                    for ( long long int m = pkolumna; m <= kkolumna; m++)
                    {
                        pomoc = 0;
                        pomoc2 = i - p;
                        pomoc2*=pomoc2;
                        pomoc += pomoc2;
                        pomoc2 = m - v;
                        pomoc2*=pomoc2;
                        pomoc += pomoc2;
                        pomoc2 = j - l;
                        pomoc2*=pomoc2;
                        pomoc += pomoc2;

                        if ( pomoc < 0 ) pomoc = 0 - pomoc;
                        if ( pomoc <= r*r)
                            suma+=tab[j][m][i];
                    }
                }
            }
            cout<<suma<<endl;

        }
        if ( operacja == 'D')
        {
            cin>>k>>i;
            long long int tab2[32][32];
            if ( k == 'l')
            {
                for ( long long int n = 0 ; n <  dlugosc; n++)
                {
                    for ( long long int j = 0; j<dlugosc; j++)
                    {
                        tab2[n][j] = tab[i][j][n];

                    }

                }

            }
            if ( k == 'v')
            {
                for ( long long int n = 0 ; n <  dlugosc; n++)
                {
                    for ( long long int j = 0; j<dlugosc; j++)
                    {
                        tab2[n][j] = tab[n][i][j];
                    }
                }

            }
            if ( k == 'p')
            {
                for ( long long int n = 0 ; n <  dlugosc; n++)
                {
                    for ( long long int j = 0; j<dlugosc; j++)
                    {
                        tab2[n][j] = tab[n][j][i];

                    }
                }
            }


            cout<<rek(tab2,dlugosc,1,0)<<endl;




        }
    }

    return 0;
}
