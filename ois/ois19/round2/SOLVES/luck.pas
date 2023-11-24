{ constraints }
const
    MAXN = 200;
    MAXC = 10000;
    INF  = 4*MAXC;

{ input data }
var
    N,C,i,j,k: longint;
    M10, D10 : array[1..4] of longint;                      { powers of 10 to extract digits by mod or div }
    L        : array[1..MAXN] of longint;                   { lucky numbers }
    pfx      : array[1..MAXN] of array[1..MAXN] of longint; { how overlapping numbers are }
    good     : array[1..MAXC] of array[1..MAXN] of longint; { good[k,i] = how short can k numbers starting from L[i] be }
    mtch     : array[1..MAXC] of array[1..MAXN] of longint; { mtch[k,i] = next number to obtain good[k,i] }
    best     : array[1..MAXC] of longint;                   { best[k]   = best start for k numbers }

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, C);
    for i:=1 to N do begin
        read(L[i]);
        good[1,i] := 4;  { L[i] has 4 digits }
        mtch[1,i] := -1; { nothing after L[i] }
    end;
    readln();
    best[1] := 1; { all equivalent for k=1 }
    M10[1] := 10;
    M10[2] := 100;
    M10[3] := 1000;
    M10[4] := 10000;
    D10[1] := 1000;
    D10[2] := 100;
    D10[3] := 10;
    D10[4] := 1;
    for i:=1 to N do for j:=1 to N do begin
        pfx[i,j] := 4; { no overlap }
        for k:=1 to 3 do if L[i] mod M10[k] = L[j] div D10[k] then
            pfx[i,j] := 4-k; { overlap found }
    end;
    for k:=2 to C-3 do begin
        best[k] := 1;
        for i:=1 to N do begin
            good[k,i] := INF;
            for j:=1 to N do if pfx[i,j] + good[k-1,j] < good[k,i] then begin
                good[k,i] := pfx[i,j] + good[k-1,j];
                mtch[k,i] := j; { use j after i }
            end;
            if good[k,i] < good[k,best[k]] then
                best[k] := i; { use i for k numbers }
        end;
        if good[k,best[k]] >= C then break; { no way to be within C digits for larger k }
    end;
    if good[k,best[k]] > C then k := k-1;
    i := best[k]; { starting number }
    for j:=1 to C-good[k,best[k]] do write(0); { padding digits to reach length C }
    for k:=k downto 2 do begin
        { write first digits of L[i] }
        for j:=1 to pfx[i,mtch[k,i]] do
            write((L[i] div D10[j]) mod 10);
        i := mtch[k,i] { next number }
    end;
    writeln(L[i]);
end.
