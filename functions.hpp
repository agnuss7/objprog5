#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <ctype.h>
#include <stdlib.h>

using std::cout;
void read (std::multimap <std::string,int> & a, std::set<std::string> & B,const std::string st)
{
    std::ifstream df (st);
    std::string w;
    char c;
    int ln=1;
    bool k=false;
    while(df.get(c))
    {
        if(!isalpha(c))
        {
	    if(int(c)==39)
	    {
		k=false;
		w.push_back(c);
	    }
            if(k==true)
            {
                B.insert(w);
                a.insert(std::pair<std::string, int>(w,ln));
                w.clear();
                k=false;
            }
            if(c=='\n')
            {
                ln++;
            }
        }
        if(isalpha(c))
        {
            k=true;
            if(isupper(c))
            {
                c=tolower(c);
            }
            w.push_back(c);
        }
    }
    df.close();
}

void print(std::multimap <std::string,int> & a, std::set<std::string> & B)
{
    std::set<std::string>::iterator f=B.begin();
    std::pair <std::multimap<std::string,int>::iterator, std::multimap<std::string,int>::iterator> ret;
    cout<<"\nZodis | kiek kartojasi | eilutes\n---|---|---\n";
    for(; f!=B.end(); f++)
    {
        if(a.count(*f)>1)
        {
            ret = a.equal_range(*f);
            cout<<(*f)<<" | "<<a.count(*f)<<" | ";
            cout<< ret.first->second;
            ret.first++;
            for (std::multimap<std::string,int>::iterator it=ret.first; it!=ret.second; ++it)
            {
                cout <<", "<< it->second;
            }
            cout<< '\n';
        }
    }
}
