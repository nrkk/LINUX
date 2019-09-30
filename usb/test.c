#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>

//probe function
//called on device insertion if and only if no other driver has beat us to the punch
static int pen_probe(struct usb_interface *interface,const struct usb_device_id * id)
{
printk(KERN_INFO "[*] Pen drive (%04X:%04X) plugged\n",id->idVendor,id->idProduct);
return 0;//return 0 indicates we will mange this device
}



//disconnect
static void pen_disconnect(struct usb_interface *interface)
{
printk(KERN_INFO "[*]Sandisk Pen drivels  removed\n");
}


//usb_device_id
static struct usb_device_id pen_table[]=
{
//
{
USB_DEVICE(0x03f0,0x5a07)//information is obtained using "lsusb" at the command line
},
{}/*Terminating entry*/
};
MODULE_DEVICE_TABLE(usb,pen_table);



//usb driver
static struct usb_driver pen_driver=
{
.name="SanDisk USB Driver",
.id_table=pen_table,
.probe=pen_probe,
.disconnect=pen_disconnect,
};



static int __init pen_init(void)
{
int ret=-1;
printk(KERN_INFO "[*]Constructor of driver");
printk(KERN_INFO "\t Registering Driver with Kernel");
ret=usb_register(&pen_driver);
printk(KERN_INFO "\tRegistration is complete");
return ret;
}


static void __exit pen_exit(void)
{
//deregister
printk(KERN_INFO "[*]Destructor of driver");
usb_deregister(&pen_driver);
printk(KERN_INFO "\tDeregistration complete");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("USB Pen Registration Driver");
MODULE_VERSION("0.1");
