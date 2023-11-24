{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, K, i, pos, sol : longint;
    V        : array[0..MAXN] of longint;
    vis      : array[0..MAXN] of boolean;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, K);
    for i:=1 to N do
    begin
        read(V[i]);
        vis[i] := false;
    end;
    readln();

    pos := 1;
    sol := 0;
    while (pos <> K) and (vis[pos] = false) do
    begin
        vis[pos] := true;
        pos := V[pos];
        sol := sol + 1;
    end;

    if pos = K
    then
        writeln(sol)
    else
        writeln(-1)
    end.
end.
