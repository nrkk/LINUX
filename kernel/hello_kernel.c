#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ranjith");
MODULE_DESCRIPTION("kernel hello");
MODULE_VERSION("2.0");

static int __init hello_start(void)
{
printk(KERN_INFO "Loading...\n");
printk(KERN_INFO "Hello Kernel\n");
return 0;
}

static void __exit hello_end(void) 
{ 
    printk(KERN_INFO "Goodbye kernel\n"); 
} 
  
module_init(hello_start); 
module_exit(hello_end); 

