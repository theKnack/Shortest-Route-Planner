#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;

vector<string>spots;
vector<ll>go;
vector<ll>order;
vector<vector<float> >dis(20,vector<float>(14,0));
vector<bool>wish(20,0);

void pre_process0(){
    spots.pb("City Palace");
    spots.pb("Hawa Mahal");
    spots.pb("Jal Mahal");
    spots.pb("Amber Fort");
    spots.pb("Nahargarh Fort");
    spots.pb("Albert Hall Museum");
    spots.pb("Galtaji Temple");
    spots.pb("Puskar Temple");
    spots.pb("Jaipur Zoo");
    spots.pb("Bhangarh Fort");
    spots.pb("Pink City Market");
    spots.pb("Jantar Mantar");
    spots.pb("Ajmer Sharif Dargah");
    spots.pb("Birla Temple");
}
void pre_process1(){
    dis[0]={0,0.6,7.4,7.8,8,2.2,9,152,1.8,70,1.1,0.2,136,4.4};
    dis[1]={0.6,0,7.6,8.1,8.4,2.3,9.1,153,1.9,82.3,1,0.7,135,4};
    dis[2]={7.4,7.6,0,3.5,3.7,11.6,13,188,11.4,86.4,8.7,8,145,8};
    dis[3]={7.8,8.1,3.5,0,0.3,10,12.7,192,5.5,68,4.7,4.2,140,8};
    dis[4]={8,8.4,3.7,0.3,0,10.2,12.9,192.,5.7,68,5,4.4,140,8.2};
    dis[5]={2.2,2.3,11.6,10,10.2,0,10.3,171,1.5,74,1.9,2.6,134,2};
    dis[6]={9,9.1,13,12.7,12.9,10.3,0,171,1.5,74.1,1.9,2.6,140,2};
    dis[7]={152,153,188,192,192,171,171,0,202,232,150,151,14.5,192};
    dis[8]={1.8,1.9,11.4,5.5,5.7,1.5,1.5,202,0,81.7,2,2.6,134,2.6};
    dis[9]={70,82.3,86.4,68,68,74,74.1,232,81.7,0,71,83,215,80};
    dis[10]={1.1,1,8.7,4.7,5,1.9,1.9,150,2,71,0,0.7,136,4.1};
    dis[11]={0.2,0.7,8,4.2,4.4,2.6,2.6,151,2.6,83,0.7,0,136,4.5};
    dis[12]={136,135,145,140,140,134,140,14.5,134,215,136,136,0,133};
    dis[13]={4.4,4,8,8,8.2,2,2,192,2.6,80,4.1,4.5,133,0};
}
void pre_process(){
    pre_process0();
    pre_process1();
}

void input(){
    string s;
    for(auto it=spots.begin();it!=spots.end();it++){
        cout<<"Do you want to visit "<<*it<<"? Yes/No(Y/N) "<<endl;
        cin>>s;
        if(s=="Yes"||s=="yes"||s=="y"||s=="Y"){
            go.pb(it-spots.begin());
            wish[it-spots.begin()]=1;
        }
        cout<<endl;
    }
}
ll shor(ll pre){
    ll ma=LLONG_MAX;
    ll ind=-1;
    for(auto it=go.begin();it!=go.end();it++){
        if(*it!=pre&&wish[*it]==1&&dis[pre][*it]<ma){
            ma=dis[pre][*it];
            ind=*it;
        }
    }
    return ind;
}

void compute(){
    ll prev=go[0],next;
    wish[prev]=0;
    ll len=go.size()-1;
    order.pb(prev);
    for(ll i=0;i<len;i++){
        next=shor(prev);
        wish[next]=0;
        order.pb(next);
        prev=next;
    }
    order.pb(order[0]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre_process();
    input();
    compute();
    cout<<"Shortest route is: "<<endl;
    for(auto it=order.begin();it!=order.end();it++){
        if(it!=order.begin())
            cout<<"->";
        cout<<spots[*it];
    }
    cout<<endl;

    return 0;
}

