module pipe5(zout,rs1,rs2,rd,func,addr,clk1,clk2);
input [3:0] rs1,rs2,rd;
input clk1,clk2;
input [3:0] func;
input [7:0] addr;
output [15:0] zout;

reg [15:0] regbank [15:0];
reg [15:0] membank [255:0];

reg [15:0] l1a,l1b;
reg [3:0]  l1rd,l1func;
reg [7:0]  l1add;

reg [15:0] l2a,l2b;
reg [3:0]  l2rd,l2func;
reg [7:0]  l2add;

reg [15:0] l3z;
reg [3:0]  l3rd;
reg [7:0]  l3add;

reg [15:0] l4z;
reg [3:0]  l4rd;
reg [7:0]  l4add;

reg [15:0] l5z;

assign zout = l5z;

always @(posedge clk1)
begin
    l1a   <= #2 regbank[rs1];
    l1b   <= #2 regbank[rs2];
    l1rd  <= #2 rd;
    l1func<= #2 func;
    l1add <= #2 addr;
end

always @(posedge clk2)
begin
    l2a   <= #2 l1a;
    l2b   <= #2 l1b;
    l2rd  <= #2 l1rd;
    l2func<= #2 l1func;
    l2add <= #2 l1add;
end

always @(posedge clk1)
begin
    case(l2func)
        0: l3z <= #2 l2a + l2b;
        1: l3z <= #2 l2a - l2b;
        2: l3z <= #2 l2a * l2b;
        3: l3z <= #2 l2a;
        4: l3z <= #2 l2b;
        5: l3z <= #2 l2a & l2b;
        6: l3z <= #2 l2a | l2b;
        7: l3z <= #2 l2a ^ l2b;
        8: l3z <= #2 ~l2a;
        9: l3z <= #2 ~l2b;
        10: l3z <= #2 l2a >> 1;
        11: l3z <= #2 l2b << 1;
        default: l3z <= 16'hxxxx;
    endcase
    l3rd  <= #2 l2rd;
    l3add <= #2 l2add;
end

always @(posedge clk2)
begin
    l4z   <= #2 l3z;
    l4rd  <= #2 l3rd;
    l4add <= #2 l3add;
    membank[l3add] <= #2 l3z;
end

always @(posedge clk1)
begin
    l5z <= #2 l4z;
    regbank[l4rd] <= #2 l4z;
end

endmodule

module simuli5();
reg [3:0] rs1,rs2,rd,func;
reg [7:0] addr;
wire [15:0] zout;
integer k;
reg clk1, clk2;

pipe5 uut(zout,rs1,rs2,rd,func,addr,clk1,clk2);

initial clk1=1;
initial clk2=0;
always #10 clk1=~clk1;
always #10 clk2=~clk2;

initial
begin
    for(k=0;k<16;k=k+1)
        uut.regbank[k]=k;
end

initial
begin
    $dumpfile("pipe5.vcd");
    $dumpvars(0, simuli5);

    $monitor("T=%0t | rs1=%d rs2=%d rd=%d func=%d addr=%d zout=%d",
             $time, rs1, rs2, rd, func, addr, zout);

    #20 rs1=6; rs2=1; rd=10; addr=125; func=2;
    #20 rs1=9; rs2=8; rd=12; addr=126; func=3;
    #20 rs1=2; rs2=4; rd=13; addr=125; func=4;
    #120 $finish;
end
endmodule