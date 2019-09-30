#include<linux/init.h>
#include<linux/module.h>

#include<linux/moduleparam.h>
//create variable
int param_var[3]={1,2,3};

//register var
//name,type,permissions
module_param_array(param_var,int,NULL,S_IRUSR|S_IWUSR);

void display(void)	
{
printk(KERN_ALERT "parameter value=%d",param_var[0]);
printk(KERN_ALERT "parameter value=%d",param_var[1]);
printk(KERN_ALERT "parameter value=%d",param_var[2]);
}

static int parameter_init(void) 
{ 
//printk(KERN_INFO "Loading hello module...\n"); 
printk(KERN_INFO "Hello world..\n"); 
display();
return 0; 
} 

static void parameter_exit(void) 
{ 
printk(KERN_INFO "Goodbye\n"); 
} 

module_init(parameter_init); 
module_exit(parameter_exit);
