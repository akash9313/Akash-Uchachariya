module mux (
    input [0:7]i,
    input [0:2]s,
    output y
);

    wire w1,w2,w3,w4,w5,w6,w7,w8;
    assign w1 = i[0]&(~s[0])&(~s[1])&(~s[2]);
    assign w2 = i[1]&(~s[0])&(~s[1])&(s[2]);
    assign w3 = i[2]&(~s[0])&(s[1])&(~s[2]);
    assign w4 = i[3]&(~s[0])&(s[1])&(s[2]);
    assign w5 = i[4]&(s[0])&(~s[1])&(~s[2]);
    assign w6 = i[5]&(s[0])&(~s[1])&(s[2]);
    assign w7 = i[6]&(s[0])&(s[1])&(~s[2]);
    assign w8 = i[7]&(s[0])&(s[1])&(s[2]);
    assign y = w1|w2|w3|w4|w5|w6|w7|w8;
endmodule


`timescale 1ns / 1ps

module tb_mux;

    reg [0:7] i;
    reg [0:2] s;
    wire y;

    mux uut (
        i,s,y
    );

    initial begin
        $dumpfile("mux.vcd");      
        $dumpvars(0, tb_mux);      

        $display("Input\tSel\tY");   
        $monitor("%b\t%b\t%b", i, s, y);

        i = 8'b10000000; s = 3'b000; #10;
        i = 8'b00000000; s = 3'b001; #10;
        i = 8'b00100000; s = 3'b010; #10;
        i = 8'b00010000; s = 3'b011; #10;
        i = 8'b00000000; s = 3'b100; #10;
        i = 8'b00000100; s = 3'b101; #10;
        i = 8'b00000000; s = 3'b110; #10;
        i = 8'b00000001; s = 3'b111; #10;

        $finish;
    end

endmodule