#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main(void)
{
  int num;
  srand((unsigned)time(NULL));
  while(cin>>num)
  {
    string fn;
    int rd_h=rand()%8999+1001, rd_l=rand()%8999+1001;
    char t[5]="";
    sprintf(t, "%d", rd_h);
    fn+=t;
    sprintf(t, "%d", rd_l);
    fn+=t;
    fn+=".htm";
    cout<<num<<'\t'<<"http://www.wqy.ac.cn/act/"<<fn<<endl;
    ifstream fin("ex.htm");
    ofstream fout(fn);
    if(!fin.is_open())
    {
      cout<<"Error."<<endl;
      break;
    }
    while(!fin.eof())
    {
      char c;
      fin.get(c);
      if(c=='#') fout<<num;
      else fout<<c;
    }
    fin.close();
    fout.close();
  }
  return 0;
}
