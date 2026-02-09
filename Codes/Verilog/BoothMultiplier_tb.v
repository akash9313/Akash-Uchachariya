`include "boothmultiplier.v"
module BoothMultiplier_tb();
reg [15:0] data_in;
reg clk,start;
wire done;
boothmultiplier BM (LdA,LdQ,LdM,clrA,clrq,clrff,sftA,sftQ,addsub,ldcnt,data_in,decr,clk,q0,qm1,eqz);
controller CL(LdA,LdQ,LdM,clrA,clrq,clrff,sftA,sftQ,addsub,ldcnt,decr,done,clk,q0,qm1,eqz,start);
initial 
begin
clk=0;
#7 start=1;
end
always #5 clk=~clk;
initial
begin
# 10 data_in=3; 
# 20 data_in=7; 
end
initial 
begin
$monitor($time, "%d %d",BM.count,done);
$dumpfile("test_booth.vcd");
$dumpvars(0,BoothMultiplier_tb);
#188 $finish;
end
endmodule

