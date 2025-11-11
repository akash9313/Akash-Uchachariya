module jk_flipflop (
    input wire J,
    input wire K,
    input wire clk,
    input wire reset,
    output reg Q,
    output reg Qn
);

always @(posedge clk or posedge reset) begin
    if (reset) begin
        Q  <= 0;
        Qn <= 1;
    end else begin
        case ({J, K})
            2'b00: begin
                // hold (do nothing)
            end
            2'b01: begin
                Q  <= 0;
                Qn <= 1;
            end
            2'b10: begin
                Q  <= 1;
                Qn <= 0;
            end
            2'b11: begin
                Q  <= ~Q;
                Qn <= ~Qn;
            end
        endcase
    end
end

endmodule

module tb_jk_flipflop;
    reg J;
    reg K;
    reg clk;
    reg reset;
    wire Q;
    wire Qn;

    jk_flipflop uut (
        .J(J),
        .K(K),
        .clk(clk),
        .reset(reset),
        .Q(Q),
        .Qn(Qn)
    );

    initial begin
        clk = 0;
        reset = 1;
        J = 0;
        K = 0;
        #12 reset = 0;
    end

    always #5 clk = ~clk;

    initial begin
        $dumpfile("jk_flipflop.vcd");
        $dumpvars(0, tb_jk_flipflop);
    end

    initial begin
        $display("Time\tclk\tJ K\tQ Qn");
        $monitor("%0t\t%b\t%b %b\t%b %b", $time, clk, J, K, Q, Qn);

        @(posedge clk); 
        @(posedge clk); J = 1; K = 0;
        @(posedge clk); J = 0; K = 1;
        @(posedge clk); J = 1; K = 1;
        @(posedge clk); J = 0; K = 0;
        @(posedge clk); J = 1; K = 1;
        @(posedge clk); J = 1; K = 1;
        @(posedge clk); $finish;
    end

endmodule
