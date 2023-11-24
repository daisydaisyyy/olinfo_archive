{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, i, temp : longint;
    A     : array[0..MAXN-1] of longint;
    T     : array[1..MAXN] of longint;
    ft    : array[1..MAXN] of longint;
    best    : array[1..MAXN] of longint;

procedure update(i: longint; v: longint);
begin
    i := N-i+1;
    while (i <= N) do
    begin
        if v > ft[i] then
            ft[i] := v;
        i := i + (i and (-i));
    end;
end;

function get(i:longint) : longint;
var res: longint;
begin
    res := 0;
    i := N-i+1;
    while (i > 0) do
    begin
        if res < ft[i] then
            res := ft[i];
        i := i - (i and (-i));
    end;
    get := res;
end;


begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    for i:=0 to N-1 do
        read(A[i]);
    readln();
    for i:=1 to N do
        read(T[i]);
    readln();

    {
        WARNING! T is indexed from 1!
        In particular T[i] is the preferred number of i.
    }

    for i:=1 to N do
    begin
        best[i] := 0;
        ft[i] := 0;
    end;

    i := N-1;
    while i >= 0 do
    begin
        if best[T[A[i]]]+1 > best[A[i]] then
            best[A[i]] := best[T[A[i]]]+1;
        temp := get(A[i]+1)+1;
        if temp > best[A[i]] then
            best[A[i]] := temp;
        update(A[i], best[A[i]]);
        i := i-1;
    end;



    { insert your code here }

    writeln(get(1)); { print result }
end.
