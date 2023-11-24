{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ input data }
var
    H0, M0, H1, M1 : longint;
    count : longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(H0, M0);
    readln(H1, M1);

    { insert your code here }
    count := (H1*60 + M1) - (H0*60 + M0);
    if (count < 0) then
        count := 24*60 + count;

    writeln(count div 60, ' ', count mod 60); { print result }
end.
