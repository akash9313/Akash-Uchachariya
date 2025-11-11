module half_adder_using_nand(input a, input b, output sum, output cout);
    wire w1, w2, w3;
    assign w1 = ~(a & b);
    assign w2 = ~(a & w1);
    assign w3 = ~(b & w2);
    assign sum = ~(w2 & w3);
    assign cout = ~(w1 & w1);
endmodule

module test_half_adder;
    reg a, b;
    wire sum, cout;

    half_adder_using_nand uut(.a(a), .b(b), .sum(sum), .cout(cout));

    initial begin
        $dumpfile("half_adder.vcd");
        $dumpvars(0, test_half_adder);
    end

    initial begin
        $display("A  B  |  sum  cout");
        $display("--------------------");

    a = 0; b = 0; #10; $display("%b %b |  %b    %b", a, b, sum, cout);
    a = 0; b = 1; #10; $display("%b %b |  %b    %b", a, b, sum, cout);
    a = 1; b = 0; #10; $display("%b %b |  %b    %b", a, b, sum, cout);
    a = 1; b = 1; #10; $display("%b %b |  %b    %b", a, b, sum, cout);
    $finish;
    end
endmodule