module full_adder_using_nand(input a, input b, input c, output Sum, output Carry);
    wire w1, w2, w3, w4, w5, w6, w7;       

    nand nand1(w1, a, b);
    nand nand2(w2, a, w1);
    nand nand3(w3, b, w1);
    nand nand4(w4, w2, w3);
    nand nand5(w5, w4, c);
    nand nand6(w6, w5, w4);
    nand nand7(w7, w5, c);
    nand nand8(Sum, w6, w7);
    nand nand9(Carry, w1, w5);

endmodule

// --------- Testbench ---------
module test_full_adder_using_nand;
    reg a, b, c;
    wire Sum, Carry;

    full_adder_using_nand uut (.a(a), .b(b), .c(c), .Sum(Sum), .Carry(Carry));

    initial begin
        $dumpfile("full_adder_using_nand.vcd");
        $dumpvars(0, test_full_adder_using_nand);
    end


    initial begin
        $display("a b c | Sum Carry");
        $display("--------------");

        $monitor("%b %b %b | %b %b", a, b, c, Sum, Carry);
        a=0; b=0; c=0; #10;
        a=0; b=0; c=1; #10;
        a=0; b=1; c=0; #10;
        a=0; b=1; c=1; #10;
        a=1; b=0; c=0; #10;
        a=1; b=0; c=1; #10;
        a=1; b=1; c=0; #10;
        a=1; b=1; c=1; #10;

        // a=0; b=0; c=0; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=0; b=0; c=1; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=0; b=1; c=0; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=0; b=1; c=1; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=1; b=0; c=0; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=1; b=0; c=1; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=1; b=1; c=0; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);
        // a=1; b=1; c=1; #10; $display("%b %b %b | %b %b", a, b, c, Sum, Carry);

        $finish;
    end
endmodule