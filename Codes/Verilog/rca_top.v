module rca_top(
    input clk,
    input [7:0] A,
    input [7:0] B,
    input Cin,
    output reg [7:0] Sum,
    output reg Cout
);

wire [7:0] Sum_temp;
wire Cout_temp;

ripple_carry_adder #(8) uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .Sum(Sum_temp),
    .Cout(Cout_temp)
);

always @(posedge clk) begin
    Sum <= Sum_temp;
    Cout <= Cout_temp;
end

endmodule