#include <iostream>
using namespace std;

struct N{int d;N*next,*prev;};
N *HD=0,*HC=0;

void IF(int x){
    N*t=new N{x,HD,0};
    if(HD)HD->prev=t;
    HD=t;
}
void IL(int x){
    N*t=new N{x,0,0};
    if(!HD){HD=t;return;}
    N*p=HD;while(p->next)p=p->next;
    p->next=t;t->prev=p;
}
void IA(int k,int x){
    N*p=HD;while(p&&p->d!=k)p=p->next;
    if(!p)return;
    N*t=new N{x,p->next,p};
    if(p->next)p->next->prev=t;
    p->next=t;
}
void DD(int k){
    N*p=HD;while(p&&p->d!=k)p=p->next;
    if(!p)return;
    if(p->prev)p->prev->next=p->next;
    else HD=p->next;
    if(p->next)p->next->prev=p->prev;
    delete p;
}
void SD(int k){
    N*p=HD;while(p){if(p->d==k){cout<<"Found\n";return;}p=p->next;}
    cout<<"Not Found\n";
}
void PD(){
    N*p=HD;while(p){cout<<p->d<<" ";p=p->next;}cout<<"\n";
}

void IFC(int x){
    N*t=new N{x,0,0};
    if(!HC){HC=t;t->next=t;return;}
    N*p=HC;while(p->next!=HC)p=p->next;
    t->next=HC;p->next=t;HC=t;
}
void ILC(int x){
    N*t=new N{x,0,0};
    if(!HC){HC=t;t->next=t;return;}
    N*p=HC;while(p->next!=HC)p=p->next;
    p->next=t;t->next=HC;
}
void IAC(int k,int x){
    if(!HC)return;
    N*p=HC;
    do{
        if(p->d==k){
            N*t=new N{x,p->next,0};
            p->next=t;return;
        }
        p=p->next;
    }while(p!=HC);
}
void DC(int k){
    if(!HC)return;
    N*p=HC,*q=0;
    do{
        if(p->d==k){
            if(p==HC){
                N*l=HC;while(l->next!=HC)l=l->next;
                if(l==HC){delete HC;HC=0;return;}
                HC=HC->next;l->next=HC;delete p;return;
            }
            q->next=p->next;delete p;return;
        }
        q=p;p=p->next;
    }while(p!=HC);
}
void SC(int k){
    if(!HC){cout<<"Not Found\n";return;}
    N*p=HC;
    do{if(p->d==k){cout<<"Found\n";return;}p=p->next;}while(p!=HC);
    cout<<"Not Found\n";
}
void PC(){
    if(!HC){cout<<"\n";return;}
    N*p=HC;do{cout<<p->d<<" ";p=p->next;}while(p!=HC);cout<<"\n";
}

int main(){
    int c,t,x,k,p;
    for(;;){
        cout<<"1 Insert\n2 Delete\n3 Search\n4 Display\n5 Exit\n";
        cin>>c;if(c==5)break;
        cout<<"1 Doubly 2 Circular\n";cin>>t;
        if(c==1){
            cout<<"1 First 2 Last 3 After\n";cin>>p;
            cout<<"Value ";cin>>x;
            if(t==1){
                if(p==1)IF(x);
                else if(p==2)IL(x);
                else{cout<<"Key ";cin>>k;IA(k,x);}
            }else{
                if(p==1)IFC(x);
                else if(p==2)ILC(x);
                else{cout<<"Key ";cin>>k;IAC(k,x);}
            }
        }else if(c==2){
            cout<<"Key ";cin>>k;
            if(t==1)DD(k);else DC(k);
        }else if(c==3){
            cout<<"Key ";cin>>k;
            if(t==1)SD(k);else SC(k);
        }else{
            if(t==1)PD();else PC();
        }
    }
}

