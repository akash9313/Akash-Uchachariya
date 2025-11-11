module xor_using_nand(input a, input b, output y);
  wire n1, n2, n3, n4;

  assign n1 = ~(a & b);      
  assign n2 = ~(a & n1);     
  assign n3 = ~(b & n1);     
  assign y  = ~(n2 & n3);    
endmodule

module test_xor_using_nand;
  reg a, b;
  wire y;

  xor_using_nand uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("xor_nand.vcd");
    $dumpvars(0, test_xor_using_nand);
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