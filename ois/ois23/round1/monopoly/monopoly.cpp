// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

// input data
int N, K;
vector<int> T;

int main() {
    //  uncomment the following lines if you want to read/write from files
      ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N >> K;
    T.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    // insert your code here
    long long int lancio=0,max,index,elim=0;
    vector<long long int> memory,tasseMax;
    //int max;
    vector<long long int> range,app;
    long long int j,pos=0,tassa=T[0],temp=T[0]; //pos=posizione reale in T
    int c;


    
    //range delle prime 12 posizioni
    if(N>12){
        range.assign(T.begin(),T.begin()+12);
    }else{
        range.assign(T.begin(),T.begin()+N);
        cout<<endl<<"size: "<<range.size()<<endl;
        j=0;
        for(long long int i=range.size();i<=12;i++){
            range.push_back(T[j]);
            j++;
        }
    }
    cout<<"range 1:"<<endl;
    for(auto i: range){
        cout<<i<<endl;
    }
    cout<<endl<<endl; //ho creato il vettore da 12



    // max=*max_element(range.begin()+1,range.end()); //trovo il max
    // memory.push_back(max);
    // auto it=find(range.begin()+1, range.end(), max);
    // cout<<endl<<endl<<"index1: "<<it-range.begin();
    // index=it-range.begin();
    int v=0;
    app=range;
    //int start=0;

long long int i,somma=0;

    //int v;
    while(lancio!=3){
        //v++;

        max=*max_element(app.begin()+1,app.end()); //trovo il max
        memory.push_back(max);
        auto it=find(range.begin()+1, range.end(), max);
        cout<<endl<<endl<<"index2: "<<it-range.begin();
        index=it-range.begin();     ///SONO QUI  index2=3
        //2 lancio
        cout<<endl<<"lancio: "<<lancio<<endl;
        cout<<endl<<endl<<"lancio2"<<endl;
        if(index%2==0){ //index pari
            //tasseMax.push_back(range[index]);
 
            lancio++;
            somma=0;
            for(auto it: memory){
                somma+=it;
            }
            cout<<"somma: "<<somma;
            if(somma<memory.front()){
                //non conviene continuare
                cout<<endl<<range.front()+index<<endl;
                //app.erase(app.begin()+index);
            }else{
                if(lancio!=3){
                cout<<"index pari"<<endl;
                tasseMax.push_back(range[index]);
                //range delle prime 12 posizioni
                pos+=index;
                if(pos>12){
                    pos=pos-12+1;
                }
                cout<<"pos3: "<<pos<<endl;
                cout<<endl<<"elemento: "<<T[pos]<<endl;
                //range delle prime 12 posizioni
                cout<<endl<<N;
                if(N>12&&N-pos>12){ 
                    cout<<"end: "<<range.back();
                    range.assign(range.begin()+pos,range.begin()+(pos+13));

                    for(int i=range.size();i<12&&j<T.size();i++){
                        range.push_back(T[j]);
                        cout<<endl<<"T[j]: "<<T[j];
                        j++;
                        if(j==T.size()) j=0;
                    }

                
                }else{

                    range.assign(T.begin()+pos,T.end());
                    cout<<endl<<"size3: "<<range.size()<<endl;
                    j=0;
                    
                    for(int i=range.size();i<=12;i++){
                        range.push_back(T[j]);
                        j++;
                    }
                }
                
                cout<<endl<<"range3:"<<endl;
                for(auto i: range){
                    cout<<i<<endl;
                }
                cout<<endl<<endl; //ho creato il vettore da 12

                app=range;
            }else{
                somma=0;
                for(auto e: memory){
                    somma+=e;
                }
                if(somma>tasseMax.back())    tasseMax.push_back(somma);
                
                //lancio--;
                // memory.pop_back();
                // memory.pop_back();
            }
            cout<<"lancio ultimo: "<<lancio;

            }

            
           

        }else{ 
            cout<<"index dispari"<<endl;
            
            
            //erase max precedente, controllo secondo in "classifica" dei massimi nel primo lancio
            cout<<endl<<"range senza erase:"<<endl;
            for(auto i: app){
                cout<<i<<endl;
            }

            //escludi il più grande già controllato dal range
            max=*max_element(app.begin()+1,app.end()); //trovo il max
            cout<<endl<<"max: "<<max;
            auto el=find(app.begin()+1, app.end(), max);
            cout<<endl<<endl<<"indexpererase: "<<el-app.begin();
            app.erase(app.begin()+(el-app.begin()));
            cout<<endl<<"range con erase:"<<endl;
            for(auto i: app){
                cout<<i<<endl;
            }
            cout<<endl<<endl; //ho creato il vettore da 12

        
            
            cout<<endl<<"memory:";
            for(auto i: memory){
            cout<<endl<<i;
            }
            somma=0,j=0;
            cout<<endl<<"lancio: "<<lancio<<endl;
            cout<<endl<<"somma1: "<<somma<<endl;
            for(i=memory.size()-lancio-1;j<=lancio;j++,i++){
                somma+=memory[i];
                cout<<endl<<"memory[i]: "<<memory[i]<<endl;
                cout<<endl<<"somma: "<<somma<<endl;
            }
            if(somma>tasseMax.back())    tasseMax.push_back(somma);
            

            //elimino dalla memoria l'elemento con indice dispari(non mi serve più)
            memory.pop_back();
            if(lancio==2){ //ho fatto 3 lanci con la strada migliore possibile
            cout<<"lancio==2"<<endl;
                v++;
                //escludi il più grande già controllato dal range
                max=*max_element(app.begin()+1,app.end()); //trovo il max
                cout<<endl<<"max: "<<max;
                auto el=find(app.begin()+1, app.end(), max);
                cout<<endl<<endl<<"indexpererase: "<<el-app.begin();
                app.erase(app.begin()+(el-app.begin()));
                cout<<endl<<"range con erase:"<<endl;
                for(auto i: app){
                    cout<<i<<endl;
                }
                cout<<endl<<endl; //ho creato il vettore da 12
                //lancio=0;
            }

        }
      cout<<endl<<"memory:";
    for(auto i: memory){
    cout<<endl<<i;
    }


    cout<<endl<<"tasseMax:";
    for(auto i: tasseMax){
    cout<<endl<<i;
    }
    cout<<endl<<endl;

    }    


   
 

    //cout<<endl<<"v: "<<v<<endl;




    cout <<*max_element(tasseMax.begin(),tasseMax.end())<< endl;  // print the result
    return 0;
}
