For Anagram-
../sim-outorder anagram.alpha words 1 1000 15.87 < anagram.in >../../OUT.std 2>../../OUT.stat
Command line parameters-
DVFS On/OFF is 1/0
DVFS Interval is 1000
DVFS Target Power is 15.87

Steps-
1) First give the command line parameters as stated above.
2) Command line parameters goes to main.c line 237 where we first check whether we are running Anagram or Go,Then we take the
command line inputs and store them in the variable DVFSInterval,DVFSTargetPower and DVFS flag.
3)Then it goes to sim-outorder.c to line 4882 to check whether we need to run with DVFS on/off and then trigger the 
DVFS controller every N cycles.
4)In the DVFS controller we check if Average_Power is less than DVFS_Target_Power then we increase the VSF and FSF values
by 0.2 each and if it is greater we deacrease the VSF and FSF values by 0.2 each which dynamically updates the VSF and FSF values.
5)Inside Power.c we check the update power stats function and calculate the Average_Power(cc1+cc2+cc3/DVFSInterval) 
and Total_Power(cc1+cc2+cc3).

Explanation-
In sim-outorder.c
Line 4882:we check if((sim_cycle % DVFSInterval == 0) && (DVFS_flag == 1))
i.e if the sim_cycle is equal to the DVFSInterval cycles then we call the DVFS controller
We also check for the DVFS flag if is 0/1.If it is 1 we consider DVFS as on and trigger the controller.

In power.c
Line 610 inside update_power_stats we update the power factor to Powerfactor1 = FSF*pow(VSF,2); with the dynamic values of VSF and FSF
from the controller.
Line 616 and 618 we calculate the Average_Power(cc1+cc2+cc3/DVFSInterval) 
and Total_Power(cc1+cc2+cc3).

In DVFS.c
Line 12 we update the VSF and FSF in lock steps by comparing the Average_Power and Target_Power.

In main.c
Line 237 and 243 we take the command line values for Go and Anagram.

For Go-
../sim-outorder go.alpha 2 8 2stone9.in 1 1000000 58 >../../ OUT.std 2>../../ OUT.stat
Command line parameters-
DVFS On/OFF is 1/0
DVFS Interval is 1000000
DVFS Target Power is 58.21

Steps-
1) First give the command line parameters as stated above.
2) Command line parameters goes to main.c line 237 where we first check whether we are running Anagram or Go,Then we take the
command line inputs and store them in the variable DVFSInterval,DVFSTargetPower and DVFS flag.
3)Then it goes to sim-outorder.c to line 4882 to check whether we need to run with DVFS on/off and then trigger the 
DVFS controller every N cycles.
4)In the DVFS controller we check if Average_Power is less than DVFS_Target_Power then we increase the VSF and FSF values
by 0.2 each and if it is greater we deacrease the VSF and FSF values by 0.2 each which dynamically updates the VSF and FSF values.
5)Inside Power.c we check the update power stats function and calculate the Average_Power(cc1+cc2+cc3/DVFSInterval) 
and Total_Power(cc1+cc2+cc3).


