#include "sensor-validate.h"
/* =================================================================================
* Function Name : IsSuddenJumpObserved
* Description   : To check sudden jump
* Arguments     : 1. value - list of value
*		              2. numOfValues - Number of values
*	                3. maxDelta - Maximum acceptable changes
* Returns       : true or false
* ================================================================================== */
bool IsSuddenJumpObserved(double* value, double nextValue, double maxDelta) {
  int lastButOneIndex = numOfValues - 1;
	for(int i = 0; i < lastButOneIndex; i++) 
	{
		if((values[i + 1] - values[i]) > maxDelta) 
		{
			return false;
		}
	}
	
	return true;
}

/* ==================================================================================
* Function Name : validateSOCreadings
* Description   : validate the SOC input values
* Arguments     : 1. values - list of SOC values
*		              2. numOfValues - Number of SOC values
*  Returns       : true or false
* ================================================================================== */
bool validateSOCreadings(double* values, int numOfValues) {
  
 if(values != NULL)
	{
		if(!IsSuddenJumpObserved(values, numOfValues, 0.05)) 
		{
			return false;
		}
	}
	return true;
}

/* ==================================================================================
* Function Name : validateCurrentreadings
* Description   : validate the Current readings and check  null pointer
* Arguments	    : 1. values - list of Current values
*		              2. numOfValues - Number of Current values
* Returns       : true or false
* ================================================================================== */
bool validateCurrentreadings(double* values, int numOfValues) {
  if(values != NULL)
	{
		if(!IsSuddenJumpObserved(values, numOfValues, 0.01)) 
		{
			return 0;
		}
	}
	return 1;
}
