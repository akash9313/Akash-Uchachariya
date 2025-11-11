module half_adder(input a, input b, output sum, output carry);
  assign sum = a ^ b;       
  assign carry = a & b;     
endmodule

module test_half_adder;
  reg a, b;
  wire sum, carry;

  half_adder uut (.a(a), .b(b), .sum(sum), .carry(carry));

  initial begin
    $dumpfile("half_adder.vcd");
    $dumpvars(0, test_half_adder);
  end

  initial begin
    $display("A B | Sum Carry");
    $display("----------------");
    a = 0; b = 0; #10; $display("%b %b |  %b    %b", a, b, sum, carry);
    a = 0; b = 1; #10; $display("%b %b |  %b    %b", a, b, sum, carry);
    a = 1; b = 0; #10; $display("%b %b |  %b    %b", a, b, sum, carry);
    a = 1; b = 1; #10; $display("%b %b |  %b    %b", a, b, sum, carry);
    $finish;
  end
endmodule