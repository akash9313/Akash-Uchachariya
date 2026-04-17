// =============================================================================
// Module      : tb_rca_4bit
// Description : Testbench for the 4-bit Sequential Ripple Carry Adder.
//               Tests all 512 possible input combinations
//               (A[3:0], B[3:0], Cin) over two clock cycles per case:
//                 - Cycle 1  : inputs are captured by the input registers
//                 - Cycle 2  : outputs appear at Sum and Cout registers
//               Automatically checks results and prints PASS / FAIL.
//
// Clock       : clkRCA (period = 20 ns, i.e. 50 MHz)
// Author      : Akash Uchachariya
// Target      : AMD Vivado Simulation (xsim)
// =============================================================================

`timescale 1ns / 1ps

module tb_rca_4bit;

    // -------------------------------------------------------------------------
    // DUT signal declarations
    // -------------------------------------------------------------------------
    reg        clkRCA;
    reg        rst;
    reg  [3:0] A;
    reg  [3:0] B;
    reg        Cin;
    wire [3:0] Sum;
    wire       Cout;

    // -------------------------------------------------------------------------
    // Instantiate DUT
    // -------------------------------------------------------------------------
    rca_4bit uut (
        .clkRCA (clkRCA),
        .rst    (rst),
        .A      (A),
        .B      (B),
        .Cin    (Cin),
        .Sum    (Sum),
        .Cout   (Cout)
    );

    // -------------------------------------------------------------------------
    // Clock generation  – 20 ns period (50 MHz)
    // -------------------------------------------------------------------------
    initial clkRCA = 0;
    always #10 clkRCA = ~clkRCA;

    // -------------------------------------------------------------------------
    // Test variables
    // -------------------------------------------------------------------------
    integer i;
    integer pass_count;
    integer fail_count;
    reg [4:0] expected;  // 5-bit: {Cout_exp, Sum_exp[3:0]}

    // -------------------------------------------------------------------------
    // Stimulus
    // -------------------------------------------------------------------------
    initial begin
        // -- Waveform dump for Vivado simulator (xsim) ----------------
        $dumpfile("tb_rca_4bit.vcd");
        $dumpvars(0, tb_rca_4bit);

        pass_count = 0;
        fail_count = 0;

        // -- Synchronous reset ----------------------------------------
        rst = 1;
        A   = 4'b0;
        B   = 4'b0;
        Cin = 1'b0;
        @(posedge clkRCA); #1;   // apply reset for one clock cycle
        rst = 0;
        @(posedge clkRCA); #1;   // wait one more cycle after de-assert

        // -- Exhaustive test: all 512 combinations --------------------
        $display("=======================================================");
        $display(" 4-bit Sequential Ripple Carry Adder – Exhaustive Test");
        $display(" Clock: clkRCA (20 ns period)");
        $display("=======================================================");

        for (i = 0; i < 512; i = i + 1) begin
            // Apply new inputs
            A   = i[8:5];   // bits [8:5] -> A[3:0]
            B   = i[4:1];   // bits [4:1] -> B[3:0]
            Cin = i[0];     // bit  [0]   -> Cin

            // Wait one clock: inputs registered by input flip-flops
            @(posedge clkRCA); #1;

            // Wait second clock: output flip-flops capture the sum
            @(posedge clkRCA); #1;

            // Compute golden reference
            expected = {1'b0, A} + {1'b0, B} + {4'b0, Cin};
            // Note: A, B, Cin are now the *previously latched* values;
            // that is fine because we wait two full cycles.

            if ({Cout, Sum} === expected[4:0]) begin
                pass_count = pass_count + 1;
                // Uncomment below line for verbose output:
                // $display("PASS A=%b B=%b Cin=%b -> Sum=%b Cout=%b", A, B, Cin, Sum, Cout);
            end else begin
                fail_count = fail_count + 1;
                $display("FAIL A=%04b B=%04b Cin=%b | Got: Sum=%04b Cout=%b | Exp: Sum=%04b Cout=%b",
                         A, B, Cin, Sum, Cout, expected[3:0], expected[4]);
            end
        end

        // -- Corner / boundary cases (explicit display) ---------------
        $display("-------------------------------------------------------");
        $display(" Boundary check (apply, then wait 2 clocks)");
        $display("-------------------------------------------------------");

        // 0 + 0 + 0 = 0
        apply_and_check(4'b0000, 4'b0000, 1'b0, 5'b00000, "0+0+Cin=0");
        // Max + Max + Cin=1  (15+15+1 = 31 -> Sum=1111, Cout=1)
        apply_and_check(4'b1111, 4'b1111, 1'b1, 5'b11111, "15+15+1=31");
        // 8+8 = 16 -> Sum=0000, Cout=1
        apply_and_check(4'b1000, 4'b1000, 1'b0, 5'b10000, "8+8=16");
        // 7+8+1 = 16 -> Sum=0000, Cout=1
        apply_and_check(4'b0111, 4'b1000, 1'b1, 5'b10000, "7+8+1=16");
        // 5+3+0 = 8 -> Sum=1000, Cout=0
        apply_and_check(4'b0101, 4'b0011, 1'b0, 5'b01000, "5+3=8");

        // -- Summary --------------------------------------------------
        $display("=======================================================");
        $display(" RESULTS: %0d PASS  |  %0d FAIL  (out of 517 tests)",
                 pass_count, fail_count);
        $display("=======================================================");

        $finish;
    end

    // -------------------------------------------------------------------------
    // Task: apply inputs, wait 2 cycles, check and print result
    // -------------------------------------------------------------------------
    task apply_and_check;
        input [3:0] ta;
        input [3:0] tb;
        input       tcin;
        input [4:0] texp;     // {Cout_exp, Sum_exp}
        input [63:0] label;   // 8-char string
        reg   [4:0] got;
    begin
        A   = ta;
        B   = tb;
        Cin = tcin;
        @(posedge clkRCA); #1;
        @(posedge clkRCA); #1;
        got = {Cout, Sum};
        if (got === texp) begin
            pass_count = pass_count + 1;
            $display("  PASS [%s] A=%04b B=%04b Cin=%b -> Sum=%04b Cout=%b",
                     label, ta, tb, tcin, Sum, Cout);
        end else begin
            fail_count = fail_count + 1;
            $display("  FAIL [%s] A=%04b B=%04b Cin=%b | Got Sum=%04b Cout=%b | Exp Sum=%04b Cout=%b",
                     label, ta, tb, tcin, Sum, Cout, texp[3:0], texp[4]);
        end
    end
    endtask

endmodule
