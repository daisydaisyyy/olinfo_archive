{ Keep track of the number of friends (deg) that already took the dessert. }
{ Once this number reaches the limit L for a member, }
{ it is added to a stack of people waiting to order the dessert. }


{ constraints }
const
    MAXN = 1000000;

{ input data }
var
    N, R, i, j, k, S     : longint;
    M, L, MM, deg, stack : array[0..MAXN-1] of longint;
    F, adj               : array[0..MAXN-1] of array of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    for i:=0 to N-1 do begin
        readln(M[i], L[i]);
        setlength(F[i], M[i]);
        for j:=0 to M[i]-1 do
            read(F[i][j]);
        readln();
    end;

    S := 0;
    R := 0;
    for i:=0 to N-1 do begin
        deg[i] := 0;
        MM[i] := 0;
    end;

    for i:=0 to N-1 do
        for j:=0 to M[i]-1 do
            MM[F[i][j]] := MM[F[i][j]] + 1;
    for i:=0 to N-1 do
        setlength(adj[i], MM[i]);
    for i:=0 to N-1 do begin
        for j:=0 to M[i]-1 do begin
            k := F[i][j];
            MM[k] := MM[k]-1;
            adj[k][MM[k]] := i;
        end;
    end;
    for i:=0 to N-1 do
        for j:=0 to M[i]-1 do
            MM[F[i][j]] := MM[F[i][j]] + 1;

    for i:=0 to N-1 do
        if L[i] = 0 then begin
            stack[S] := i;
            S := S+1;
        end;

    while S > 0 do begin
        R := R+1;
        S := S-1;
        i := stack[S];
        for j:=0 to MM[i]-1 do
            k := adj[i][j];
            deg[k] := deg[k]+1;
            if deg[k] = L[k] then begin
                stack[S] := k;
                S := S+1;
            end;
    end;


    writeln(R); { print result }
end.
