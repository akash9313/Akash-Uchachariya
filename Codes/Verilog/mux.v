module mux2to1 (input A, input B, input S, output Y);

    wire nS, A1, B1;

    not  (nS, S);     
    and  (A1, A, nS); 
    and  (B1, B, S);  
    or   (Y, A1, B1); 

endmodule

module tb_mux2to1;
    reg A, B, S;   
    wire Y;        

    mux2to1 uut (.A(A),.B(B),.S(S),.Y(Y));

    initial begin
         $dumpfile("mux2to1.vcd");
        $dumpvars(0, tb_mux2to1);

        $monitor("A=%b B=%b S=%b -> Y=%b", A, B, S, Y);

        A=0; B=0; S=0; #10;  
        A=1; B=0; S=0; #10;  
        A=0; B=1; S=0; #10;  
        A=1; B=1; S=0; #10;  
        A=0; B=0; S=1; #10;  
        A=1; B=0; S=1; #10;  
        A=0; B=1; S=1; #10;  
        A=1; B=1; S=1; #10;  

        $finish;  
    end
endmodule