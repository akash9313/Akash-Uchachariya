// =============================================================================
// Module      : rca_4bit
// Description : 4-bit Sequential Ripple Carry Adder
//               Inputs are registered on the rising edge of clkRCA.
//               Sum and Cout are also registered at the output stage.
//               This sequential architecture allows Vivado to report
//               accurate clock-to-output and propagation delays, making
//               it directly comparable against a tree-based CSA design.
//
// Pipeline:    Cycle 0 (posedge clkRCA) -> latch A, B, Cin
//              Combinational ripple carry propagation (FA0 -> FA1 -> FA2 -> FA3)
//              Cycle 1 (posedge clkRCA) -> register Sum[3:0] and Cout
//
// Author      : Akash Uchachariya
// Target      : AMD Vivado (Synthesis / Simulation)
// =============================================================================

`timescale 1ns / 1ps

(* dont_touch = "yes" *)
module rca_4bit (
    input  wire        clkRCA,   // Clock – positive-edge triggered
    input  wire        rst,      // Synchronous active-high reset
    input  wire [3:0]  A,        // 4-bit operand A
    input  wire [3:0]  B,        // 4-bit operand B
    input  wire        Cin,      // Carry-in
    output reg  [3:0]  Sum,      // Registered 4-bit sum
    output reg         Cout      // Registered carry-out
);

    // -------------------------------------------------------------------------
    // Stage 1 – Input registers (capture A, B, Cin on clock edge)
    // -------------------------------------------------------------------------
    (* keep = "true" *) reg [3:0] A_reg;
    (* keep = "true" *) reg [3:0] B_reg;
    (* keep = "true" *) reg       Cin_reg;

    always @(posedge clkRCA) begin
        if (rst) begin
            A_reg   <= 4'b0000;
            B_reg   <= 4'b0000;
            Cin_reg <= 1'b0;
        end else begin
            A_reg   <= A;
            B_reg   <= B;
            Cin_reg <= Cin;
        end
    end

    // -------------------------------------------------------------------------
    // Combinational ripple-carry chain (structural instantiation)
    // Carry ripples bit-by-bit: FA0 -> FA1 -> FA2 -> FA3
    // -------------------------------------------------------------------------
    (* keep = "true" *) wire [3:0] sum_wire;   // intermediate sums
    (* keep = "true" *) wire [3:1] carry;      // internal carry wires (c1, c2, c3)
    (* keep = "true" *) wire       cout_wire;  // final carry-out (before output register)

    full_adder FA0 (
        .a   (A_reg[0]),
        .b   (B_reg[0]),
        .cin (Cin_reg),
        .sum (sum_wire[0]),
        .cout(carry[1])
    );

    full_adder FA1 (
        .a   (A_reg[1]),
        .b   (B_reg[1]),
        .cin (carry[1]),
        .sum (sum_wire[1]),
        .cout(carry[2])
    );

    full_adder FA2 (
        .a   (A_reg[2]),
        .b   (B_reg[2]),
        .cin (carry[2]),
        .sum (sum_wire[2]),
        .cout(carry[3])
    );

    full_adder FA3 (
        .a   (A_reg[3]),
        .b   (B_reg[3]),
        .cin (carry[3]),
        .sum (sum_wire[3]),
        .cout(cout_wire)
    );

    // -------------------------------------------------------------------------
    // Stage 2 – Output registers (capture computed sum on clock edge)
    // -------------------------------------------------------------------------
    always @(posedge clkRCA) begin
        if (rst) begin
            Sum  <= 4'b0000;
            Cout <= 1'b0;
        end else begin
            Sum  <= sum_wire;
            Cout <= cout_wire;
        end
    end

endmodule
