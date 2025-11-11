module demux (
    input wire in,
    input wire [0:2] s,
    output wire [0:7] y
);

    assign y[0] = in & (~s[0]) & (~s[1]) & (~s[2]);
    assign y[1] = in & (~s[0]) & (~s[1]) & (s[2]);
    assign y[2] = in & (~s[0]) & (s[1]) & (~s[2]);
    assign y[3] = in & (~s[0]) & (s[1]) & (s[2]);
    assign y[4] = in & (s[0]) & (~s[1]) & (~s[2]);
    assign y[5] = in & (s[0]) & (~s[1]) & (s[2]);
    assign y[6] = in & (s[0]) & (s[1]) & (~s[2]);
    assign y[7] = in & (s[0]) & (s[1]) & (s[2]);

endmodule


`timescale 1ns / 1ps
module tb_demux;

    reg in;
    reg [0:2] s;
    wire [0:7] y;

    demux uut (
        .in(in),
        .s(s),
        .y(y)
    );

    initial begin
        $dumpfile("demux.vcd");
        $dumpvars(0, tb_demux);

        $display("Time\tIn\tSel\t\tOutput");
        $monitor("%0t\t%b\t%b\t%b", $time, in, s, y);

        in = 1'b1;

        s = 3'b000; #10;
        s = 3'b001; #10;
        s = 3'b010; #10;
        s = 3'b011; #10;
        s = 3'b100; #10;
        s = 3'b101; #10;
        s = 3'b110; #10;
        s = 3'b111; #10;

        in = 1'b0; // test input low, all outputs should be 0
        s = 3'b000; #10;

        $finish;
    end

endmodule