{ maintains a queue of the houses that will be destroyed by the next plane, }
{ using the fact that they must be adjacent to those just destroyed }

{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, P, i, q, pp, K : longint;
    H, hits       : array[0..2*MAXN-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, P);
    for i:=0 to N-1 do
        read(H[i]);
    readln();

    K := 0;
    for i:=0 to N-1 do
        if ((i=0) or (H[i] > H[i-1])) and ((i=N-1) or (H[i] > H[i+1])) then begin
            hits[K] := i;
            K := K+1;
        end;
    hits[K] := -1;
    K := K+1;

    q := 0;
    for pp:=1 to P-1 do begin
        if hits[q] = -1 then begin
            P := pp;
            break;
        end;
        while (q < K) and (hits[q] <> -1) do begin
            i := hits[q];
            H[i] := 0;
            if (i >= 1) and (((i = 1) and (H[i-1] <> 0)) or (H[i-1] > H[i-2])) and (hits[K-1] <> i-1) then begin
                hits[K] := i-1;
                K := K+1;
            end;
            if (i < N-1) and (((i = N-2) and (H[i+1] <> 0)) or (H[i+1] > H[i+2])) then begin
                hits[K] := i+1;
                K := K+1;
            end;
            q := q+1;
        end;
        q := q+1;
        hits[K] := -1;
        K := K+1;
    end;

    writeln(K-P); { print result }
end.
