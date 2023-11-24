{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, i  : Int64;
    S, P  : array[0..MAXN-1] of Int64;
    best  : Int64;
    sumS, sumP: Int64;
begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    sumP := 0;
    sumS := 0;
    for i:=0 to N-1 do
    begin
        read(S[i]);
        read(P[i]);
        readln();

        sumP := sumP + P[i];
        sumS := sumS + S[i];
    end;

    best := 0;
    for i:=0 to N-1 do
    begin
        if ((sumS - S[i]) * (sumP - P[best]) > (sumS - S[best]) * (sumP - P[i])) then
            best := i
    end;

    writeln(best); { print result }
end.
