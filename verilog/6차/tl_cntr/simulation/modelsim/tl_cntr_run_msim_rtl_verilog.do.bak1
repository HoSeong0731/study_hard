transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/gates.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/tl_cntr.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/ns_logic.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/_register2_r.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/_dff_rs_async.v}
vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/o_logic.v}

vlog -vlog01compat -work work +incdir+C:/Users/jjaa7/Desktop/tl_cntr {C:/Users/jjaa7/Desktop/tl_cntr/tb_tl_cntr.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  tb_tl_cntr

add wave *
view structure
view signals
run -all
