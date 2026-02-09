module boothmultiplier(
  LdA,LdQ,LdM,clrA,clrQ,clrff,
  sftA,sftQ,addsub,ldcnt,
  data_in,decr,clk,q0,qm1,eqz
);

input LdA,LdQ,LdM,clrA,clrQ,clrff,sftA,sftQ,addsub,ldcnt,decr,clk;
input [15:0] data_in;
output q0,qm1,eqz;

wire [15:0] A,Q,M,Z;
reg  [4:0] count;

assign q0  = Q[0];
assign eqz = (count == 0);

shiftreg AR (LdA, clrA, Z, sftA, A, clk, A[15]);
shiftreg QR (LdQ, clrQ, data_in, sftQ, Q, clk, A[0]);
dff QM1 (Q[0], qm1, clk, clrff);
addsum AS (Z, A, M, addsub);
PIPO MR (LdM, data_in, M, clk);

always @(posedge clk) begin
  if (ldcnt)
    count <= 5'd16;
  else if (decr)
    count <= count - 1;
end

endmodule


module shiftreg(ld, clr, din, sft, dout, clk, s_in);
input ld, clr, sft, clk, s_in;
input [15:0] din;
output reg [15:0] dout;

always @(posedge clk) begin
  if (clr)
    dout <= 16'd0;
  else if (ld)
    dout <= din;
  else if (sft)
    dout <= {s_in, dout[15:1]};
end
endmodule


module PIPO(ld, din, dout, clk);
input ld, clk;
input [15:0] din;
output reg [15:0] dout;

always @(posedge clk)
  if (ld)
    dout <= din;
endmodule


module dff(d, q, clk, clr);
input d, clk, clr;
output reg q;

always @(posedge clk) begin
  if (clr)
    q <= 1'b0;
  else
    q <= d;
end
endmodule


module addsum(out, in1, in2, addsub);
input [15:0] in1, in2;
input addsub;
output reg [15:0] out;

always @(*) begin
  if (addsub)
    out = in1 + in2;
  else
    out = in1 + (~in2 + 1);
end
endmodule


module controller(
  LdA,LdQ,LdM,clrA,clrQ,clrff,
  sftA,sftQ,addsub,ldcnt,decr,
  done,clk,Q0,qm1,eqz,start
);

input clk,Q0,qm1,eqz,start;
output reg LdA,LdQ,LdM,clrA,clrQ,clrff;
output reg sftA,sftQ,addsub,ldcnt,decr,done;

reg [2:0] state;

parameter s0=3'b000, s1=3'b001, s2=3'b010,
          s3=3'b011, s4=3'b100, s5=3'b101, s6=3'b110;

always @(posedge clk) begin
  case(state)
    s0: if(start) state <= s1;
    s1: state <= s2;
    s2: if({Q0,qm1}==2'b01) state <= s3;
        else if({Q0,qm1}==2'b10) state <= s4;
        else state <= s5;
    s3: state <= s5;
    s4: state <= s5;
    s5: if(eqz) state <= s6;
        else state <= s2;
    s6: state <= s6;
    default: state <= s0;
  endcase
end

always @(*) begin
  LdA=0; LdQ=0; LdM=0; clrA=0; clrQ=0; clrff=0;
  sftA=0; sftQ=0; addsub=0; ldcnt=0; decr=0; done=0;

  case(state)
    s1: begin clrA=1; clrff=1; ldcnt=1; LdQ=1; end
    s2: begin LdM=1; end
    s3: begin LdA=1; addsub=1; end
    s4: begin LdA=1; addsub=0; end
    s5: begin sftA=1; sftQ=1; decr=1; end
    s6: begin done=1; end
  endcase
end

endmodule


module BoothMultiplier_tb;

reg [15:0] data_in;
reg clk, start;
wire done;

wire LdA,LdQ,LdM,clrA,clrQ,clrff;
wire sftA,sftQ,addsub,ldcnt,decr;
wire q0,qm1,eqz;

boothmultiplier BM (
  LdA,LdQ,LdM,clrA,clrQ,clrff,
  sftA,sftQ,addsub,ldcnt,
  data_in,decr,clk,q0,qm1,eqz
);

controller CL (
  LdA,LdQ,LdM,clrA,clrQ,clrff,
  sftA,sftQ,addsub,ldcnt,decr,
  done,clk,q0,qm1,eqz,start
);

always #5 clk = ~clk;

initial begin
  clk = 0;
  start = 0;
  data_in = 0;

  #2  data_in = 16'd3;
  #4  data_in = 16'd7;
  #6  start = 1;
  #10 start = 0;

  #300 $finish;
end

initial begin
  $dumpfile("booth2.vcd");
  $dumpvars(0, BoothMultiplier_tb);
end

endmodule
