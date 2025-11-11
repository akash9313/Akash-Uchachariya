module or_using_nand(input a, input b, output y);
  wire na, nb;
  assign na = ~(a & a); 
  assign nb = ~(b & b);  
  assign y = ~(na & nb); 
endmodule

module test_or_using_nand;
  reg a, b;
  wire y;

  or_using_nand uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("or_nand.vcd");
    $dumpvars(0, test_or_using_nand);
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