//Mateusz Paszyński
#include <iostream>

using namespace std;

struct Place{
    unsigned short ilosc;
     unsigned short etykieta;
};
struct Shelf{
    short zajete;
    Place place[128];
    unsigned long long towar;
};
struct Rack{
    short zajete;
    Shelf shelf[128];
    unsigned long long towar;
};
struct Warehouse{
    short zajete;
    Rack rack[128];
    Shelf handyShelf;
    unsigned long long towar;
};
struct Sklad{
    short zajete;
    Warehouse warehouse[128];
    Rack handyRack;
    Shelf handyShelf;
    unsigned long long towar;
} sklad;
void set_ap(){
    long long wb,rb,sb,pe;
    cin>>wb>>rb>>sb>>pe;
    if ( sklad.zajete <= wb || wb < 0 ||wb>127)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.warehouse[wb].zajete <= rb || rb < 0 ||rb>127)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.warehouse[wb].rack[rb].zajete<=sb || sb < 0 ||sb>127)
    {
        cout<<"error\n";
        return;
    }
    if ( pe>128 || pe < 0)
    {
        cout<<"error\n";
        return;
    }
        for (int i = pe; i<sklad.warehouse[wb].rack[rb].shelf[sb].zajete; i++)
        {
            sklad.warehouse[wb].rack[rb].shelf[sb].towar-=sklad.warehouse[wb].rack[rb].shelf[sb].place[i].ilosc;
            sklad.warehouse[wb].rack[rb].towar-=sklad.warehouse[wb].rack[rb].shelf[sb].place[i].ilosc;
            sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[rb].shelf[sb].place[i].ilosc;
            sklad.towar-=sklad.warehouse[wb].rack[rb].shelf[sb].place[i].ilosc;
            sklad.warehouse[wb].rack[rb].shelf[sb].place[i].ilosc=0;
            sklad.warehouse[wb].rack[rb].shelf[sb].place[i].etykieta=0;
        }
    sklad.warehouse[wb].rack[rb].shelf[sb].zajete = pe;
}
void set_as(){
    long long wb,rb,se,pe;
    cin>>wb>>rb>>se>>pe;
    if ( sklad.zajete<=wb || wb<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.warehouse[wb].zajete<=rb || rb<0)
    {
        cout<<"error\n";
        return;
    }
    if ( se>128 || se<0)
    {
    cout<<"error\n";
        return;
    }
    if ( pe>128 || se<0)
    {
        cout<<"error\n";
        return;
    }
        for  (int i = se; i<sklad.warehouse[wb].rack[rb].zajete; i++)
        {
            for ( int j=0; j<sklad.warehouse[wb].rack[rb].shelf[i].zajete; j++)
            {
                sklad.warehouse[wb].rack[rb].shelf[i].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].rack[rb].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc=0;
                sklad.warehouse[wb].rack[rb].shelf[i].place[j].etykieta=0;
            }
            sklad.warehouse[wb].rack[rb].shelf[i].zajete=0;
        }

    for ( int i = 0; i<se; i++)
    {
            for ( int j = pe; j<sklad.warehouse[wb].rack[rb].shelf[i].zajete; j++)
            {
                sklad.warehouse[wb].rack[rb].shelf[i].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].rack[rb].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.towar-=sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc;
                sklad.warehouse[wb].rack[rb].shelf[i].place[j].ilosc=0;
                sklad.warehouse[wb].rack[rb].shelf[i].place[j].etykieta=0;
            }
        sklad.warehouse[wb].rack[rb].shelf[i].zajete=pe;
    }
    sklad.warehouse[wb].rack[rb].zajete=se;
}
void set_ar(){
    long long wb,re,se,pe;
    cin>>wb>>re>>se>>pe;
    if ( sklad.zajete<=wb || wb<0)
    {
        cout<<"error\n";
        return;
    }
    if ( re < 0 || re >128 || se < 0 || se >128 ||  pe < 0 || pe >128  )
    {
        cout<<"error\n";
        return;
    }
        for (int i = re; i<sklad.warehouse[wb].zajete; i++)
        {
            for ( int j = 0; j<sklad.warehouse[wb].rack[i].zajete; j++)
            {
                for ( int k = 0; k<sklad.warehouse[wb].rack[i].shelf[j].zajete; k++)
                {
                    sklad.warehouse[wb].rack[i].shelf[j].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc=0;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].etykieta=0;

                }
                sklad.warehouse[wb].rack[i].shelf[j].zajete=0;
            }
            sklad.warehouse[wb].rack[i].zajete=0;
        }
        sklad.warehouse[wb].zajete=re;

        for (int i = 0; i<sklad.warehouse[wb].zajete; i++)
        {
            for ( int j = se; j<sklad.warehouse[wb].rack[i].zajete; j++)
            {
                for ( int k = 0; k<sklad.warehouse[wb].rack[i].shelf[j].zajete; k++)
                {
                    sklad.warehouse[wb].rack[i].shelf[j].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc=0;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].etykieta=0;

                }
                sklad.warehouse[wb].rack[i].shelf[j].zajete=0;
            }
            sklad.warehouse[wb].rack[i].zajete=se;
        }

        for (int i = 0; i<sklad.warehouse[wb].zajete; i++)
        {
            for ( int j = 0; j<sklad.warehouse[wb].rack[i].zajete; j++)
            {
                for ( int k = pe; k<sklad.warehouse[wb].rack[i].shelf[j].zajete; k++)
                {
                    sklad.warehouse[wb].rack[i].shelf[j].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.towar-=sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].ilosc=0;
                    sklad.warehouse[wb].rack[i].shelf[j].place[k].etykieta=0;

                }
                sklad.warehouse[wb].rack[i].shelf[j].zajete=pe;
            }
        }
}
void set_aw(){
    long long we,re,se,pe;
    cin>>we>>re>>se>>pe;
   if (we<0 ||we>128 ||re<0 ||re>128 ||se<0 ||se>128 ||pe<0 ||pe>128 )
   {
       cout<<"error\n";
       return;
   }
        for ( int i = we; i<sklad.zajete; i++)
        {
            for ( int j =0;j<sklad.warehouse[i].handyShelf.zajete;j++)
            {
                sklad.warehouse[i].handyShelf.towar-=sklad.warehouse[i].handyShelf.place[j].ilosc;
                sklad.warehouse[i].towar-=sklad.warehouse[i].handyShelf.place[j].ilosc;
                sklad.towar-=sklad.warehouse[i].handyShelf.place[j].ilosc;
                sklad.warehouse[i].handyShelf.place[j].ilosc=0;
                sklad.warehouse[i].handyShelf.place[j].etykieta=0;
            }
            for ( int j = 0; j<sklad.warehouse[i].zajete; j++)
            {
                for ( int k = 0; k<sklad.warehouse[i].rack[j].zajete; k++)
                {
                    for ( int l = 0; l<sklad.warehouse[i].rack[j].shelf[k].zajete; l++)
                    {
                        sklad.warehouse[i].rack[j].shelf[k].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc=0;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].etykieta=0;
                    }
                    sklad.warehouse[i].rack[j].shelf[k].zajete=0;
                }
                sklad.warehouse[i].rack[j].zajete=0;
            }
            sklad.warehouse[i].zajete=0;
        }
        sklad.zajete=we;

        for ( int i = 0; i<sklad.zajete; i++)
        {
            for ( int j = re; j<sklad.warehouse[i].zajete; j++)
            {
                for ( int k = 0; k<sklad.warehouse[i].rack[j].zajete; k++)
                {
                    for ( int l = 0; l<sklad.warehouse[i].rack[j].shelf[k].zajete; l++)
                    {
                        sklad.warehouse[i].rack[j].shelf[k].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc=0;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].etykieta=0;
                    }
                    sklad.warehouse[i].rack[j].shelf[k].zajete=0;
                }
                sklad.warehouse[i].rack[j].zajete=0;
            }
            sklad.warehouse[i].zajete=re;
        }

        for ( int i = 0; i<sklad.zajete; i++)
        {
            for ( int j = 0; j<sklad.warehouse[i].zajete; j++)
            {
                for ( int k = se; k<sklad.warehouse[i].rack[j].zajete; k++)
                {
                    for ( int l = 0; l<sklad.warehouse[i].rack[j].shelf[k].zajete; l++)
                    {
                        sklad.warehouse[i].rack[j].shelf[k].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc=0;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].etykieta=0;
                    }
                    sklad.warehouse[i].rack[j].shelf[k].zajete=0;
                }
                sklad.warehouse[i].rack[j].zajete=se;
            }
            sklad.warehouse[i].zajete=re;
        }
        for ( int i = 0; i<sklad.zajete; i++)
        {
            for ( int j = 0; j<sklad.warehouse[i].zajete; j++)
            {
                for ( int k = 0; k<sklad.warehouse[i].rack[j].zajete; k++)
                {
                    for ( int l = pe; l<sklad.warehouse[i].rack[j].shelf[k].zajete; l++)
                    {
                        sklad.warehouse[i].rack[j].shelf[k].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.towar-=sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc=0;
                        sklad.warehouse[i].rack[j].shelf[k].place[l].etykieta=0;
                    }
                    sklad.warehouse[i].rack[j].shelf[k].zajete=pe;
                }
                sklad.warehouse[i].rack[j].zajete=se;

            }
            sklad.warehouse[i].zajete=re;
        }
    sklad.zajete=we;
}
void set_hw(){
    long long w,p;
    cin>>w>>p;
    if ( sklad.zajete<=w || w < 0)
    {
        cout<<"error\n";
        return;
    }
    if ( p<0 || p>128)
    {
        cout<<"error\n";
        return;
    }
        for ( int i = p; i<sklad.warehouse[w].handyShelf.zajete; i++)
        {
            sklad.warehouse[w].handyShelf.towar-=sklad.warehouse[w].handyShelf.place[i].ilosc;
            sklad.warehouse[w].towar-=sklad.warehouse[w].handyShelf.place[i].ilosc;
            sklad.towar-=sklad.warehouse[w].handyShelf.place[i].ilosc;
            sklad.warehouse[w].handyShelf.place[i].ilosc=0;
            sklad.warehouse[w].handyShelf.place[i].etykieta=0;
        }
        sklad.warehouse[w].handyShelf.zajete=p;
}
void set_hr(){
    long long s,p;
    cin>>s>>p;
    if ( s<0 || s>128 || p<0 ||p>128)
    {
        cout<<"error\n";
        return;
    }
  for ( int i = s; i<sklad.handyRack.zajete; i++)
        {
            for ( int j = 0; j<sklad.handyRack.shelf[i].zajete; j++)
            {
                sklad.handyRack.shelf[i].towar-=sklad.handyRack.shelf[i].place[j].ilosc;
                sklad.handyRack.towar-=sklad.handyRack.shelf[i].place[j].ilosc;
                sklad.towar-=sklad.handyRack.shelf[i].place[j].ilosc;
                sklad.handyRack.shelf[i].place[j].ilosc=0;
                sklad.handyRack.shelf[i].place[j].etykieta=0;
            }
            sklad.handyRack.shelf[i].zajete=0;
        }
    for ( int i = 0; i<s; i++)
    {
        for ( int j = p; j<sklad.handyRack.shelf[i].zajete; j++)
        {
            sklad.handyRack.shelf[i].towar-=sklad.handyRack.shelf[i].place[j].ilosc;
            sklad.handyRack.towar-=sklad.handyRack.shelf[i].place[j].ilosc;
            sklad.towar-=sklad.handyRack.shelf[i].place[j].ilosc;
            sklad.handyRack.shelf[i].place[j].ilosc=0;
            sklad.handyRack.shelf[i].place[j].etykieta=0;

        }
        sklad.handyRack.shelf[i].zajete=p;
    }
    sklad.handyRack.zajete=s;
}
void set_hs(){
    long long pe;
    cin>>pe;
    if ( pe<0 || pe>128)
    {
        cout<<"error\n";
        return;
    }
        for ( int i = pe; i<sklad.handyShelf.zajete; i++)
        {
            sklad.handyShelf.towar-=sklad.handyShelf.place[i].ilosc;
            sklad.towar-=sklad.handyShelf.place[i].ilosc;
            sklad.handyShelf.place[i].ilosc=0;
            sklad.handyShelf.place[i].etykieta=0;

        }
    sklad.handyShelf.zajete=pe;
}
void put_w(){
    long long w,r,s,p,a;
    cin>>w>>r>>s>>p>>a;
    if ( w>127 || w < 0 ||w>=sklad.zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( r>127 || r < 0 ||r>=sklad.warehouse[w].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( s>127 || s < 0 ||s>=sklad.warehouse[w].rack[r].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( p>127 || p< 0 ||p>=sklad.warehouse[w].rack[r].shelf[s].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if (sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc+a>65535 )
    {
        a=65535-sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc;

    }
    sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc+=a;
    sklad.warehouse[w].rack[r].shelf[s].towar+=a;
    sklad.warehouse[w].rack[r].towar+=a;
    sklad.warehouse[w].towar+=a;
    sklad.towar+=a;

}
void put_h(){
    long long w,p,a;
    cin>>w>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( w>=sklad.zajete || w<0 || w>127)
    {
        cout<<"error\n";
        return ;
    }
    if ( p>= sklad.warehouse[w].handyShelf.zajete || p <0 || p>127)
    {
        cout<<"error\n";
        return ;
    }
    if ( sklad.warehouse[w].handyShelf.place[p].ilosc+a>65535)
    {
        a=65535-sklad.warehouse[w].handyShelf.place[p].ilosc;
    }
    sklad.warehouse[w].handyShelf.place[p].ilosc+=a;
    sklad.warehouse[w].handyShelf.towar+=a;
    sklad.warehouse[w].towar+=a;
    sklad.towar+=a;
}
void put_r(){
    long long s,p,a;
    cin>>s>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( s>=sklad.handyRack.zajete || s>127 || s<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyRack.shelf[s].zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.handyRack.shelf[s].place[p].ilosc+a>65535)
    {
        a=65535-sklad.handyRack.shelf[s].place[p].ilosc;
    }
    sklad.handyRack.shelf[s].place[p].ilosc+=a;
    sklad.handyRack.shelf[s].towar+=a;
    sklad.handyRack.towar+=a;
    sklad.towar+=a;
}
void put_s(){
    long long p,a;
    cin>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyShelf.zajete || p>128 || p<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.handyShelf.place[p].ilosc+a>65535)
    {
        a=65535-sklad.handyShelf.place[p].ilosc;
    }
    sklad.handyShelf.place[p].ilosc+=a;
    sklad.handyShelf.towar+=a;
    sklad.towar+=a;

}
void FILL(){
    long long w,r,s,p,a;
    cin>>w>>r>>s>>p>>a;
    if (w<0 || w>128)
    {
        cout<<"error\n";
        return;
    }
    if (r<0 || r>128)
    {
        cout<<"error\n";
        return;
    }
    if (s<0 || s>128)
    {
        cout<<"error\n";
        return;
    }
    if (p<0 || p>128)
    {
        cout<<"error\n";
        return;
    }
    if (a<0 || a>65535)
    {
        cout<<"error\n";
        return;
    }
    for ( int i = 0; i<w; i++)
    {
        for ( int j = 0 ; j<p; j++)
        {
            sklad.warehouse[i].handyShelf.place[j].ilosc=a;
            sklad.warehouse[i].handyShelf.place[j].etykieta=0;
        }
        sklad.warehouse[i].handyShelf.towar = a*p;
        sklad.warehouse[i].handyShelf.zajete = p;

        for( int j = 0; j<r; j++)
        {
            for ( int k=0; k<s; k++)
            {
                for ( int l = 0; l<p; l++)
                {
                    sklad.warehouse[i].rack[j].shelf[k].place[l].ilosc=a;
                    sklad.warehouse[i].rack[j].shelf[k].place[l].etykieta=0;
                }
                sklad.warehouse[i].rack[j].shelf[k].towar=a*p;
                sklad.warehouse[i].rack[j].shelf[k].zajete=p;
            }
            sklad.warehouse[i].rack[j].towar = a*s*p;
            sklad.warehouse[i].rack[j].zajete=s;
        }
        sklad.warehouse[i].towar=a*s*r*p+a*p;
        sklad.warehouse[i].zajete=r;
    }
    for ( int j = 0 ; j<p; j++)
    {

        sklad.handyShelf.place[j].ilosc=a;
        sklad.handyShelf.place[j].etykieta=0;
    }
    sklad.handyShelf.towar=a*p;
    sklad.handyShelf.zajete=p;
    sklad.handyRack.towar=a*p*s;
    sklad.handyRack.zajete=s;
    for ( int i =0 ; i<s; i++)
    {
        for ( int j =0; j<p; j++)
        {
            sklad.handyRack.shelf[i].place[j].ilosc=a;
            sklad.handyRack.shelf[i].place[j].etykieta=0;

        }
        sklad.handyRack.shelf[i].zajete=p;
        sklad.handyRack.shelf[i].towar=a*p;
    }
    sklad.towar=w*(a*s*r*p+a*p)+p*a+p*a*s;
    sklad.zajete=w;



}
void pop_w(){
    long long w,r,s,p,a;
    cin>>w>>r>>s>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( w>127 || w < 0 ||w>=sklad.zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( r>127 || r < 0 ||r>=sklad.warehouse[w].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( s>127 || s < 0 ||s>=sklad.warehouse[w].rack[r].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if ( p>127 || p< 0 ||p>=sklad.warehouse[w].rack[r].shelf[s].zajete)
    {
        cout<<"error\n";
        return ;
    }
    if (sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc-a<0 )
    {
        a=sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc;

    }
    sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc-=a;
    sklad.warehouse[w].rack[r].shelf[s].towar-=a;
    sklad.warehouse[w].rack[r].towar-=a;
    sklad.warehouse[w].towar-=a;
    sklad.towar-=a;
}
void pop_h(){
    long long w,p,a;
    cin>>w>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( w>=sklad.zajete || w<0 || w>127)
    {
        cout<<"error\n";
        return ;
    }
    if ( p>= sklad.warehouse[w].handyShelf.zajete || p <0 || p>127)
    {
        cout<<"error\n";
        return ;
    }
    if ( sklad.warehouse[w].handyShelf.place[p].ilosc-a<0)
    {
        a=sklad.warehouse[w].handyShelf.place[p].ilosc;
    }
    sklad.warehouse[w].handyShelf.place[p].ilosc-=a;
    sklad.warehouse[w].handyShelf.towar-=a;
    sklad.warehouse[w].towar-=a;
    sklad.towar-=a;
}
void pop_r(){
    long long s,p,a;
    cin>>s>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( s>=sklad.handyRack.zajete || s>127 || s<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyRack.shelf[s].zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.handyRack.shelf[s].place[p].ilosc-a<0)
    {
        a=sklad.handyRack.shelf[s].place[p].ilosc;
    }
    sklad.handyRack.shelf[s].place[p].ilosc-=a;
    sklad.handyRack.shelf[s].towar-=a;
    sklad.handyRack.towar-=a;
    sklad.towar-=a;
}
void pop_s(){
    long long p,a;
    cin>>p>>a;
    if ( a<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyShelf.zajete || p>128 || p<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.handyShelf.place[p].ilosc-a<0)
    {
        a=sklad.handyShelf.place[p].ilosc;
    }
    sklad.handyShelf.place[p].ilosc-=a;
    sklad.handyShelf.towar-=a;
    sklad.towar-=a;
}
void mov_w(){
    long long wb,rb,sb,we,re,se,p,a;
    cin>>wb>>rb>>sb>>we>>re>>se>>p>>a;
    if ( wb >= sklad.zajete || we >= sklad.zajete || wb < 0 || we < 0)
    {
        cout<<"error\n";
        return;
    }
    if ( rb >= sklad.warehouse[wb].zajete || re>=sklad.warehouse[we].zajete || re < 0 || rb < 0)
    {
        cout<<"error\n";
        return;

    }
    if ( sb>=sklad.warehouse[wb].rack[rb].zajete || se>=sklad.warehouse[we].rack[re].zajete || sb < 0 || se < 0 )
    {
        cout<<"error\n";
        return;
    }
    if (p >=sklad.warehouse[wb].rack[rb].shelf[sb].zajete || p >=sklad.warehouse[we].rack[re].shelf[se].zajete || p < 0)
    {
        cout<<"error\n";
        return;
    }
    if ( a<0 )
    {
        cout<<"error\n";
        return;
    }
    if (sklad.warehouse[wb].rack[rb].shelf[sb].place[p].ilosc < a )
    {
        a=sklad.warehouse[wb].rack[rb].shelf[sb].place[p].ilosc;
    }
    if ( sklad.warehouse[we].rack[re].shelf[se].place[p].ilosc+a>65535)
    {
        a=65535-sklad.warehouse[we].rack[re].shelf[se].place[p].ilosc;
    }
        sklad.warehouse[wb].rack[rb].shelf[sb].place[p].ilosc-=a;
        sklad.warehouse[wb].rack[rb].shelf[sb].towar-=a;
        sklad.warehouse[wb].rack[rb].towar-=a;
        sklad.warehouse[wb].towar-=a;
        sklad.warehouse[we].rack[re].shelf[se].place[p].ilosc+=a;
        sklad.warehouse[we].rack[re].shelf[se].towar+=a;
        sklad.warehouse[we].rack[re].towar+=a;
        sklad.warehouse[we].towar+=a;
}
void mov_h(){
    long long w,r,s,p,a;
    cin>>w>>r>>s>>p>>a;
    if ( w>=sklad.zajete || w < 0  ||  w  > 127)
    {
        cout<<"error\n";
        return;
    }
    if ( r>=sklad.warehouse[w].zajete || r < 0 )
    {
        cout<<"error\n";
        return;
    }
    if (s>=sklad.warehouse[w].rack[r].zajete || s < 0 )
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].rack[r].shelf[s].zajete || p>=sklad.warehouse[w].handyShelf.zajete || p < 0)
    {
        cout<<"error\n";
        return;
    }
    if ( a < 0 )
    {
        cout<<"error\n";
        return;
    }
    if (sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc < a )
    {
        a=sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc;
    }
    if ( sklad.warehouse[w].handyShelf.place[p].ilosc + a> 65535 )
    {
        a=65535-sklad.warehouse[w].handyShelf.place[p].ilosc;

    }
   sklad.warehouse[w].rack[r].shelf[s].place[p].ilosc-=a;
   sklad.warehouse[w].rack[r].shelf[s].towar-=a;
   sklad.warehouse[w].rack[r].towar-=a;
   sklad.warehouse[w].handyShelf.place[p].ilosc+=a;
   sklad.warehouse[w].handyShelf.towar+=a;

}
void mov_r(){
    long long w,r,sb,se,p,a;
    cin>>w>>r>>sb>>se>>p>>a;
    if ( w >= sklad.zajete || w<0)
    {
        cout<<"error\n";
        return;
    }
    if ( r >=sklad.warehouse[w].zajete || r<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sb >=sklad.warehouse[w].rack[r].zajete || se >=sklad.handyRack.zajete || se<0 || sb<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].rack[r].shelf[sb].zajete || p >= sklad.handyRack.shelf[se].zajete ||p<0)
    {
        cout<<"error\n";
        return;
    }
    if (a<0 )
    {
        cout<<"error\n";
        return;
    }
    if  (sklad.warehouse[w].rack[r].shelf[sb].place[p].ilosc<a)
    {
        a=sklad.warehouse[w].rack[r].shelf[sb].place[p].ilosc;
    }
    if ( sklad.handyRack.shelf[se].place[p].ilosc+a>65535)
    {
        a=65535-sklad.handyRack.shelf[se].place[p].ilosc;

    }
    sklad.warehouse[w].rack[r].shelf[sb].place[p].ilosc-=a;
    sklad.warehouse[w].rack[r].shelf[sb].towar-=a;
    sklad.warehouse[w].rack[r].towar-=a;
    sklad.warehouse[w].towar-=a;
    sklad.handyRack.shelf[se].place[p].ilosc+=a;
    sklad.handyRack.shelf[se].towar+=a;
    sklad.handyRack.towar+=a;
}
void mov_s(){
    long long s,p,a;
    cin>>s>>p>>a;
    if ( a<0 )
    {
        cout<<"error\n";
        return;
    }
    if ( s>=sklad.handyRack.zajete || s>127 || s<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyRack.shelf[s].zajete || p>=sklad.handyShelf.zajete || p>127 ||p<0)
    {
        cout<<"error\n";
        return;
    }
    if  (sklad.handyRack.shelf[s].place[p].ilosc<a)
    {
        a=sklad.handyRack.shelf[s].place[p].ilosc;
    }
    if ( sklad.handyShelf.place[p].ilosc+a>65535)
    {
        a=65535-sklad.handyShelf.place[p].ilosc;
    }
    sklad.handyRack.shelf[s].place[p].ilosc-=a;
    sklad.handyRack.shelf[s].towar-=a;
    sklad.handyRack.towar-=a;
    sklad.handyShelf.place[p].ilosc+=a;
    sklad.handyShelf.towar+=a;
}
void get_e(){
    cout<<sklad.towar<<endl;
}
void get_w(){
    short w;
    cin>>w;
    if ( w<0 || w >=sklad.zajete)
    {
        cout<<"error\n";
        return;
    }
    cout<<sklad.warehouse[w].towar<<endl;

}
void get_rw(){
    short w,r;
    cin>>w>>r;
    if ( w<0 || w>=sklad.zajete)
    {
        cout<<"error\n";
        return;
    }
    if ( r<0 || r>=sklad.warehouse[w].zajete)
    {
        cout<<"error\n";
        return;
    }
    cout<<sklad.warehouse[w].rack[r].towar<<endl;

}
void get_rh(){
    cout<<sklad.handyRack.towar<<endl;
}
void get_sw(){
    short w,r,s;
    cin>>w>>r>>s;

    if (sklad.zajete<=w || w<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.warehouse[w].zajete<=r || r<0)
    {
        cout<<"error\n";
        return;
    }
    if ( sklad.warehouse[w].rack[r].zajete<=s ||s<0)
    {
        cout<<"error\n";
        return;
    }
    cout<<sklad.warehouse[w].rack[r].shelf[s].towar<<endl;
}
void get_sh(){
    short w;
    cin>>w;

    if ( sklad.zajete<=w || w<0)
    {
        cout<<"error\n";
        return;
    }
    cout<<sklad.warehouse[w].handyShelf.towar<<endl;
}
void get_sr(){
    short s;
    cin>>s;
    if ( s>=sklad.handyRack.zajete || s<0)
    {
        cout<<"error\n";
        return;
    }
    cout<<sklad.handyRack.shelf[s].towar<<endl;
}
void get_s(){
    cout<<sklad.handyShelf.towar<<endl;
}
void set_lw(){
    long long w,r,s,p,label=0;
    unsigned char x[3];
    cin>>w>>r>>s>>p>>x;
    if ( x[0]>='0' && x[0]<='9' && x[1]>='0' && x[1]<='9')
        {
            if(x[0]=='0' && x[1]=='0')
            {
                label=100;
            }
            else label = 10 * (x[0]-'0')+x[1]-'0';
        }
        else {

            cout<<"error\n";
            return;
        }
    if ( w>=sklad.zajete || w<0 || w>127)
    {
        cout<<"error\n";
        return;
    }
    if ( r>=sklad.warehouse[w].zajete || r >127 || r<0)
    {
        cout<<"error\n";
        return;
    }
    if ( s>=sklad.warehouse[w].rack[r].zajete || s<0 || s>127)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].rack[r].shelf[s].zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    sklad.warehouse[w].rack[r].shelf[s].place[p].etykieta=label;
}
void set_lh(){
    long long w,p,label=0;
    unsigned char x[3];
    cin>>w>>p>>x;
    if ( x[0]>='0' && x[0]<='9' && x[1]>='0' && x[1]<='9')
        {if(x[0]=='0' && x[1]=='0')
            {
                label=100;
            }
            else
            label = 10 * (x[0]-'0')+x[1]-'0';
        }
        else {

            cout<<"error\n";
            return;
        }
    if ( w>=sklad.zajete || w>127 || w<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].handyShelf.zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    sklad.warehouse[w].handyShelf.place[p].etykieta=label;

}
void set_lr(){
    long long s,p,label=0;
    unsigned char x[3];
    cin>>s>>p>>x;
        if ( x[0]>='0' && x[0]<='9' && x[1]>='0' && x[1]<='9')
        {if(x[0]=='0' && x[1]=='0')
            {
                label=100;
            }
            else
            label = 10 * (x[0]-'0')+x[1]-'0';
        }
        else {

            cout<<"error\n";
            return;
        }
    if (s>=sklad.handyRack.zajete || s>127 || s<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyRack.shelf[s].zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    sklad.handyRack.shelf[s].place[p].etykieta=label;
}
void set_ls(){
   int t,label=0;
   char x[3];
    cin>>t;
    cin>>x;
    if ( x[0]>='0' && x[0]<='9' && x[1]>='0' && x[1]<='9')
    {if(x[0]=='0' && x[1]=='0')
            {
                label=100;
            }
            else
        label = 10 * (x[0]-'0')+x[1]-'0';
    }
    else {
        cout<<"error\n";
        return;
    }

    if ( sklad.handyShelf.zajete <= t || t > 127 || t < 0)
    {
        cout<<"error\n";
        return;
    }
    sklad.handyShelf.place[t].etykieta=label;
}
void get_lw(){
    long long w,r,s,p;
    cin>>w>>r>>s>>p;
    if ( w>=sklad.zajete || w>127 || w<0)
    {
        cout<<"error\n";
        return;
    }
    if ( r>=sklad.warehouse[w].zajete || r<0 || r>127)
    {
        cout<<"error\n";
        return;
    }
    if ( s>=sklad.warehouse[w].rack[r].zajete || s<0 || s>127)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].rack[r].shelf[s].zajete || p<0 ||p>127)
    {
        cout<<"error\n";
        return;
    }
    if(sklad.warehouse[w].rack[r].shelf[s].place[p].etykieta==0)
    {
        cout<<"--"<<endl;
        return;
    }
     if (sklad.warehouse[w].rack[r].shelf[s].place[p].etykieta == 100 )
    {
        cout<<"00"<<endl;
        return;
    }
    if (sklad.warehouse[w].rack[r].shelf[s].place[p].etykieta < 10 )
    {
        cout<<"0";
    }
cout<<sklad.warehouse[w].rack[r].shelf[s].place[p].etykieta<<endl;
}
void get_ls(){
    unsigned short p;
    cin>>p;
    if ( sklad.handyShelf.zajete <= p || p > 127 || p < 0)
    {
        cout<<"error\n";
        return;
    }
    if (sklad.handyShelf.place[p].etykieta==0)
    {
        cout<<"--"<<endl;
        return;
    }
    if (sklad.handyShelf.place[p].etykieta == 100 )
    {
        cout<<"00"<<endl;
        return;
    }
    if (sklad.handyShelf.place[p].etykieta < 10 )
    {
        cout<<"0";
    }
cout<<sklad.handyShelf.place[p].etykieta<<endl;
}
void get_lr(){
    long long s,p;
    cin>>s>>p;
    if (s>=sklad.handyRack.zajete || s>127 || s<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.handyRack.shelf[s].zajete || p>127 || p<0)
    {
        cout<<"error\n";
        return;
    }
    if(sklad.handyRack.shelf[s].place[p].etykieta==0)
     {
        cout<<"--"<<endl;
        return;
    }
     if (sklad.handyRack.shelf[s].place[p].etykieta == 100 )
    {
        cout<<"00"<<endl;
        return;
    }
    if (sklad.handyRack.shelf[s].place[p].etykieta < 10 )
    {
        cout<<"0";
    }
cout<<sklad.handyRack.shelf[s].place[p].etykieta<<endl;
}
void get_lh(){
    long long w,p;
    cin>>w>>p;
    if ( w>=sklad.zajete ||w>127 ||w<0)
    {
        cout<<"error\n";
        return;
    }
    if ( p>=sklad.warehouse[w].handyShelf.zajete||p>127||p<0)
    {
        cout<<"error\n";
        return;
    }
    if(sklad.warehouse[w].handyShelf.place[p].etykieta==0)
    {
        cout<<"--"<<endl;
        return;
    }
    if (sklad.warehouse[w].handyShelf.place[p].etykieta == 100 )
    {
        cout<<"00"<<endl;
        return;
    }
    if (sklad.warehouse[w].handyShelf.place[p].etykieta < 10 )
    {
        cout<<"0";
    }
    cout<<sklad.warehouse[w].handyShelf.place[p].etykieta<<endl;
}
void rozpoznaj ( char * polecenie ){
    if ( polecenie[0]=='F')//fill
    {
        FILL();
    }
    char s[7]="SET-AP";
    int cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-ap
    {
        set_ap();
    }
    s[5]='S';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-as
    {
        set_as();
    }
    s[5]='R';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-ar
    {
        set_ar();
    }
    s[5]='W';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-aw
    {
        set_aw();
    }
    s[4]='H';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-hw
    {
        set_hw();
    }
    s[5]='R';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-hr
    {
        set_hr();
    }
    s[5]='S';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-hs
    {
        set_hs();
    }
    s[4]='L';
    s[5]='W';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-lw
    {
        set_lw();
    }
    s[5]='H';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-lh
    {
        set_lh();
    }
    s[5]='R';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-lr
    {
        set_lr();
    }
    s[5]='S';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//set-ls
    {

        set_ls();
    }
    s[0]='G';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-ls
    {
        get_ls();
    }
    s[5]='R';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-lr
    {
        get_lr();
    }
    s[5]='H';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-lh
    {
        get_lh();
    }
    s[5]='W';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-lw
    {
        get_lw();
    }
    s[4]='S';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-sw;
    {
        get_sw();
    }
    s[5]='H';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-sh
    {
        get_sh();
    }
    s[5]='R';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-sr
    {
        get_sr();
    }
    s[4]='R';
    s[5]='H';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-rh
    {
        get_rh();
    }
    s[5]='W';
    cunt=0;
    for ( int i = 0; i<7; i++)
    {
        if ( s[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==7)//get-rw
    {
        get_rw();
    }
    char s1[6]="PUT-W";
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//put-w
    {
        put_w();
    }
    s1[4]='H';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//put-h
    {
        put_h();
    }
    s1[4]='R';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//put-r
    {
        put_r();
    }
    s1[4]='S';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)
    {
        put_s();
    }
    s1[0]='G';
    s1[1]='E';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//get-s
    {
        get_s();
    }
    s1[4]='W';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//get_w
    {
        get_w();
    }
    s1[4]='E';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//get-e
    {
        get_e();
    }
    s1[0]='P';
    s1[1]='O';
    s1[2]='P';
    s1[3]='-';
    s1[4]='W';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//pop-w
    {
        pop_w();
    }
    s1[4]='H';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)
    {
        pop_h();
    }
    s1[4]='R';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//pop-r
    {
        pop_r();
    }
    s1[4]='S';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//pop-s
    {
        pop_s();
    }
    s1[0]='M';
    s1[1]='O';
    s1[2]='V';
    s1[3]='-';
    s1[4]='W';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//mov-w
    {
        mov_w();
    }
    s1[4]='H';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//mov-h
    {
        mov_h();
    }
    s1[4]='R';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//mov-r
    {
        mov_r();
    }
    s1[4]='S';
    cunt=0;
    for ( int i = 0; i<6; i++)
    {
        if ( s1[i]==polecenie[i])
        {
            cunt++;
        }
    }
    if ( cunt==6)//mov-s
    {
        mov_s();
    }
}
int main(){
    char polecenie[7];
    while(cin>>polecenie)
    {
        if(polecenie[0]=='E')
        {
            break;
        }
        else rozpoznaj(polecenie);
    }
    return 0;
}
