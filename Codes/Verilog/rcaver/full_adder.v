// =============================================================================
// Module      : full_adder
// Description : 1-bit Full Adder (combinational primitive)
//               Used as building block for the 4-bit Ripple Carry Adder.
// Author      : Akash Uchachariya
// Target      : AMD Vivado (Synthesis / Simulation)
// =============================================================================

`timescale 1ns / 1ps

module full_adder (
    input  wire a,      // Operand bit
    input  wire b,      // Operand bit
    input  wire cin,    // Carry-in
    output wire sum,    // Sum output
    output wire cout    // Carry-out
);

    assign sum  = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);

endmodule
