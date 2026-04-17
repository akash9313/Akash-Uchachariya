`timescale 1ns/1ps

module ripple_carry_adder #(parameter N = 8)(
    input  [N-1:0] A,
    input  [N-1:0] B,
    input          Cin,
    output [N-1:0] Sum,
    output         Cout
);

    wire [N:0] carry;
    assign carry[0] = Cin;

    genvar i;
    generate
        for(i = 0; i < N; i = i + 1) begin : RCA
            assign {carry[i+1], Sum[i]} = A[i] + B[i] + carry[i];
        end
    endgenerate

    assign Cout = carry[N];

endmodule