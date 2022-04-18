#include<iostream>
#include<cstring>
using namespace std;

typedef enum E_TYPE {Er,Mgr,Dir} E_TYPE;
class Engineer{
   protected:
    string name_; E_TYPE type_;
   public:
    Engineer(const string &name,E_TYPE e=Er):name_(name),type_(e){}
    E_TYPE GetType(){return type_;}
    void processSalary(){cout<<name_<<": process Salary for Engineer"<<endl;}
};
class Manager:public Engineer{
    Engineer *reports_[10];
   public:
    Manager(const string &name,E_TYPE e=Mgr):Engineer(name,e){}
    void processSalary(){cout<<name_<<": proces Salary for manager "<<endl;}
};
class Director:public Manager{
   Manager *reports_[10];
   public:
   Director(const string &name,E_TYPE e=Dir):Manager(name,e){}
   void processSalary(){cout<<name_<<": process salary for director"<<endl;}
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    std::ios::sync_with_stdio(false);
    //-------------------------------------------------------------------------------//
    Engineer e1("Rohit"),e2("shuhbham"),e3("kavita"),e4("shambhu");
    Manager  m1("kamal"),m2("rajib");Director d1("ranjana"),d2("shivam");
    Engineer *staff[]{&e1,&e2,&e3,&e4,&m1,&m2,&d1,&d2};
    for(int i{};i<sizeof(staff)/sizeof(Engineer*);i++){
       E_TYPE t=staff[i]->GetType();
       if(t==Er) staff[i]->processSalary();
       else if(t==Mgr)((Manager*)staff[i])->processSalary();
       else if(t==Dir)((Director*)staff[i])->processSalary();
       else cout<<"Invalid Staff Type"<<endl;

    }
    return 0;

}
