int x;
int y;
int count;
int array[10];

int main ( void ) begin
    boolean z;
    z = true;
    y = 5;
    x = 10;
    if (x < y) then 
        write "if stuff";
    else 
        write "Else stuff";

    while (count < 10) do
    begin
        write "looping with array";
        array[count] = 1;
        count = count + 1;
    end
    write "end of loop";

    array[5*2/2] = 10;
    array[2] = 2;
    write "Array checking";
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 0;
    write array[array[array[array[0]]]];
    write array[array[array[array[1]]]];
    write array[array[array[array[2]]]];
    write array[array[array[array[3]]]];
    
end 
