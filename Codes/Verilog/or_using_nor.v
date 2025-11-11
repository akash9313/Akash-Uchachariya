module or_using_nor(input a, input b, output y);
  wire temp;
  assign temp = ~(a | b); 
  assign y = ~(temp | temp); 
endmodule

module test_or_using_nor;
  reg a, b;
  wire y;

  or_using_nor uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("or_nor.vcd");
    $dumpvars(0, test_or_using_nor);
  end

  initial begin
    $display("A B | Y");
    $display("----------");
    a=0; b=0; #10; $display("%b %b | %b", a, b, y);
    a=0; b=1; #10; $display("%b %b | %b", a, b, y);
    a=1; b=0; #10; $display("%b %b | %b", a, b, y);
    a=1; b=1; #10; $display("%b %b | %b", a, b, y);
    $finish;
  end
endmodule