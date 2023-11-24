{ input data }
var
    R, C, K  : longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    read(R);
    read(C);
    read(K);
    readln();

    writeln(((R + K - 1) div K) * ((C + K - 1) div K));
end.
