module not_gate (input a, output y);
  assign y = ~a;
endmodule

module test_not;
  reg a;
  wire y;

   not_gate uut (.a(a), .y(y));

  initial begin
    $dumpfile("not.vcd");
    $dumpvars(0, test_not);
  end

   initial begin
    $display("A | Y");
    $display("--------");

    a=0; #10; $display("%b | %b", a, y);
    a=1; #10; $display("%b | %b", a, y);

    $finish;
  end
endmodule