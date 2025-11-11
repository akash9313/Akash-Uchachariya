module jk(
    input j,
    input k,
    input clk,
    input qn1,
    input qnn1,
    output q,
    output qn
);
    wire w1, w2;

    assign w1 = ~(j & clk);
    assign q  = ~(w1 & qnn1);

    assign w2 = ~(k & clk);
    assign qn = ~(w2 & qn1);

endmodule

module jk_tb;

    reg j, k, clk, qn1, qnn1;
    wire q, qn;            

    jk uut (
        .j(j),
        .k(k),
        .clk(clk),
        .qn1(qn1),
        .qnn1(qnn1),
        .q(q),
        .qn(qn)
    );

    initial begin
        $dumpfile("jkflip.vcd");
        $dumpvars(0, jk_tb);
    end

    initial begin
        
        $display("j k clk | q qn");
        $display("----------------");

        qn1 = 0; qnn1 = 1; clk = 0; j = 0; k = 0; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 1; j = 0; k = 0; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 0; j = 0; k = 1; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 1; j = 0; k = 1; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 0; j = 1; k = 0; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 1; j = 1; k = 0; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 0; j = 1; k = 1; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        qn1 = q; qnn1 = qn; clk = 1; j = 1; k = 1; #10;
        $display("%b %b  %b  | %b %b", j, k, clk, q, qn);

        $finish;
    end

endmodule
