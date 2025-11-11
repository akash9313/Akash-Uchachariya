module xor_using_nor(input a, input b, output y);
  wire na, nb, t1, t2, t3;

  assign na = ~(a | a);   
  assign nb = ~(b | b);   
  assign t1 = ~(a | b);   
  assign t2 = ~(na | nb); 
  assign y  = ~(t1 | t2); 
endmodule

// Testbench
module test_xor_using_nor;
  reg a, b;
  wire y;

  xor_using_nor uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("xor_nor.vcd");
    $dumpvars(0, test_xor_using_nor);
  end

  initial begin
    $display("A B | Y");
    $display("------------");
    a=0; b=0; #10; $display("%b %b | %b", a, b, y);
    a=0; b=1; #10; $display("%b %b | %b", a, b, y);
    a=1; b=0; #10; $display("%b %b | %b", a, b, y);
    a=1; b=1; #10; $display("%b %b | %b", a, b, y);
    $finish;
  end
endmodule