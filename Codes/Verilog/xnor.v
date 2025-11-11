// Design Module: XNOR Gate
module xnor_gate (input a, input b, output y);
  assign y = ~(a ^ b);
endmodule

// Testbench Module
module test_xnor;
  reg a, b;
  wire y;

  // Instantiate the design under test (DUT)
  xnor_gate uut (.a(a), .b(b), .y(y));

  // Waveform dump setup
  initial begin
    $dumpfile("xnor.vcd");
    $dumpvars(0, test_xnor);
  end

  // Stimulus + Display
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