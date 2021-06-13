#include "iostream"
#include "math.h"
#include "vector"
using namespace std;

class NPoint
{   private:
        vector <int> m_Coordi;
    public:
        NPoint(vector <int> c)   { m_Coordi=c;	}
        double Distance(const NPoint& p)
        {   double d(0);
            int size=m_Coordi.size();
            if(size != p.m_Coordi.size())
            {   cout<<"Two points locate in different space!"<<endl;
                exit(1);	  }
            for(int i=0; i<size; i++)
                d+=(m_Coordi[i]-p.m_Coordi[i]) *(m_Coordi[i]-p.m_Coordi[i]);
            return sqrt(d);
        }
        friend  double Distance(const NPoint& p1, const NPoint& p2);
};

double Distance(const NPoint& p1, const NPoint& p2)
{   double d(0);
    int size=p1.m_Coordi.size();
    if(size != p2.m_Coordi.size())
    {   cout<<"Two points locate in different space!"<<endl;
        exit(1);     }
    for(int i=0; i<size; i++)
        d+=(p1.m_Coordi[i]-p2.m_Coordi[i]) *(p1.m_Coordi[i]-p2.m_Coordi[i]);
    return sqrt(d);
}

vector <int> & CreateNPoint(vector <int>&  c)
{   int i=0;
    cout<<"Input the coordinates of a point in N-Space"<<endl;
    while(++i)
    {   double temp=0;
        cout<<"Enter the "<<i<<"th coordinate: ";
        cin >> temp;
        if(temp>=100) break;
        c.push_back(temp);
    }
    return c;
}

int main(int argc, char* argv[])
{   vector <int> cc, dd;
    cc=CreateNPoint(cc);
    dd=CreateNPoint(dd);

	 NPoint p1(cc), p2(dd);
	 cout<<"Distance 1 is :"<<p1.Distance(p2)<<endl;
	 cout<<"Distance 2 is :"<<Distance(p2,p1)<<endl;
  
  return 0;			
}