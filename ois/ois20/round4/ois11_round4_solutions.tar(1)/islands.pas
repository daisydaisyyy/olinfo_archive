{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 1000;
    dr : array[0..3] of longint = (-1, 1, 0, 0);
    dc : array[0..3] of longint = (0, 0, 1, -1);

{ input data }
var
    R, C, i, j  : longint;
    count: longint;
    M           : array[0..MAXN-1, 0..MAXN-1] of longint;

procedure dfs (rr, cc : longint);
var
    k : longint;
begin
    if (rr < 0) or (rr >= R) or (cc < 0) or (cc >= C) or (M[rr, cc] = 0) then
        exit;
    M[rr, cc] := 0;
    for k:=0 to 3 do
    begin
        dfs(rr+dr[k], cc+dc[k]);
    end;
end;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(R, C);
    for i:=0 to R-1 do
    begin
        for j:=0 to C-1 do
            read(M[i,j]);
        readln();
    end;

    for i:=0 to R-1 do
    begin
        dfs(i, 0);
        dfs(i, C-1);
    end;

    for j:=0 to C-1 do
    begin
        dfs(0, j);
        dfs(R-1, j);
    end;

    count := 0;
    for i:=0 to R-1 do
    begin
        for j:=0 to C-1 do
        begin
            if (M[i,j] = 1) then
            begin
                dfs(i, j);
                count := count + 1;
            end;
        end;
    end;

    { insert your code here }

    writeln(count); { print result }
end.
