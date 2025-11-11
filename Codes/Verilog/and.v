module and_gate (input a, input b, output y);
  assign y = a & b;
endmodule

module test_and;
  reg a, b;
  wire y;

   and_gate uut (.a(a), .b(b), .y(y));

   initial begin
    $dumpfile("and.vcd");      
    $dumpvars(0, test_and);    
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