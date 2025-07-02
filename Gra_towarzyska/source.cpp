//Mateusz Paszyñski
#include <iostream>

using namespace std;

int main()
{
    float l, wa=0, ra=0, pa=0, wb=0, rb=0, pb=0, wc=0, rc=0, pc=0, wd=0, rd=0, pd=0, sa=0, sb=0, sc=0, sd=0 ;
    char gracz1, gracz2 ;
    int moc1, moc2 ;
    char g1, g2 ;

    cin >> l;
    while(l)
    {
        cin >> gracz1 >> g1 >> moc1 >> gracz2 >> g2 >> moc2 ;
        if( g1 == g2 )
        {
            if ( moc1 > moc2 )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd =  wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    pb = pb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else if ( moc1 == moc2 )
            {
                if ( gracz1 == 'a' )
                {
                    ra = ra + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    rb = rb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    rc = rc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    rd = rd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    ra = ra + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    rb = rb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    rc= rc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    rd = rd + 1 ;
                }
            }
            else
            {
                if ( gracz2 == 'a' )
                {
                    wa= wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz1 == 'a' )
                {
                    pa=pa+1;
                }
                if ( gracz1 == 'b' )
                {
                    pb = pb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    pd = pd + 1 ;
                }
            }

        }
         else { if ( g1 == 'J' )
        {
            if ( g2=='P' || g2 == 'S' )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else { if ( gracz2 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if( gracz1 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if( gracz1 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    pd = pd + 1 ;
                }}
        }
        if ( g1 == 'K' )
        {
            if ( g2 == 'J' || g2 == 'N' )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else { if ( gracz2 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz1 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    pd = pd + 1 ;
                }}
        }

        if (g1 == 'N' )
        {
            if ( g2 == 'J' || g2 == 'P' )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa=pa+1;
                }
                if (gracz2=='b')
                {
                    pb = pb + 1;

                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else { if ( gracz2 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    wd = wd + 1;
                }
                if ( gracz1 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd')
                {
                    pd = pd + 1 ;
                }}
        }


        if ( g1 == 'P' )
        {
            if ( g2 == 'K' || g2 == 'S' )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else { if ( gracz2 == 'a')
                {
                    wa = wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd')
                {
                    wd = wd + 1 ;
                }
                if ( gracz1 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    pd = pd + 1 ;
                }}
        }
        if ( g1 == 'S' )
        {
            if ( g2 == 'K' || g2 == 'N' )
            {
                if ( gracz1 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz1 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz2 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz2 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    pd = pd + 1 ;
                }

            }
            else { if ( gracz2 == 'a' )
                {
                    wa = wa + 1 ;
                }
                if ( gracz2 == 'b' )
                {
                    wb = wb + 1 ;
                }
                if ( gracz2 == 'c' )
                {
                    wc = wc + 1 ;
                }
                if ( gracz2 == 'd' )
                {
                    wd = wd + 1 ;
                }
                if ( gracz1 == 'a' )
                {
                    pa = pa + 1 ;
                }
                if ( gracz1 == 'b' )
                {
                    pb = pb + 1 ;

                }
                if ( gracz1 == 'c' )
                {
                    pc = pc + 1 ;
                }
                if ( gracz1 == 'd' )
                {
                    pd = pd + 1 ;
                }}
        }
    }
        l = l - 1 ;
    }
    sa = wa + ra + pa ;
    sb = wb + rb + pb ;
    sc = wc + rc + pc ;
    sd = wd + rd + pd ;




    if ( sa != 0 )
    {   wa = ( wa * 100 ) / sa ;
        ra = ( ra * 100 ) / sa ;
        pa = ( pa * 100 ) / sa ;
        cout << "gracz a\n" ;
        if ( wa != 0 )
        {
            cout << "    wygrane: " << wa << "%\n" ;
        }
        if ( ra != 0 )
        {
            cout << "    remisy: " << ra << "%\n" ;
        }
        if ( pa != 0 )
        {
            cout << "    przegrane: " << pa << "%\n" ;
        }
        cout<<endl;
    }
    if ( sb != 0 )
    {
         wb = ( wb * 100 ) / sb ;
        rb = ( rb * 100 ) / sb ;
        pb = ( pb * 100 ) / sb ;
        cout << "gracz b\n" ;
        if ( wb != 0 )
        {
            cout << "    wygrane: " << wb << "%\n" ;
        }
        if ( rb != 0 )
        {
            cout << "    remisy: " << rb << "%\n" ;
        }
        if ( pb != 0 )
        {
            cout << "    przegrane: " << pb << "%\n" ;
        }
        cout<<endl;
    }
    if ( sc != 0 )
    {
         wc = ( wc * 100 ) / sc ;
        rc = ( rc * 100 ) / sc ;
        pc = ( pc * 100 ) / sc ;
        cout << "gracz c\n" ;
        if ( wc != 0 )
        {
            cout << "    wygrane: " << wc << "%\n" ;
        }
        if ( rc != 0 )
        {
            cout << "    remisy: " << rc << "%\n" ;
        }
        if ( pc != 0 )
        {
            cout << "    przegrane: " << pc << "%\n" ;
        }
        cout<<endl;
    }
    if ( sd != 0 )
    {
        wd = ( wd * 100 ) / sd ;
        rd = ( rd * 100 ) / sd ;
        pd = ( pd * 100 ) / sd ;
        cout << "gracz d\n" ;
        if ( wd != 0 )
        {
            cout << "    wygrane: " << wd << "%\n" ;
        }
        if ( rd != 0 )
        {
            cout << "    remisy: " << rd << "%\n" ;
        }
        if ( pd != 0 )
        {
            cout << "    przegrane: " << pd << "%\n" ;
        }
    }

    return 0;
}
