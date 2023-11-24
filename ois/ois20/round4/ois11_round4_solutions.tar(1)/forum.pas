{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXD = 500000;
    MAXP = 500000;
    MAXE = 500000;

{ input data }
var
    D, P, E, i  : longint;
    A     : array[0..(MAXD+MAXP)-1] of longint;
    T, ID : array[0..MAXE-1] of longint;
    adj : array[0..MAXD+MAXP-1] of array of longint;
    adjl: array[0..MAXD+MAXP-1] of longint;
    adjr: array[0..MAXD+MAXP-1] of longint;
    left: array[0..MAXD+MAXP-1] of longint;
    right: array[0..MAXD+MAXP-1] of longint;
    st : array[1..4*(MAXD+MAXP)] of longint;
    time: longint;
    res: longint;

procedure calc_times(u : longint);
var
    jj : longint;
begin
    left[u] := time;
    time := time+1;
    for jj := 0 to adjl[u]-1 do
    begin
        calc_times(adj[u][jj]);
    end;
    right[u] := time-1;
end;

procedure propagate(nid : longint);
begin
    if (st[nid] <> 0) then
    begin
        st[nid*2] := st[nid];
        st[nid*2+1] := st[nid];
    end;
    st[nid] := 0;
end;

procedure update(active, b, e, l, r, nid : longint);
begin
    if ((e < l) or (b > r)) then
        exit;
    if ((l >= b) and (r <= e)) then
    begin
        if (active = 1) then
            st[nid] := 1
        else
            st[nid] := -1;
        exit;
    end;

    propagate(nid);
    update(active, b, e, l, (l+r) div 2, nid*2);
    update(active, b, e, ((l+r) div 2)+1, r, nid*2+1);
end;

function get(v, l, r, nid : longint) : longint;
begin
    if (l = r) then
    begin
        get := st[nid];
        exit;
    end;

    propagate(nid);
    if (v <= ((l+r) div 2)) then
        get := get(v, l, (l+r) div 2, nid*2)
    else
        get := get(v, ((l+r) div 2)+1, r, nid*2+1);
end;


begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(D, P, E);
    for i:=0 to D+P-1 do
        read(A[i]);
    readln();
    for i := 0 to E-1 do
        readln(T[i], ID[i]);

    for i := 0 to D+P-1 do
    begin
        adjl[i] := 0;
        adjr[i] := 1;
        setLength(adj[i], 1);
    end;

    for i := 1 to D+P-1 do
    begin
        if (adjl[A[i]] >= adjr[A[i]]) then
        begin
            adjr[A[i]] := adjr[A[i]] * 2;
            setLength(adj[A[i]], adjr[A[i]]);
        end;
        adj[A[i]][adjl[A[i]]] := i;
        adjl[A[i]] := adjl[A[i]]+1;
    end;

    time := 0;
    calc_times(0);


    for i := 1 to 4*(D+P) do
        st[i] := -1;

    for i := 0 to E-1 do
    begin
        if (T[i] = 2) then
        begin
            res := get(left[ID[i]], 0, D+P-1, 1);
            if (res = -1) then
                writeln(0)
            else
                writeln(1);
        end
        else
            update(T[i], left[ID[i]], right[ID[i]], 0, D+P-1, 1);
    end;
end.
