module D_flipflop (
    input D,          
    input clk,        
    output reg Q      
);

always @(posedge clk) begin
    Q <= D;       
end

endmodule


module testbench;
    reg D, clk;
    wire Q;

    D_flipflop uut (
        .D(D),
        .clk(clk),
        .Q(Q)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("dflipflop.vcd");
        $dumpvars(0, testbench);
    end

    initial begin
        clk = 0;
        D = 0;

        $display("Time\tclk\tD\tQ");
        $monitor("%0t\t%b\t%b\t%b", $time, clk, D, Q);

        #10 D = 1;      
        #10 D = 0;      
        #10 D = 1;      
        #10 D = 0;      
        #20 $finish;    
    end

endmodule