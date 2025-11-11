module and_using_nand(input a, input b, output y);
  wire w1;
  assign w1 = ~(a & b);
  assign y = ~(w1 & w1);  
endmodule

module test_and_using_nand;
  reg a, b;
  wire y;

  and_using_nand uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("and_nand.vcd");
    $dumpvars(0, test_and_using_nand);
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