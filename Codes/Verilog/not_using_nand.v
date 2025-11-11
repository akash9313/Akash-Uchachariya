module not_using_nand(input a, output y);
  assign y = ~(a & a);  
endmodule

module test_not_using_nand;
  reg a;
  wire y;

  not_using_nand uut (.a(a), .y(y));

  initial begin
    $dumpfile("not_nand.vcd");
    $dumpvars(0, test_not_using_nand);
  end

  initial begin
    $display("A | Y");
    $display("--------");
    a=0; #10; $display("%b | %b", a, y);
    a=1; #10; $display("%b | %b", a, y);
    $finish;
  end
endmodule