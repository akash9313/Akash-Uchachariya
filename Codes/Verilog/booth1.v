module boothmultiplier (
    input        LdA, LdQ, LdM,
    input        clrA, clrQ, clrff,
    input        sftA, sftQ,
    input        addsub, ldcnt, decr,
    input        clk,
    input  [15:0] data_in,
    output       q0, qm1, eqz
);

    wire [15:0] A, Q, M, Z;
    wire [4:0]  count;

    assign eqz = ~|count;
    assign q0  = Q[0];

    shiftreg AR (
        .ld   (LdA),
        .clr  (clrA),
        .din  (Z),
        .sft  (sftA),
        .dout (A),
        .clk  (clk),
        .s_in (A[15])
    );

    shiftreg QR (
        .ld   (LdQ),
        .clr  (clrQ),
        .din  (data_in),
        .sft  (sftQ),
        .dout (Q),
        .clk  (clk),
        .s_in (A[0])
    );

    dff QM1 (
        .d   (Q[0]),
        .q   (qm1),
        .clk (clk),
        .clr (clrff)
    );

    addsum AS (
        .out    (Z),
        .in1    (A),
        .in2    (M),
        .addsub (addsub)
    );

    PIPO MR (
        .ld   (LdM),
        .din  (data_in),
        .dout (M),
        .clk  (clk)
    );

    CNTR CN (
        .ldcnt (ldcnt),
        .clk   (clk),
        .decr  (decr),
        .count (count)
    );

endmodule


module shiftreg (
    input        ld, clr, sft, clk, s_in,
    input  [15:0] din,
    output reg [15:0] dout
);
    initial dout = 16'd0;

    always @(posedge clk)
    begin
        if      (clr) dout <= 16'd0;
        else if (ld)  dout <= din;
        else if (sft) dout <= {s_in, dout[15:1]};
    end
endmodule


module PIPO (
    input        ld, clk,
    input  [15:0] din,
    output reg [15:0] dout
);
    initial dout = 16'd0;

    always @(posedge clk)
        if (ld) dout <= din;
endmodule


module dff (
    input  d, clk, clr,
    output reg q
);
    initial q = 1'b0;

    always @(posedge clk)
        if (clr) q <= 1'b0;
        else     q <= d;
endmodule


module addsum (
    input  [15:0] in1, in2,
    input         addsub,
    output reg [15:0] out
);
    always @(*)
    begin
        if (addsub == 1'b0)
            out = in1 + (~in2) + 16'd1;
        else
            out = in1 + in2;
    end
endmodule


module CNTR (
    input        ldcnt, decr, clk,
    output reg [4:0] count
);
    initial count = 5'd0;

    always @(posedge clk)
    begin
        if      (ldcnt) count <= 5'd15;
        else if (decr)  count <= count - 5'd1;
    end
endmodule


module controller (
    input        clk, Q0, qm1, eqz, start,
    output reg   LdA, LdQ, LdM,
    output reg   clrA, clrQ, clrff,
    output reg   sftA, sftQ,
    output reg   addsub, ldcnt, decr, done
);

    reg [2:0] state;
    initial   state = 3'd0;

    parameter s0 = 3'd0,
              s1 = 3'd1,
              s2 = 3'd2,
              s3 = 3'd3,
              s4 = 3'd4,
              s5 = 3'd5,
              s6 = 3'd6;

    always @(posedge clk)
    begin
        case (state)
            s0: state <= start ? s1 : s0;
            s1: state <= s2;
            s2: begin
                if      ({Q0,qm1} == 2'b01) state <= s3;
                else if ({Q0,qm1} == 2'b10) state <= s4;
                else                         state <= s5;
            end
            s3: state <= s5;
            s4: state <= s5;
            s5: begin
                if      (({Q0,qm1} == 2'b01) && !eqz) state <= s3;
                else if (({Q0,qm1} == 2'b10) && !eqz) state <= s4;
                else if (eqz)                          state <= s6;
            end
            s6: state <= s6;
            default: state <= s0;
        endcase
    end

    always @(*)
    begin
        LdA    = 1'b0;
        LdQ    = 1'b0;
        LdM    = 1'b0;
        clrA   = 1'b0;
        clrQ   = 1'b0;
        clrff  = 1'b0;
        sftA   = 1'b0;
        sftQ   = 1'b0;
        addsub = 1'b0;
        ldcnt  = 1'b0;
        decr   = 1'b0;
        done   = 1'b0;

        case (state)
            s1: begin
                clrA  = 1'b1;
                clrff = 1'b1;
                ldcnt = 1'b1;
                LdQ   = 1'b1;
            end
            s2: begin
                LdM = 1'b1;
            end
            s3: begin
                LdA    = 1'b1;
                addsub = 1'b1;
            end
            s4: begin
                LdA    = 1'b1;
                addsub = 1'b0;
            end
            s5: begin
                sftA = 1'b1;
                sftQ = 1'b1;
                decr = 1'b1;
            end
            s6: begin
                done = 1'b1;
            end
        endcase
    end

endmodule


module BoothMultiplier_tb;

    reg        clk;
    reg        start;
    reg [15:0] data_in;

    wire       q0, qm1, eqz;
    wire       LdA, LdQ, LdM;
    wire       clrA, clrQ, clrff;
    wire       sftA, sftQ;
    wire       addsub, ldcnt, decr;
    wire       done;

    boothmultiplier BM (
        .LdA     (LdA),
        .LdQ     (LdQ),
        .LdM     (LdM),
        .clrA    (clrA),
        .clrQ    (clrQ),
        .clrff   (clrff),
        .sftA    (sftA),
        .sftQ    (sftQ),
        .addsub  (addsub),
        .ldcnt   (ldcnt),
        .decr    (decr),
        .clk     (clk),
        .data_in (data_in),
        .q0      (q0),
        .qm1     (qm1),
        .eqz     (eqz)
    );

    controller CL (
        .clk    (clk),
        .Q0     (q0),
        .qm1    (qm1),
        .eqz    (eqz),
        .start  (start),
        .LdA    (LdA),
        .LdQ    (LdQ),
        .LdM    (LdM),
        .clrA   (clrA),
        .clrQ   (clrQ),
        .clrff  (clrff),
        .sftA   (sftA),
        .sftQ   (sftQ),
        .addsub (addsub),
        .ldcnt  (ldcnt),
        .decr   (decr),
        .done   (done)
    );

    initial clk = 1'b0;
    always  #5  clk = ~clk;

    initial
    begin
        start   = 1'b0;
        data_in = 16'd0;

        @(negedge clk);
        data_in = 16'd3;
        @(negedge clk);
        data_in = 16'd7;
        @(negedge clk);
        start   = 1'b1;
        @(negedge clk);
        start   = 1'b0;

        @(posedge done);
        $display("Test 1 done at time %0t | count=%0d", $time, BM.count);

        repeat(2) @(negedge clk);

        data_in = 16'd5;
        @(negedge clk);
        data_in = 16'd4;
        @(negedge clk);
        start   = 1'b1;
        @(negedge clk);
        start   = 1'b0;

        @(posedge done);
        $display("Test 2 done at time %0t | count=%0d", $time, BM.count);

        repeat(3) @(negedge clk);
        $finish;
    end

    initial
    begin
        $monitor("t=%0t count=%0d done=%b Q0=%b qm1=%b eqz=%b",
                 $time, BM.count, done, q0, qm1, eqz);
    end

    initial
    begin
        $dumpfile("test_booth.vcd");
        $dumpvars(0, BoothMultiplier_tb);
    end

endmodule
