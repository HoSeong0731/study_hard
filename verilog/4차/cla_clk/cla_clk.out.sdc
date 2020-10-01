## Generated SDC file "cla_clk.out.sdc"

## Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
## Your use of Altera Corporation's design tools, logic functions 
## and other software and tools, and its AMPP partner logic 
## functions, and any output files from any of the foregoing 
## (including device programming or simulation files), and any 
## associated documentation or information are expressly subject 
## to the terms and conditions of the Altera Program License 
## Subscription Agreement, the Altera Quartus Prime License Agreement,
## the Altera MegaCore Function License Agreement, or other 
## applicable license agreement, including, without limitation, 
## that your use is for the sole purpose of programming logic 
## devices manufactured by Altera and sold by Altera or its 
## authorized distributors.  Please refer to the applicable 
## agreement for further details.


## VENDOR  "Altera"
## PROGRAM "Quartus Prime"
## VERSION "Version 15.1.0 Build 185 10/21/2015 SJ Lite Edition"

## DATE    "Mon Sep 28 22:07:21 2020"

##
## DEVICE  "5CSXFC6D6F31C6"
##


#**************************************************************
# Time Information
#**************************************************************

set_time_format -unit ns -decimal_places 3



#**************************************************************
# Create Clock
#**************************************************************

create_clock -name {clock} -period 7.000 -waveform { 0.000 3.500 } [get_ports {clock}]


#**************************************************************
# Create Generated Clock
#**************************************************************



#**************************************************************
# Set Clock Latency
#**************************************************************



#**************************************************************
# Set Clock Uncertainty
#**************************************************************

set_clock_uncertainty -rise_from [get_clocks {clock}] -rise_to [get_clocks {clock}] -setup 0.170  
set_clock_uncertainty -rise_from [get_clocks {clock}] -rise_to [get_clocks {clock}] -hold 0.060  
set_clock_uncertainty -rise_from [get_clocks {clock}] -fall_to [get_clocks {clock}] -setup 0.170  
set_clock_uncertainty -rise_from [get_clocks {clock}] -fall_to [get_clocks {clock}] -hold 0.060  
set_clock_uncertainty -fall_from [get_clocks {clock}] -rise_to [get_clocks {clock}] -setup 0.170  
set_clock_uncertainty -fall_from [get_clocks {clock}] -rise_to [get_clocks {clock}] -hold 0.060  
set_clock_uncertainty -fall_from [get_clocks {clock}] -fall_to [get_clocks {clock}] -setup 0.170  
set_clock_uncertainty -fall_from [get_clocks {clock}] -fall_to [get_clocks {clock}] -hold 0.060  


#**************************************************************
# Set Input Delay
#**************************************************************



#**************************************************************
# Set Output Delay
#**************************************************************



#**************************************************************
# Set Clock Groups
#**************************************************************



#**************************************************************
# Set False Path
#**************************************************************



#**************************************************************
# Set Multicycle Path
#**************************************************************



#**************************************************************
# Set Maximum Delay
#**************************************************************



#**************************************************************
# Set Minimum Delay
#**************************************************************



#**************************************************************
# Set Input Transition
#**************************************************************

