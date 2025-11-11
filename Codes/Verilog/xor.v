// Design Module: XOR Gate
module xor_gate (input a, input b, output y);
  assign y = a ^ b;
endmodule

// Testbench Module
module test_xor;
  reg a, b;
  wire y;

  // Instantiate the design under test (DUT)
  xor_gate uut (.a(a), .b(b), .y(y));

  // Waveform dump setup
  initial begin
    $dumpfile("xor.vcd");
    $dumpvars(0, test_xor);
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