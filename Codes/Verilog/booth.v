module boothmultiplier(LdA,LdQ,LdM,clrA,clrq,clrff,sftA,sftQ,addsub,ldcnt,data_in,decr,clk,q0,qm1,eqz);// objective M*Q  Datapath
input LdA,LdQ,LdM,clrA,clrq,clrff,sftA,sftQ,addsub,ldcnt,decr,clk;
input [15:0] data_in;
output q0,qm1,eqz;
wire[15:0] A,Q,M,Z;
wire[4:0] count;
assign eqz=~|count;
//assign q0=Q[0];
shiftreg AR(LdA,clrA,Z,sftA,A,clk,A[15]);     //Submodule for accumulator
shiftreg QR(LdQ,clrQ,data_in,sftQ,Q,clk,A[0]);//Submodule for multiplier 
dff QM1(Q[0],qm1,clk,clrff);//Submodule for buffer
addsum AS(Z,A,M,addsub);//Submodule for adder
PIPO MR(LdM,data_in,M,clk);//Submodule for Multiplicand
CNTR CN(ldcnt,clk,decr,count);//Submodule for counter
endmodule
module shiftreg (ld,clr,din,sft,dout,clk,s_in);
input ld,clr,sft,clk,s_in;
output reg [15:0] dout;
input [15:0] din;
always@(posedge clk) //clock  Shift register A & Q
begin
if(clr)
dout<=0;
else if (ld)
dout<=din;
else if (sft)
dout<={s_in,dout[15:1]};
end
endmodule 
module PIPO(ld,din,dout,clk); 
input[15:0] din;
input ld,clk;
output reg [15:0] dout;
always@(posedge clk)   //clock for register M
if (ld)
dout<=din;
endmodule
module dff(d,q,clk,clr);
input clr,clk,d;
output reg q;
always@(posedge clk) // clock for buffer register
if (clr)
 #1 q<=0;
else
#1 q<=d;
endmodule
module addsum(out,in1,in2,addsub);
input[15:0] in1,in2;
input addsub;
output reg[15:0] out;
always@(*)
begin
if (addsub==0)
out=in1+((!in2)+4'b0001);
else
out=in1+in2;
end
endmodule
module CNTR (ldcnt,clk,decr,count);
input ldcnt,decr,clk;
output reg[4:0] count;
always@(posedge clk) // clock for counter 
begin
if (ldcnt)
count=4'b1111;
else if(decr)
count<=count-1;
end
endmodule
module controller(LdA,LdQ,LdM,clrA,clrQ,clrff,sftA,sftQ,addsub,ldcnt,decr,done,clk,Q0,qm1,eqz,start);// control path code
input clk,Q0,qm1,eqz,start;
output reg LdA,LdQ,LdM,clrA,clrQ,clrff,sftA,sftQ,addsub,ldcnt,decr,done;
reg[2:0] state;
parameter s0=3'b000,s1=3'b001,s2=3'b010,s3=3'b011,s4=3'b100,s5=3'b101,s6=3'b110;
always @(posedge clk)
begin
case(state)
s0: if(start) state<=s1;
s1: #2 state<=s2;
s2:  if({Q0,qm1}==2'b01) state<=s3;
       else if({Q0,qm1}==2'b10) state<=s4;
       else state<=s5;
 s3: state<=s5;
 s4:  state<=s5;
 s5: #2 if (({Q0,qm1}==2'b01) && !eqz) state<=s3;
         else if (({Q0,qm1}==2'b10) && !eqz) state<=s4;
         else if(eqz) state<=s6;
  s6: state<=s6;
  default: state <=s0;
  endcase 
  end
  always@(state)
  begin
  case(state)
  s0: begin LdA=0;clrA=0;sftA=0;LdQ=0;clrQ=0;clrff=0;LdQ=0;sftQ=0;LdM=0;done=0;end
  s1: begin clrA=1;clrff=1;ldcnt=1;LdQ=1;end
  s2: begin clrA=0;clrff=0;ldcnt=0;LdM=1;LdQ=0;end
  s3: begin LdA=1;addsub=1;LdQ=0;sftA=0;sftQ=0;decr=0;end
  s4: begin LdA=1;LdQ=0;sftA=0;sftQ=0;decr=0;addsub=0;end
  s5: begin LdA=0;sftA=1;LdQ=0;sftQ=1;decr=1;end
  s6: done=1;
  default: begin LdA=0;clrA=0;LdQ=0;clrQ=0;clrff=0;LdM=0;end  
  
  endcase
end
endmodule

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
$dumpfile("booth.vcd");
$dumpvars(0,BoothMultiplier_tb);
#188 $finish;
end
endmodule


