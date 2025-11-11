module full_adder(input a, input b, input cin, output sum, output cout);
  assign sum  = a ^ b ^ cin;                            
  assign cout = (a & b) | (b & cin) | (a & cin);        
endmodule

module test_full_adder;
  reg a, b, cin;
  wire sum, cout;

  full_adder uut (.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));

  initial begin
    $dumpfile("full_adder.vcd");
    $dumpvars(0, test_full_adder);
  end

  initial begin
    $display("A B Cin | Sum Cout");
    $display("-------------------");
    a = 0; b = 0; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 0; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 1; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 1; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 0; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 0; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 1; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 1; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    $finish;
  end
endmodule