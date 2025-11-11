module D_flipflop (
    input D,          
    input clk,        
    input reset,      
    output reg Q      
);

always @(posedge clk or posedge reset) begin
    if (reset)
        Q <= 1'b0;    
    else
        Q <= D;       
end

endmodule


module testbench;
    reg D, clk, reset;
    wire Q;

    D_flipflop uut (
        .D(D),
        .clk(clk),
        .reset(reset),
        .Q(Q)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("dflipflop2.vcd");
        $dumpvars(0, testbench);
    end

    initial begin
        clk = 0;
        reset = 1;
        D = 0;

        $display("Time\tclk\tr\tD\tQ");
        $monitor("%0t\t%b\t%b\t%b\t%b", $time, clk, reset, D, Q);

        #10 reset = 0;  
        #10 D = 1;      
        #10 D = 0;      
        #10 D = 1;      
        #20 reset = 1;  
        #10 reset = 0;  
        #20 $finish;    
    end

endmodule