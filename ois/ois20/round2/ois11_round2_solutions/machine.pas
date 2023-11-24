{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXD = 1000;
    MAXY = 1000000;

{ input data }
var
    C, D, Y, i  : longint;
    // Warning! M and P are 1-based
    M, P        : array[1..MAXD] of longint;
    cumulative  : array[1..MAXD] of longint;
    DP : array[0..MAXY] of longint;
    j, k, u : longint;
    useful : array[0..MAXD] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(C, D, Y);
    // Warning! M and P are 1-based
    for i:=1 to D do
        read(M[i]);
    readln();
    for i:=1 to D do
        read(P[i]);
    readln();

    cumulative[1] := M[1];
    for i:=2 to D do
        cumulative[i] := cumulative[i-1] + M[i];

    for i:=1 to D do
    begin
        cumulative[i] := cumulative[i] + C;
        cumulative[i] := cumulative[i] - P[i];
    end;

    DP[0] := 0;
    for i:= 1 to Y do
        DP[i] := 2000000000;

    u := 0;
    for i:= 0 to D do
    begin
        for j:=1 to D do
        begin
            if (i+j <= Y) then
            begin
                if (DP[i+j] >= DP[i] + cumulative[j]) then
                    DP[i+j] := DP[i] + cumulative[j];
            end;
        end;
        if ((i <= Y) and (DP[i] = cumulative[i])) then
        begin
            useful[u] := i;
            u := u+1;
        end;
    end;

    for i:= D to Y do
    begin
        for k:=0 to u-1 do
        begin
            j := useful[k];
            if (i+j <= Y) then
            begin
                if (DP[i+j] >= DP[i] + cumulative[j]) then
                    DP[i+j] := DP[i] + cumulative[j];
            end;
        end;
    end;

    writeln(DP[Y]); { print result }
end.
