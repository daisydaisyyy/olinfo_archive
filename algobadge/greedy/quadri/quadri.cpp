int quadri(int N, long long M, int V[]) {
    // Scrivete qui la vostra soluzione
    //N=num quadri M=max valore
    int j=0,B=N,i=0,k; //B=best case (N)
    long long int sum=0;
    bool check=false; //per entrare nel ciclo


    while(B!=0&&!check){
        check=true;
        for(i=0;i+(B-1)<N&&check;i++){ //provo con lo stesso numero di B sui sottoarray
            sum=0;
            for(k=i;k<=i+(B-1)&&sum<M;k++){ //scorro i singoli subarray
                sum+=V[k];
            }
            if(sum>M){
                check=false;
                B--;
            } 
        }
        
    }

    return B;

    
}