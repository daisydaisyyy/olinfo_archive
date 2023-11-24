// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// input data
int N, K;
vector<int> T;
vector<int> sub,memory,values,app;
int j,lancio=0;




vector<int> creaSub(int start,vector<int> app){
//creo subarray
    if(N-start>12){
        app.assign(T.begin()+start,T.begin()+12);
    }else if(N-start<0){

            
    }else{
        app.assign(T.begin()+start,T.end());
        // cout<<endl<<"size: "<<range.size()<<endl;
        j=0;
        for(long long int i=app.size();i<=12;i++){
            app.push_back(T[j]);
            j++;
            if(j>=T.size()) j=0;
        }
    }
    return app;
}




void control(int start, vector<int> sub){

    //cout<<endl<<"start: "<<start<<endl;
    lancio++;


    //     //stampa
    // cout<<endl<<"sub1: "<<endl;
    // for(auto it: sub){
    //     cout<<it<<endl;
    // }   
    
        
    if(start!=12){
        //     cout<<endl<<"start: "<<start<<endl;
        // cout<<endl<<"lancio: "<<lancio<<endl;
        app=creaSub(start,sub); //creo sottoarray per il secondo lancio
        // cout<<endl<<"sub: "<<endl;
        // for(auto it: sub){
        //     cout<<it<<endl;
        // }
        // cout<<endl<<"app: "<<endl;
        // for(auto it: app){
        //     cout<<it<<endl;
        // }

        // cout<<"sub[0]: "<<sub[0];
        // cout<<endl<<"sub[start2]: "<<sub[start-2];
        // cout<<endl<<"app[0]: "<<app[0];
        // cout<<endl<<"lancio: "<<lancio<<endl;
        // cout<<endl<<"start: "<<start<<endl;
    
        if(lancio>1&&(start-2!=2&&start!=2)) { //sono al secondo tiro e mi salvo il valore se mi fermo
            //cout<<"if1"; 
            values.push_back(sub[0]+app[0]); //salvo il valore del primo tiro (posso anche fermarmi se la pos non è 2)
            values.push_back(sub[0]+app[1]);
        }else if(start-2!=2&&start!=2) { //sono al primo tiro e posso fermarmi
            //cout<<"if2";  
            values.push_back(sub[0]);
            values.push_back(sub[0]+sub[1]);
            
        }

            
        if(lancio==2)  { //terzo tiro
            //cout<<"if3"; 
            values.push_back(sub[1]);
            values.push_back(sub[0]+app[0]+*max_element(app.begin()+1,app.end()));
        }
        // cout<<endl<<"values: "<<endl;
        // for(auto it: values){
        //     cout<<it<<endl;
        // } 


        if(lancio==2)   lancio--;
        control(start+2,sub);
    }else{
        //cout<<"ultimo";
        
        values.push_back(sub[0]+sub[11]);
        app=creaSub(start+2-N,sub);
        // cout<<endl<<"sub[0]: "<<sub[0];
        // cout<<endl<<"app[0]: "<<app[0];
        // cout<<endl<<"app: "<<endl;
        // for(auto it: app){
        //     cout<<it<<endl;
        // }
        
        values.push_back(sub[0]+app[0]);
        values.push_back(sub[0]+app[0]+*max_element(app.begin()+1,app.end()));

    } 
    
}


//SISTEMA CASO CON K>1 (subarray per salvare ogni volta l'ultima posizione a cui sono arrivata)
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
    vector<int> inizio=creaSub(0,T);
   
    
    int i=2;


    while(i<=12){
        sub=creaSub(i,inizio);
        control(i,sub);
        memory.push_back(*max_element(values.begin(),values.end()));
        values.clear();
        i+=2;
    }
   
    cout << *max_element(memory.begin(),memory.end()) << endl;  // print the result
    return 0;
}
