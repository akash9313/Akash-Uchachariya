`timescale 1ns/1ps

module tb_rca_top;

    parameter N = 8;

    // DUT signals
    reg          clk;
    reg  [N-1:0] A, B;
    reg          Cin;
    wire [N-1:0] Sum;
    wire         Cout;

    // Instantiate the sequential (clocked) RCA top
    rca_top uut (
        .clk (clk),
        .A   (A),
        .B   (B),
        .Cin (Cin),
        .Sum (Sum),
        .Cout(Cout)
    );

    // Clock generation: 10 ns period (50 MHz)
    initial clk = 0;
    always #5 clk = ~clk;

    // Task: apply inputs, wait one full clock cycle, then display result
    task apply_and_check;
        input [N-1:0] a_in, b_in;
        input         cin_in;
        begin
            A   = a_in;
            B   = b_in;
            Cin = cin_in;
            @(posedge clk);   // inputs are registered on this edge
            #1;               // small delay so outputs settle after clock edge
            $display("A=%0d  B=%0d  Cin=%b  |  Sum=%0d  Cout=%b  (Expected: %0d)",
                     A, B, Cin, Sum, Cout, A + B + Cin);
        end
    endtask

    initial begin
        $dumpfile("rca_top.vcd");
        $dumpvars(0, tb_rca_top);

        $display("=== Sequential RCA Top Testbench ===");
        $display("A\t\tB\t\tCin\t|\tSum\t\tCout");
        $display("--------------------------------------------------------------");

        // Apply test vectors; outputs appear ONE clock after inputs are applied
        apply_and_check(8'd5,   8'd3,   1'b0);   // 5  + 3   = 8
        apply_and_check(8'd15,  8'd1,   1'b0);   // 15 + 1   = 16
        apply_and_check(8'd255, 8'd1,   1'b0);   // 255 + 1  = 0 (overflow, Cout=1)
        apply_and_check(8'd100, 8'd50,  1'b1);   // 100 + 50 + 1 = 151
        apply_and_check(8'd128, 8'd127, 1'b1);   // 128 + 127 + 1 = 0 (overflow, Cout=1)
        apply_and_check(8'd0,   8'd0,   1'b0);   // 0  + 0   = 0

        $display("=== Simulation Complete ===");
        $finish;
    end

endmodule
