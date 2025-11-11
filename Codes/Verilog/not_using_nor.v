module not_using_nor(input a, output y);
  assign y = ~(a | a);  
endmodule

module test_not_using_nor;
  reg a;
  wire y;

  not_using_nor uut (.a(a), .y(y));

  initial begin
    $dumpfile("not_nor.vcd");
    $dumpvars(0, test_not_using_nor);
  end

  initial begin
    $display("A | Y");
    $display("--------");
    a=0; #10; $display("%b | %b", a, y);
    a=1; #10; $display("%b | %b", a, y);
    $finish;
  end
endmodule