module and_using_nor(input a, input b, output y);
  wire w1, w2;
  assign w1 = ~(a | a);   
  assign w2 = ~(b | b);
  assign y = ~(w1 & w2);
endmodule

module test_and_using_nor;
  reg a, b;
  wire y;

  and_using_nor uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("and_nor.vcd");
    $dumpvars(0, test_and_using_nor);
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