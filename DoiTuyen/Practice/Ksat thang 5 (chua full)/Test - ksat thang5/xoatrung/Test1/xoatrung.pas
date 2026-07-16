Program bai2;
uses crt;
var  s, y:ansistring;
     x: char;
     n,i:longint;
     f: text;
begin
    clrscr;
    assign(f,'xoatrung.inp');
    reset(f);
    readln(f,s);
    close(f);
    n :=length(s);
    y:=s[1];
    for i:=2 to n do
        if y[length(y)] <> s[i] then y:=y+s[i];
    assign(f,'xoatrung.out');
    rewrite(f);
    writeln(f,y);
    close(f);
end.
