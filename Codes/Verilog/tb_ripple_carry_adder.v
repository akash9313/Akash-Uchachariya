`timescale 1ns/1ps

module tb_ripple_carry_adder;

    parameter N = 8;

    reg  [N-1:0] A, B;
    reg  Cin;
    wire [N-1:0] Sum;
    wire Cout;

    ripple_carry_adder #(N) uut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .Sum(Sum),
        .Cout(Cout)
    );

    initial begin
        $display("A\tB\tCin\tSum\tCout");

        A = 8'd5;   B = 8'd3;   Cin = 0; #10;
        $display("%d\t%d\t%b\t%d\t%b", A, B, Cin, Sum, Cout);

        A = 8'd15;  B = 8'd1;   Cin = 0; #10;
        $display("%d\t%d\t%b\t%d\t%b", A, B, Cin, Sum, Cout);

        A = 8'd255; B = 8'd1;   Cin = 0; #10;
        $display("%d\t%d\t%b\t%d\t%b", A, B, Cin, Sum, Cout);

        A = 8'd100; B = 8'd50;  Cin = 1; #10;
        $display("%d\t%d\t%b\t%d\t%b", A, B, Cin, Sum, Cout);

        $finish;
    end

endmodule