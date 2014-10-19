#include <stdio.h>
#include "DVFS.h"
extern int DVFSTargetPower;
extern float total_cycle_power_average;
extern float total_cycle_power_total;
float FSF = 1.0;
float VSF = 1.0;
//cs203A entire File
void DVFS_controller_on()
{
int temp = (int)total_cycle_power_average;
if(temp < DVFSTargetPower)
   {	
	fprintf(stderr,"Total Power DVFS :%f\n",total_cycle_power_total);
	fprintf(stderr,"Average Power DVFS :%f\n",total_cycle_power_average);
	fprintf(stderr,"Target Power DVFS :%f\n",(float)DVFSTargetPower);	
	
	if(FSF <= 2.0 && VSF <=2.0 && VSF >= 0.2 && FSF >=0.2)
	{	
		FSF += 0.2;
		VSF += 0.2;
	}
	fprintf(stderr,"FSF%f\n",FSF);
	fprintf(stderr,"VSF%f\n",VSF);
   }
if(temp > DVFSTargetPower)
   {	
	fprintf(stderr,"Total Power DVFS :%f\n",total_cycle_power_total);
	fprintf(stderr,"Average Power DVFS :%f\n",total_cycle_power_average);
	fprintf(stderr,"Target Power DVFS :%f\n",(float)DVFSTargetPower);			
	
	if(FSF <= 2.0 && VSF <=2.0 && VSF >= 0.2 && FSF >=0.2)
	{	
		FSF -= 0.2;
		VSF -= 0.2;
	}	
	fprintf(stderr,"FSF%f\n",FSF);
	fprintf(stderr,"VSF%f\n",VSF);
   }

}  

void DVFS_controller_off()
{
	fprintf(stderr,"Total Power DVFS :%f\n",total_cycle_power_total);
	fprintf(stderr,"Average Power DVFS :%f\n",total_cycle_power_average);
	fprintf(stderr,"Target Power DVFS :%f\n",(float)DVFSTargetPower);	
	fprintf(stderr,"FSF%f\n",FSF);
	fprintf(stderr,"VSF%f\n",VSF);
   
}  

