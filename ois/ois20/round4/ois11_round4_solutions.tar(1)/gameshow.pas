{ just simulates the process }

{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, M, K, i : longint;
    P, C       : array[0..MAXN-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, M);
    for i:=0 to N-1 do
        read(P[i]);
    readln();
    for i:=0 to N-1 do
        read(C[i]);
    readln();

    K := 0;
    for i:=0 to N-1 do
        if P[i] > M then M := M + C[i]
        else begin
            M := M - P[i];
            K := K + 1;
        end;

    writeln(K, ' ', M); { print result }
end.
