#include <stdio.h>

/* Function Prototypes or ddeclarations */
void explain_program(void);
void get_values(float *r, float *v);
float do_calculations(float resistance, float voltage);
void display_answer(float current); 

float calc_power_by_data(float i,float r);
void calc_power_by_addr(float *i,float *r, float *p);
void calc_power_by_mixed(float i,float r, float *p);

main()
{
	float resistor;
	float volts;
	float current;
    float power;  
      
	explain_program();
	get_values(&resistor, &volts);
	current = do_calculations(resistor,volts);
	display_answer(current); 
	
	power=calc_power_by_data(current,resistor);
	printf("\n Power by data = %f",power);
	
	calc_power_by_addr(&current,&resistor,&power);
	printf("\n Power by addr = %f",power);

	calc_power_by_mixed(current, resistor ,&power);
	printf("\n Power by mixed = %f",power);
}
/*----------------------Function Definitions ----------------------------*/
void explain_program()
{                            
	printf("Current and Power calculator Vr1.0 Nov 19 2003 PK\n");
	printf("This program calculates the value of the current\n");
	printf("in amps. You need to enter the value of the resistor\n");
	printf("and the voltage in volts.\n");
	printf("Illustrates pass by data and address.\n");	
}  /* end of explain_program() */
/*------------------------------------------------------------------------*/
void get_values(float *r, float *v)
{
	float resistance;
	float voltage;
	printf("\n\nInput the resistance in ohms = ");
	scanf("%f",&resistance);
	printf("Input the voltage in volts = ");
	scanf("%f",&voltage);

	*r = resistance;
	*v = voltage;
}   /* end of get_values() */

/*------------------------------------------------------------------------*/

float do_calculations(float resistance, float voltage)
{
	float current;

	current = voltage / resistance;
	return(current);
}   /* end of do_calculations() */

/*------------------------------------------------------------------------*/

void display_answer(float current)
{
	printf("The value of the current is %f amps.",current);
}


/*------------------------------------------------------------------------*/
float calc_power_by_data(float i,float r){ 
		
		return(i*i*r);

}


/*------------------------------------------------------------------------*/
void calc_power_by_addr(float *i,float *r, float *p){ 

			*p=(*i)*(*i)*(*r);

}

/*------------------------------------------------------------------------*/
void calc_power_by_mixed(float i,float r, float *p){
		*p=i*i*r;
}
/*------------------------------------------------------------------------*/