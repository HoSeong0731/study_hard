transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/gates.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/tl_cntr_w_left.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/ns_logic.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/o_logic.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/_register3_r.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/_dff_r_async.v}

vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr_w_left {C:/Users/jjaa7/Desktop/tl_cntr_w_left/tb_tl_cntr_w_left.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  tb_tl_cntr_w_left

add wave *
view structure
view signals
run -all
