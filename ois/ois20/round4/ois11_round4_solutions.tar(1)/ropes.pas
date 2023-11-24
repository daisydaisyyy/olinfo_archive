{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, i, sol  : longint;
    P, T, mostc  : array[0..MAXN] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    for i:=0 to N-1 do
        read(P[i]);
    readln();
    for i:=0 to N-1 do
        read(T[i]);
    readln();

    for i:=0 to N-1 do
        mostc[i] := 0;

    sol := 0;
    for i:=0 to N-1 do
    begin
        if T[i] >= mostc[P[i]] then
        begin
            sol := sol + mostc[P[i]];
            mostc[P[i]] := T[i];
        end
        else
            sol := sol + T[i];
    end;

    writeln(sol);
end.
