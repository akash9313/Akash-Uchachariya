module pipe(zout,rs1,rs2,rd,func,addr,clk1,clk2);
input [3:0] rs1,rs2,rd;
input clk1,clk2;
input [3:0] func;
input [7:0] addr;
output [15:0] zout;

reg [15:0] l1a,l1b,l2z,l3z,l4z;
reg [7:0] l1add,l2add,l3add,l4add;
reg [3:0] l1func,l1rd,l2rd,l3rd;
reg [15:0] regbank [15:0];
reg [15:0] membank [255:0];

assign zout = l3z;

always @(posedge clk1)
begin
    l1a <= #2 regbank[rs1];
    l1b <= #2 regbank[rs2];
    l1func <= #2 func;
    l1rd <= #2 rd;
    l1add <= #2 addr;
end

always @(posedge clk2)
begin
    case(l1func)
        0: l2z <= #2 l1a + l1b;
        1: l2z <= #2 l1a - l1b;
        2: l2z <= #2 l1a * l1b;
        3: l2z <= #2 l1a;
        4: l2z <= #2 l1b;
        5: l2z <= #2 l1a & l1b;
        6: l2z <= #2 l1a | l1b;
        7: l2z <= #2 l1a ^ l1b;
        8: l2z <= #2 ~l1a;
        9: l2z <= #2 ~l1b;
        10: l2z <= #2 l1a >> 1;
        11: l2z <= #2 l1b << 1;
        default: l2z <= 16'hxxxx;
    endcase
    l2rd <= #2 l1rd;
    l2add <= #2 l1add;
end

always @(posedge clk1)
begin
    regbank[l2rd] <= #2 l2z;
    l3z <= #2 l2z;
    l3add <= #2 l2add;
end

always @(posedge clk2)
begin
    l4z <= #2 l3z;
    l4add <= #2 l3add;
    membank[l4add] <= #2 l4z;
end
endmodule


module simuli();
reg [3:0] rs1,rs2,rd,func;
reg [7:0] addr;
wire [15:0] zout;
integer k;
reg clk1, clk2;

pipe uut(zout,rs1,rs2,rd,func,addr,clk1,clk2);

initial clk1 = 1;
initial clk2 = 0;

always #10 clk1 = ~clk1;
always #10 clk2 = ~clk2;
 n
initial
begin
    for(k=0;k<16;k=k+1)
        uut.regbank[k] = k;
end

initial
begin
    $dumpfile("advancepipeline.vcd");
    $dumpvars(0, simuli);

    #20 rs1=6; rs2=1; rd=10; addr=125; func=2;
    #20 rs1=9; rs2=8; rd=12; addr=126; func=3;
    #20 rs1=2; rs2=4; rd=13; addr=125; func=4;

    $monitor("Time=%0t | rs1=%d rs2=%d rd=%d func=%d addr=%d | zout=%d",
              $time, rs1, rs2, rd, func, addr, zout);
    #60 $finish;
end
endmodule