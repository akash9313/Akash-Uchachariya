module pipe_ex (F, A, B, C, D, clk);
parameter N = 10;
input [N-1:0] A, B, C, D;
input clk;
output [N-1:0] F;
reg [N-1:0] L12_x1, L12_x2, L12_D, L23_x3, L23_D, L34_F;
assign F = L34_F;
always @(posedge clk)
    begin
        L12_x1 <= #4 A + B;
        L12_x2 <= #4 C - D;  
        L12_D  <=  D;
        L23_x3 <= #4 L12_x1 + L12_x2;
        L23_D  <= L12_D;
        L34_F  <= #6 L23_x3 * L23_D;
    end
endmodule


module tb_pipe_ex;

parameter N = 10;

reg  [N-1:0] A, B, C, D;
reg          clk;
wire [N-1:0] F;

pipe_ex #(N) dut (
    .F(F),
    .A(A),
    .B(B),
    .C(C),
    .D(D),
    .clk(clk)
);

always #5 clk = ~clk;

initial begin
    $dumpfile("pipeline.vcd");   
    $dumpvars(0, tb_pipe_ex);   
end

initial begin
    clk = 0;
    A = 0; B = 0; C = 0; D = 0;

    #10 A = 10; B = 5;  C = 3;  D = 2;
    #10 A = 20; B = 4;  C = 1;  D = 3;
    #10 A = 7;  B = 6;  C = 2;  D = 4;
    #10 A = 15; B = 8;  C = 5;  D = 2;

    #100 $finish;
end

initial begin
    $monitor("Time=%0t | A=%d B=%d C=%d D=%d | F=%d",
              $time, A, B, C, D, F);
end

endmodule