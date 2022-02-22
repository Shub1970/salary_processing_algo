#include<iostream>
#include<string>
using namespace std;

class Engineer{
    protected:
     string name_;
    public:
     Engineer(const string &name):name_(name){}
     virtual void salaryprocessing(){cout<<name_<<" : process salary for Engineer"<<endl;}
};
class Manager:public Engineer{
    Engineer* reports[10];
    public:
     Manager(const string &name):Engineer(name){}
     void salaryprocessing(){cout<<name_<<" : process salary for Manager"<<endl;}
};
class Director:public Manager{
     Manager* reports[10];
    public:
     Director(const string &name): Manager(name){}
     void salaryprocessing(){cout<<name_<<" : process salary for Director"<<endl;}   
};
int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    std::ios::sync_with_stdio(false);
    //--------------------------------------------------------------------------//

    Engineer e1("Rohit"),e2("shuhbham"),e3("kavita"),e4("shambhu");
    Manager  m1("kamal"),m2("rajib");
    Director d1("ranjana"),d2("shivam");
    Engineer *staff[]{&e1,&e2,&e3,&e4,&m1,&m2,&d1,&d2};
    for(int i{};i<sizeof(staff)/sizeof(Engineer*);i++){
         staff[i]->salaryprocessing();
    }
return 0;
}