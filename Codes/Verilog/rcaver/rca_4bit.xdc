## =============================================================================
## Constraints File : rca_4bit.xdc
## Project          : 4-bit Sequential Ripple Carry Adder (rcaver)
## Target           : AMD Vivado (Synthesis & Implementation)
## =============================================================================

## ----------------------------------------------------------------------------
## Clock constraint – clkRCA
## Period = 20 ns (50 MHz)
## The -waveform option makes the rising/falling edges explicit so Vivado
## can always resolve the port even on the first synthesis pass.
## ----------------------------------------------------------------------------

## ----------------------------------------------------------------------------
## Prevent opt_design from sweeping away the registered logic.
## Without output I/O pin constraints (LOC) Vivado treats all flip-flop
## outputs as "unobservable" and prunes them – causing "Design is empty".
## DONT_TOUCH on every cell keeps all registers and combinational cells alive
## so Vivado can report meaningful timing numbers for RCA vs CSA comparison.
## ----------------------------------------------------------------------------
set_property DONT_TOUCH true [get_cells -hierarchical *]

## ----------------------------------------------------------------------------
## Optional: board-level input/output delays – uncomment and adjust for
## your specific FPGA board once you have I/O pin assignments.
## ----------------------------------------------------------------------------
## set_input_delay  -clock clkRCA -max 2.0 [get_ports {A[*] B[*] Cin}]
## set_input_delay  -clock clkRCA -min 0.5 [get_ports {A[*] B[*] Cin}]
## set_output_delay -clock clkRCA -max 2.0 [get_ports {Sum[*] Cout}]
## set_output_delay -clock clkRCA -min 0.5 [get_ports {Sum[*] Cout}]

create_clock -period 10.000 -name clk2 -waveform {0.000 5.000} clkRCA
