#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::endl;

class zodziai
{
    protected:
    std::string z;
    public:
        zodziai(std::string a)
        {
            z=a;
        }

        bool operator<(const zodziai& rhs) const {
  if (z < rhs.z) return true;
  else return false;
}
void print()
        {
            cout<<z<<"\n";
        }
};

class zodziai_sk: public zodziai
{
private:
std::size_t sk;
    public:
void print()
        {
            cout<<z<<" "<<sk<<"\n";
        }
};
int main()
{
    std::set<zodziai> a;
zodziai b("grazus");
zodziai x("xenomorph");
zodziai p ("dog");
zodziai pp ("dog");
a.insert(b);
a.insert(p);
a.insert(x);
a.insert(pp);
  for(zodziai h:a)
  {
      h.print();
  }
    return 0;
}
